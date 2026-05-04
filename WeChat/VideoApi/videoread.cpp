#include "videoread.h"
#include<QPainter>

VideoRead::VideoRead(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer;
    // connect(m_timer,SIGNAL(timeout()),
    //         this,SLOT(slots_getVideoFrame()));

    m_pVideoWorker = QSharedPointer<VideoWorker>(new VideoWorker);//智能指针：自动回收
    m_pVideoWorker.data()->slot_setInfo(this);
    connect(m_timer,SIGNAL(timeout()),
            m_pVideoWorker.data(),SLOT(slot_dowork()));

    //需要 xml 加到 exe 同目录下
    MyFaceDetect::FaceDetectInit();

    //初始化人脸检测对象
    m_pFaceDetect = new FaceDetect;
    //加载特效图片
    m_tuer.load(":/images/tuer.png");;
    m_hat.load(":/images/hat.png");
    m_smile.load(":/bq/0.png");
    m_moji = 0;
}

VideoRead::~VideoRead()
{
    if(m_timer){
        m_timer->stop();
        delete m_timer;m_timer = NULL;
    }
}

//采集图像
void VideoRead::slots_getVideoFrame()
{
    qDebug()<< "VideoWorker线程ID:" << QThread::currentThreadId();
    //从摄像头对象 读取数据
    Mat frame; //Mat对象 存储图像
    if(!m_cap.read(frame)){
        return;
    }
    //----------------------------------进行人脸识别----------------------------------
    std::vector<Rect> faces;
    if(m_moji != 0){
        //MyFaceDetect::detectAndDisplay(frame, faces);
        m_pFaceDetect->FaceDetectAndDraw(frame, faces);
    }


    //将 opencv 采集的 BGR 的图片类型转化为 RGB24 的类型
    cvtColor(frame,frame,CV_BGR2RGB);
    //Mat图像不是 显示和传输 的格式
    //定义 QImage 对象, 用于发送数据以及图片显示
    QImage image ((unsigned const char*)frame.data,frame.cols,frame.rows,QImage::Format_RGB888);{}

    //将特效画在图片上
    if(faces.size() > 0)
        m_vecLastFace = faces;
    QImage tmpImg;
    switch(m_moji){
    case tuer:
        tmpImg = m_tuer;break;
    case hat:
        tmpImg = m_hat;break;
    case smile:
        tmpImg = m_smile;break;
    }
    if(m_moji == tuer || m_moji == hat){
        QPainter paint(&image);
        for(int i =0;i < m_vecLastFace.size();i++){
            Rect rct = m_vecLastFace[i];
            int x = rct.x + rct.width*0.5 - tmpImg.width()*0.5 + 20;
            int y = rct.y - tmpImg.height();
            QPoint p(x,y);
            paint.drawImage(p, tmpImg);
        }
    }else if(m_moji == smile){
        QPainter paint(&image);
        paint.setRenderHint(QPainter::SmoothPixmapTransform); // 抗锯齿（缩放不模糊）
        for(int i = 0; i < m_vecLastFace.size(); i++){
            Rect rct = m_vecLastFace[i];
            // 1. 取最大边长作为正方形尺寸（保证覆盖整个脸）
            int faceSize = qMax(rct.width, rct.height) * 1.2;

            int centerX = rct.x + rct.width / 2;
            int centerY = rct.y + rct.height / 2;
            int drawX = centerX - faceSize / 2;
            int drawY = centerY - faceSize / 2;
            paint.drawImage(QRect(drawX, drawY, faceSize, faceSize), tmpImg);
        }
    }

    //转化为大小更小的图片 保持缩放比
    image = image.scaled( IMAGE_WIDTH,IMAGE_HEIGHT, Qt::KeepAspectRatio );
    //发送图片
    Q_EMIT SIG_sendVideoFrame( image );
}

//开启摄像头
void VideoRead::slots_openVideo()
{
    m_timer->start(1000/FRAME_RATE -10);//15帧 + 10ms提速
    //打开摄像头
    m_cap.open(0);//0 默认摄像头
    if(!m_cap.isOpened()){
        QMessageBox::information(NULL,tr("提示"),tr("视频没有打开"));
    }/*else {
        //打开摄像头时获取默认分辨率：640 × 480
        double default_width = m_cap.get(cv::CAP_PROP_FRAME_WIDTH);
        double default_height = m_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
        qDebug() << "摄像头默认分辨率：" << default_width << "×" << default_height;
    }*/
}

//关闭摄像头
void VideoRead::slots_closeVideo()
{
    m_timer->stop();
    //关闭摄像头
    if(m_cap.isOpened()){
        m_cap.release();
    }
}

void VideoRead::slots_setMoji(int newMoji)
{
    m_moji = newMoji;
}
