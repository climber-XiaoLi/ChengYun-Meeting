#ifndef VIDEOREAD_H
#define VIDEOREAD_H

#include <QObject>
#include<QTimer>
#include"common.h"
#include"threadworker.h"
#include"myfacedetect.h"
#include"facedetect.h"

// 前向声明
class VideoWorker;
class VideoRead : public QObject
{
    Q_OBJECT
public:
    explicit VideoRead(QObject *parent = nullptr);
    ~VideoRead();

signals:
    void SIG_sendVideoFrame(QImage img);
public slots:
    void slots_getVideoFrame();
    void slots_openVideo();
    void slots_closeVideo();

    void slots_setMoji(int newMoji);
private:
    QTimer * m_timer;
    //opencv获取图片对象
    cv::VideoCapture m_cap;

    //人脸检测对象
    FaceDetect * m_pFaceDetect;

    //工作者线程：采集摄像头并人脸识别
    QSharedPointer<VideoWorker> m_pVideoWorker;

    //人脸 Rect矩形框数组
    std::vector<Rect> m_vecLastFace;
    //特效{兔耳朵，帽子}
    enum special_types{tuer = 1, hat ,smile};
    int m_moji;
    QImage m_tuer;
    QImage m_hat;
    QImage m_smile;
};


class VideoWorker : public ThreadWorker{
    Q_OBJECT
public slots:
    void slot_setInfo(VideoRead * p){
        m_pVideoRead = p;
    };
    //使用qt多线程采集摄像头+人脸识别
    void slot_dowork(){
        m_pVideoRead->slots_getVideoFrame();
    };
private:
    VideoRead * m_pVideoRead;
};

#endif // VIDEOREAD_H
