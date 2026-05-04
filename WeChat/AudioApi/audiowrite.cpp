#include "audiowrite.h"

AudioWrite::AudioWrite(QObject *parent)
    : QObject{parent}
{
    //speex 初始化
    speex_bits_init(&bits_dec);
    Dec_State = speex_decoder_init(speex_lib_get_mode(SPEEX_MODEID_NB));

    //首先初始化设备
    // ---------------- Qt6 替换QAudioDeviceInfo ----------------
    // Qt5: QAudioDeviceInfo::defaultInputDevice() → Qt6: QMediaDevices::defaultAudioOutput()
    QAudioDevice info = QMediaDevices::defaultAudioOutput();
    qDebug() << "默认输出设备名称：" << info.description();
    format = info.preferredFormat();
    qDebug() << "设备推荐播放格式：";
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


    // 空设备判断（新增，避免崩溃）
    if (info.isNull()) {
        QMessageBox::warning(NULL, "错误", "未检测到音频输出设备！");
        return;
    }

     // 校验格式是否被输出设备支持
    if (!info.isFormatSupported(format)) {
        //QMessageBox::information(NULL , "提示", "打开音频输出设备失败，使用兼容格式");
        // 改用设备推荐格式
        // Qt5: info.nearestFormat(format) → Qt6: info.preferredFormat()（逻辑等价）
        //format = info.preferredFormat();
        //format = info.nearestFormat(format);
    }
    qDebug() << "最终播放格式：";
    qDebug() << "采样率：" << format.sampleRate();
    qDebug() << "声道数：" << format.channelCount();
    qDebug() << "采样格式：" << format.sampleFormat();

    m_audio_out = new QAudioSink(format, this);
    m_Buffer_out = m_audio_out->start();
}

// 析构函数：释放资源，避免内存泄漏
AudioWrite::~AudioWrite()
{
    if (m_audio_out) {
        m_audio_out->stop(); // 停止播放
        delete m_audio_out;
        m_audio_out = nullptr;
    }
    m_Buffer_out = nullptr; // IO设备由QAudioSink管理，无需手动删除
}

void AudioWrite::slot_playAudio(QByteArray ba)
{
#if USE_SPEEX
    //speex解码
    char bytes[800] = {0};
    int i = 0;
    float output_frame1[320] = {0};
    char buf[800] = {0};
    memcpy(bytes,ba.data(),ba.length() / 2);
    //解压缩数据 106 62
    //speex_bits_reset(&bits_dec);
    speex_bits_read_from(&bits_dec,bytes,ba.length() / 2);
    int error = speex_decode(Dec_State,&bits_dec,output_frame1);
    //将解压后数据转换为声卡识别格式
    //大端->小端
    short num = 0;
    for (i = 0;i < 160;i++)
    {
        num = output_frame1[i];
        buf[2 * i] = num;
        buf[2 * i + 1] = num >> 8;
        //qDebug() << "float out" << num << output_frame1[i];
    }
    memcpy(bytes,ba.data() + ba.length() / 2,ba.length() / 2);
    //解压缩数据
    //speex_bits_reset(&bits_dec);
    speex_bits_read_from(&bits_dec,bytes,ba.length() / 2);
    error = speex_decode(Dec_State,&bits_dec,output_frame1);
    //将解压后数据转换为声卡识别格式
    //大端
    for (i = 0;i < 160;i++)
    {
        num = output_frame1[i];
        buf[2 * i + 320] = num;
        buf[2 * i + 1 + 320] = num >> 8;
    }
    qint64 l = m_Buffer_out->write(buf,640);
    qDebug() << "recv sizes:"<< l ;
    return;

#else
    if(ba.size() < 640)
        return;

    // 写入640字节音频数据到播放缓冲区
    qint64 writeLen = m_Buffer_out->write(ba.data(), ba.size());
    qDebug() << "实际播放字节数：" << writeLen; // 可选：打印实际写入长度，排查播放异常
#endif
}
