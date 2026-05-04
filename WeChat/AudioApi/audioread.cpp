#include "audioread.h"

AudioRead::AudioRead(QObject *parent)
    : QObject{parent}
{
    //speex 初始化
    speex_bits_init(&bits_enc);
    Enc_State = speex_encoder_init(speex_lib_get_mode(SPEEX_MODEID_NB));
    //设置质量为 8(15kbps)
    int tmp = SPEEX_QUALITY;
    speex_encoder_ctl(Enc_State,SPEEX_SET_QUALITY,&tmp);

    //首先初始化设备
    // ---------------- Qt6 替换QAudioDeviceInfo ----------------
    // Qt5: QAudioDeviceInfo::defaultInputDevice() → Qt6: QMediaDevices::defaultAudioInput()
    QAudioDevice info = QMediaDevices::defaultAudioInput();
    // 空设备判断（新增，避免崩溃）
    if (info.isNull()) {
        QMessageBox::warning(NULL, "错误", "未检测到音频输入设备！");
        return;
    }
    qDebug() << "默认输入设备名称：" << info.description();
    format = info.preferredFormat();
    qDebug() << "设备推荐输入格式：";
    qDebug() << "采样率：" << format.sampleRate();
    qDebug() << "声道数：" << format.channelCount();
    qDebug() << "采样格式：" << format.sampleFormat();

    //声卡采样格式（Qt6适配版）
    format.setSampleRate(8000);  // 采样率（Qt5/Qt6通用）
    format.setChannelCount(1);   // 单声道（Qt5/Qt6通用）
    // ---------------- Qt6 核心适配：替换Qt5的setXXX系列方法 ----------------
    // Qt5的setSampleSize(16) + setSampleType(UnSignedInt) → Qt6的UInt16
    format.setSampleFormat(QAudioFormat::Int16);
    //format.setSampleType(QAudioFormat::UnSignedInt);

    // format.setSampleRate(48000);
    // format.setChannelCount(1);  // 强制单声道，匹配采集端
    // format.setSampleFormat(QAudioFormat::Float);

    //移除，Qt6 音频默认使用 PCM 编码，无需手动设置
    //format.setCodec("audio/pcm");
    //移除，Qt6 统一默认小端序，无该接口
    //format.setByteOrder(qToLittleEndian);

    if (!info.isFormatSupported(format)) {
        //QMessageBox::information(NULL , "提示", "打开音频输入设备失败，使用兼容格式");
        // 改用设备推荐格式
        // Qt5: info.nearestFormat(format) → Qt6: info.preferredFormat()（逻辑等价）
        //format = info.preferredFormat();
        // //format = info.nearestFormat(format);
    }

    qDebug() << "最终输入格式：";
    qDebug() << "采样率：" << format.sampleRate();
    qDebug() << "声道数：" << format.channelCount();
    qDebug() << "采样格式：" << format.sampleFormat();

    m_audio_in = NULL;
    m_buffer_in = NULL;
    m_audioState = pausing;
    m_timer = new QTimer(this);
    connect( m_timer , &QTimer::timeout , this , &AudioRead::ReadMore );

#ifdef USE_VAD
    //vad create
    if(0 != WebRtcVad_Create(&handle)){
        qDebug() << "vad create failed";
    }
    //vad init
    if(0 != WebRtcVad_Init(handle)){
        qDebug() << "vad init failed";
    }
#endif

}

AudioRead::~AudioRead()
{
    qDebug() << __func__;
    //回收定时器
    if(m_timer){
        m_timer->stop();
        delete m_timer;m_timer = NULL;
    }
    //回收采集对象
    if(m_audio_in)
    {
        m_audio_in->stop();
        delete m_audio_in;m_audio_in = NULL;
    }
    // 置空IO设备指针，避免野指针
    m_buffer_in = nullptr;
#ifdef USE_VAD
    //回收vad
    WebRtcVad_Free(handle);
#endif
}

void AudioRead::ReadMore()
{
#if USE_SPEEX
    if (!m_audio_in)
        return;
    // 初始化2048字节缓冲区
    QByteArray m_buffer(2048,0);

    // Qt6核心修复：用IO设备的QIODevice::bytesAvailable()替代QAudioSource::bytesReady()
    qint64 len = m_buffer_in->bytesAvailable();
    //qDebug() << "m_buffer_in->bytesAvailable sizes:"<< len ;
    if (len < 640)
    {
        return;
    }
    //从音频设备对应的缓冲区中读取 640字节 到m_buffer
    qint64 l = m_buffer_in->read(m_buffer.data(), 640);
    //qDebug() << "readLen sizes:"<< l ;

    // 封装成帧，并发射信号
    QByteArray frame;
    //---------------------------------vad静音检测---------------------------------
#ifdef USE_VAD
    char * bufferData = (char*)m_buffer.data() ;
    //每次操作 320字节
    for(int i = 0; i < 640; i += 320){
        char * tmp = bufferData + i;
        //静音检测返回值：-1错误 0静音 1有声
        if(0 == WebRtcVad_Process(handle, 8000, (int16_t*)tmp, 160)){
            //静音：清除这块空间
            memset(tmp, 0, 320);
        }
    }
#endif

    //---------------------------------speex编码----------------------------------
    char bytes[800] = {0}; // 存储编码后的单段数据
    float input_frame1[320];// Speex编码器要求的输入格式（float数组）
    char buf[800] = {0};
    char * pInData = (char*)m_buffer.data() ;
    memcpy( buf , pInData , 640); // 把读取的640字节PCM数据拷贝到buf
    int i = 0;
    int nbytes = 0;
    {
        //转换为大端 -> float
        short num = 0;
        for (i = 0;i < 160;i++)
        {
            num = (uint8_t)buf[2 * i] | (((uint8_t)buf[2 * i + 1]) << 8);
            input_frame1[i] = num;
            //num = m_buffer[2 * i] | ((short)(m_buffer[2 * i + 1]) << 8);
            //qDebug() << "float in" << num << input_frame1[i];
        }
        //压缩数据
        speex_bits_reset(&bits_enc);// 重置编码比特流
        speex_encode(Enc_State,input_frame1,&bits_enc);// Speex核心编码函数
        nbytes = speex_bits_write(&bits_enc,bytes,800);// 把编码后的数据写入bytes
        frame.append(bytes,nbytes);                    // 拼接第一段编码数据到最终帧
        //转换为大端 -> float
        for (i = 0;i < 160;i++)
        {
            num = (uint8_t)buf[2 * i + 320] | (((uint8_t)buf[2 * i + 1 + 320]) << 8);
            input_frame1[i] = num;
        }
        //压缩数据
        speex_bits_reset(&bits_enc);
        speex_encode(Enc_State,input_frame1,&bits_enc);
        nbytes = speex_bits_write(&bits_enc,bytes,800);
        frame.append(bytes,nbytes);
        qDebug() << "audioFrame.size() = " << frame.size();
        //发送 帧信号
        Q_EMIT SIG_audioFrame (frame);
        return;
    }
#else
    if (!m_audio_in)
        return;
    // 初始化2048字节缓冲区
    QByteArray m_buffer(2048,0);

    // Qt6核心修复：用IO设备的QIODevice::bytesAvailable()替代QAudioSource::bytesReady()
    qint64 len = m_buffer_in->bytesAvailable();
    qDebug() << "m_buffer_in->bytesAvailable sizes:"<< len ;
    if (len < 640)
    {
        return;
    }
    //从音频设备对应的缓冲区中读取 640字节
    qint64 l = m_buffer_in->read(m_buffer.data(), len);
    qDebug() << "l sizes:"<< l ;

    // 封装成帧并发射信号
    QByteArray frame;
    frame.append(m_buffer.data(), len);
    Q_EMIT SIG_audioFrame(frame);
#endif
}

void AudioRead::start()
{
    if(m_audioState == stopped || m_audioState == pausing){
        //创建采集对象
        m_audio_in = new QAudioSource(format, this);//QAudioSource 的构造函数，会隐式关联默认输入设备

        //返回缓冲区地址 给m_buffer_in
        m_buffer_in = m_audio_in->start();//声音采集开始
        m_timer->start(1000/50 - 5);//一秒50次采样，20ms一次 + 5ms提速
        m_audioState = playing;

        //查看QAudioSource的默认缓冲区大小（初始为设备推荐值）
        int currentBufSize = m_audio_in->bufferSize();
        qDebug() << "QAudioSource默认缓冲区大小：" << currentBufSize << "字节";
    }
}

void AudioRead::pause()
{
    if(m_audioState == playing){
        //停止计时
        m_timer->stop();
        //回收采集对象
        if(m_audio_in){
            m_audio_in->stop();
            delete m_audio_in;m_audio_in = NULL;
        }
        // 置空IO设备指针，避免野指针
        m_buffer_in = nullptr;
        m_audioState = pausing;
    }
}



