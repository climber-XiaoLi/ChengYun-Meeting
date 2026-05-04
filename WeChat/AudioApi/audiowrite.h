#ifndef AUDIOWRITE_H
#define AUDIOWRITE_H

#include <QObject>
#include"world.h"

class AudioWrite : public QObject
{
    Q_OBJECT
public:
    explicit AudioWrite(QObject *parent = nullptr);
    ~AudioWrite();
signals:

public slots:
    void slot_playAudio(QByteArray ba);
private:
    QAudioSink  * m_audio_out;
    QAudioFormat format;
    QIODevice *  m_Buffer_out;

    //SPEEX 相关全局变量
    SpeexBits bits_dec;
    void * Dec_State;
};

#endif // AUDIOWRITE_H
