#include "myfacedetect.h"
#include "objdetect/objdetect.hpp"
//#include <opencv2/dnn.hpp>
#include<QCoreApplication>
#include<qDebug>

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

MyFaceDetect::MyFaceDetect(QObject *parent)
    : QObject{parent}
{

}

void MyFaceDetect::FaceDetectInit()
{
    // 将 xml 文件放在 exe 同级的目录下面
    QString face_cascade_name = QCoreApplication::applicationDirPath()
                                +"/haarcascade_frontalface_default.xml";
    //+"/haarcascade_frontalface_alt_tree.xml";//"haarcascade_frontalface_alt.xml"
    //+ "/lbpcascade_frontalface.xml" ;
    QString eyes_cascade_name = QCoreApplication::applicationDirPath()
                                +"/haarcascade_eye_tree_eyeglasses.xml";
    //haarcascade_eye_tree_eyeglasses.xml;// +"/haarcascade_eye.xml";

    // 根据路径加载 xml 文件
    qDebug() << face_cascade_name;
    //-- 1. Load the cascade
    if( !face_cascade.load( face_cascade_name.toStdString() ) )
    {
        qDebug()<< "--(!)Error loading face " ;
        return;
    }
    qDebug() << eyes_cascade_name;
    if( !eyes_cascade.load( eyes_cascade_name.toStdString() ) )
    {
        qDebug()<<"--(!)Error loading eyes " ;
        return;
    }
}

void MyFaceDetect::detectAndDisplay(Mat &frame, std::vector<Rect> &faces)
{
    Mat frame_gray;
    //首先, 得到灰度图片用于做识别
    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    face_cascade.detectMultiScale( frame_gray, faces
                                  , 1.05, 6, 0, Size(30,30) , Size(500, 500));

    //为了防止误识别, 再识别眼睛
    for( auto ite = faces.begin() ; ite != faces.end() ; ){
        Rect rct = *ite;
        Mat faceROI = frame_gray( rct );
        std::vector<Rect> eyes;
        //-- 在每张人脸上检测双眼
        eyes_cascade.detectMultiScale( faceROI, eyes , 1.05, 5, 0 , Size(10, 10) );//检测精度1.1
        //正常：有两只眼睛 鼻子的大小 应该不超过脸的 1/3
        if( eyes.size() < 1 || eyes.size() > 4){
            ite = faces.erase(ite);
        }else{
            if( rct.height*0.5 < eyes[0].y ){
                ite = faces.erase(ite);
                continue;
            }
            // ellipse( frame, center, Size( rct.width*0.5, rct.height*0.5), 0, 0, 360,
            //Scalar( 0, 255, 255 ), 4, 8, 0 );
            // Rect rctnose;
            // rctnose.x = nose[0].x + rct.x;
            // rctnose.y = nose[0].y + rct.y;
            // rctnose.width = nose[0].width;
            // rctnose.height = nose[0].height;
            // Point nosecenter( rctnose.x + rctnose.width*0.5, rctnose.y+rctnose.height*0.5 );
            // ellipse( frame, nosecenter, Size( rctnose.width*0.5,rctnose.height*0.5),0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        ++ite;
        }
        // //测试：
        // for( auto ite = eyes.begin() ; ite != eyes.end() ; ++ite )
        // {
        //     Rect eye_rct = *ite;
        //     Point eye_center(eye_rct.x + eye_rct.width * 0.5 + rct.x,
        //                      eye_rct.y + eye_rct.height * 0.5 + rct.y); // 修正坐标（相对→绝对）
        //     ellipse( frame, eye_center, Size( eye_rct.width*0.5, eye_rct.height*0.5), 0, 0, 360,
        //             Scalar( 0, 255, 255 ), 4, 8, 0 );
        // }
    }
    //-- 显示结果图像
    // //测试：绘制识别的人脸矩形
    // for( auto ite = faces.begin() ; ite != faces.end() ; ++ite )
    // {
    //     Rect rct = *ite;
    //     Point center( rct.x + rct.width*0.5, rct.y + rct.height*0.5 );
    //     ellipse( frame, center, Size( rct.width*0.5, rct.height*0.5), 0, 0, 360,
    //             Scalar( 255, 0, 255 ), 4, 8, 0 );
    // }
    //imshow( window_name_face, frame );

}










