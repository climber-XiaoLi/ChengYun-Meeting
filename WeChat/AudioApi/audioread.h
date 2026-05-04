#ifndef AUDIOREAD_H
#define AUDIOREAD_H

#include <QObject>
#include"world.h"

class AudioRead : public QObject
{
    Q_OBJECT
public:
    explicit AudioRead(QObject *parent = nullptr);
    ~AudioRead();
public slots:
    //定时超时，从缓冲区读取音频数据
    void ReadMore();

    void start();
    void pause();

signals:
    void SIG_audioFrame(QByteArray ba);
private:
    //QT6
    QAudioSource * m_audio_in;//采集声卡 音频输入
    QIODevice * m_buffer_in;//对应的缓冲区
    QTimer * m_timer;
    QAudioFormat format;
    int m_audioState;

    //SPEEX 相关全局变量
    SpeexBits bits_enc;
    void * Enc_State;
    //webRTC vad静音检测
    VadInst * handle;
    //NSX 降噪 todo
};

#endif // AUDIOREAD_H
