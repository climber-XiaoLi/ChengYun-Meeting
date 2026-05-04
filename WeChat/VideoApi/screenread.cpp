#include "screenread.h"

ScreenRead::ScreenRead(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer;
    // connect(m_timer,SIGNAL(timeout()),
    //         this,SLOT(slots_getScreenFrame()));
    //获取桌面对象： 主屏幕
    m_screen = QApplication::primaryScreen(); //问题：如何获取整个屏幕
    //获取屏幕分辨率
    QPixmap pixmap = m_screen->grabWindow(0);// 当前屏幕分辨率： 2560 × 1600
    qDebug() << "当前屏幕分辨率：" << pixmap.width() << "×" << pixmap.height();

    m_pScreenWorker = QSharedPointer<ScreenWorker>(new ScreenWorker);//智能指针：自动回收
    m_pScreenWorker.data()->slot_setInfo(this);
    connect(m_timer,SIGNAL(timeout()),
            m_pScreenWorker.data(),SLOT(slot_dowork()));
}

ScreenRead::~ScreenRead()
{
    if(m_timer){
        m_timer->stop();
        delete m_timer;m_timer = NULL;
    }
}

void ScreenRead::slots_getScreenFrame()
{
    qDebug()<< "ScreenWorker线程ID:" << QThread::currentThreadId();
    //截取整个屏幕
    QPixmap pixmap = m_screen->grabWindow(0);

    QImage img = pixmap.toImage();
    img = img.convertToFormat(QImage::Format_RGB888);

    //img = img.scaled( 600, 450, Qt::KeepAspectRatio, Qt::SmoothTransformation );
    //img = img.scaled( IMAGE_WIDTH,IMAGE_HEIGHT, Qt::KeepAspectRatio , Qt::SmoothTransformation);
    //发送
    Q_EMIT SIG_sendScreenFrame(img);
}

void ScreenRead::slots_openVideo()
{
    m_timer->start(1000/FRAME_RATE - 10);//15帧 + 10ms提速
}

void ScreenRead::slots_closeVideo()
{
     m_timer->stop();
}
