#ifndef FACEDETECT_H
#define FACEDETECT_H

#include <QObject>
#include"common.h"

class FaceDetect : public QObject
{
    Q_OBJECT
public:
    explicit FaceDetect(QObject *parent = nullptr);
    ~FaceDetect();
    //接收一个图片，然后在在图片上检测人脸，绘制人脸区域
    void FaceDetectAndDraw(Mat &frame, std::vector<Rect> &vec);
signals:

private:
    unsigned char * m_pBuffer;
};

#endif // FACEDETECT_H
