#ifndef COMMON_H
#define COMMON_H




#include"highgui/highgui.hpp"
#include"imgproc/imgproc.hpp"
#include"core/core.hpp"
#include"opencv2\imgproc\types_c.h"

//人脸识别-强化
#include "src/facedetectcnn.h"
#include"opencv2/opencv.hpp"

//define the buffer size. Do not change the size!
//0x9000 = 1024 * (16 * 2 + 4), detect 1024 face at most
#define DETECT_BUFFER_SIZE 0x9000

#include<QMessageBox>

using namespace cv;

#define FRAME_RATE (15)
//图片的宽和高
#define IMAGE_WIDTH (320)
#define IMAGE_HEIGHT (240)


#endif // COMMON_H
