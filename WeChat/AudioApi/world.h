#ifndef WORLD_H
#define WORLD_H

// Qt6 音频输入类头文件（替代QAudioInput）
#include <QAudioSource>
// Qt6 音频输出类头文件（替代QAudioOutput）
#include <QAudioSink>

#include <QAudioFormat>
//#include <QtMultimedia/QAudioFormat>

// Qt6 替代QAudioDeviceInfo的头文件
#include <QAudioDevice>
#include <QMediaDevices>

#include<QIODevice>

#include <QByteArray>
#include<QTimer>
#include<QMessageBox>
#include<qDebug>
#include"speex_64/include/speex/speex.h"
#include"WebRtc_Vad/webrtc_vad.h"

enum ENUM_PLAY_STATE {stopped, playing, pausing};

#define SPEEX_QUALITY (8)
//是否使用编码器
#define USE_SPEEX (1)
//是否静音检测
#define USE_VAD (1)


#endif // WORLD_H
