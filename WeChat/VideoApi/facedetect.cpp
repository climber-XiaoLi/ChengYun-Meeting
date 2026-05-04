#include "facedetect.h"

FaceDetect::FaceDetect(QObject *parent)
    : QObject{parent}
{

    m_pBuffer = (unsigned char *)malloc(DETECT_BUFFER_SIZE);
}

FaceDetect::~FaceDetect()
{
    free(m_pBuffer);
}

void FaceDetect::FaceDetectAndDraw(Mat &frame, std::vector<Rect> &vec)
{
    Mat &image = frame;

    ///////////////////////////////////////////
    // CNN face detection
    // Best detection rate
    //////////////////////////////////////////
    //!!! The input image must be a BGR one (three-channel) instead of RGB
    //!!! DO NOT RELEASE pResults !!!

    int * pResults = facedetect_cnn(m_pBuffer, (unsigned char*)(image.ptr(0)), image.cols, image.rows, (int)image.step);

    //printf("time = %gms\n", cvtm.getTimeMilli());

    //printf("%d faces detected.\n", (pResults ? *pResults : 0));
    Mat &result_image = image;
    //print the detection results
    for(int i = 0; i < (pResults ? *pResults : 0); i++)
    {
        short * p = ((short*)(pResults+1)) + 16*i;
        int confidence = p[0];
        int x = p[1];
        int y = p[2];
        int w = p[3];
        int h = p[4];

        //show the score of the face. Its range is [0-100]
        char sScore[256];
        //snprintf(sScore, 256, "%d", confidence);
        //cv::putText(result_image, sScore, cv::Point(x, y-3), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);

        //draw face rectangle
        if(confidence > 60){//可信度 > 60的
            //rectangle(result_image, Rect(x, y, w, h), Scalar(0, 255, 0), 2);
            vec.push_back(Rect(x, y, w, h));
        }

        //draw five face landmarks in different colors
        // cv::circle(result_image, cv::Point(p[5], p[5 + 1]), 1, cv::Scalar(255, 0, 0), 2);
        // cv::circle(result_image, cv::Point(p[5 + 2], p[5 + 3]), 1, cv::Scalar(0, 0, 255), 2);
        // cv::circle(result_image, cv::Point(p[5 + 4], p[5 + 5]), 1, cv::Scalar(0, 255, 0), 2);
        // cv::circle(result_image, cv::Point(p[5 + 6], p[5 + 7]), 1, cv::Scalar(255, 0, 255), 2);
        // cv::circle(result_image, cv::Point(p[5 + 8], p[5 + 9]), 1, cv::Scalar(0, 255, 255), 2);

    }
}
