#ifndef SCREENREAD_H
#define SCREENREAD_H

#include <QObject>
#include<QTimer>
//#include<QDesktopWidget>
//#include <QGuiApplication>
#include <QApplication>
#include<QScreen>
#include"common.h"
#include"threadworker.h"

// 前向声明
class ScreenWorker;
class ScreenRead : public QObject
{
    Q_OBJECT
public:
    explicit ScreenRead(QObject *parent = nullptr);
    ~ScreenRead();
signals:
    void SIG_sendScreenFrame(QImage img);
public slots:
    void slots_getScreenFrame();
    void slots_openVideo();
    void slots_closeVideo();
private:
    QTimer * m_timer;
    QScreen * m_screen;
    //工作者线程：采集摄像头并人脸识别
    QSharedPointer<ScreenWorker> m_pScreenWorker;


};

class ScreenWorker : public ThreadWorker{
    Q_OBJECT
public slots:
    void slot_setInfo(ScreenRead * p){
        m_pScreenRead = p;
    };
    //使用qt多线程采集桌面
    void slot_dowork(){
        m_pScreenRead->slots_getScreenFrame();
    };
private:
    ScreenRead * m_pScreenRead;
};

#endif // SCREENREAD_H
