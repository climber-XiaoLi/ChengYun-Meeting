HEADERS += \
    $$PWD/common.h \
    $$PWD/facedetect.h \
    $$PWD/myfacedetect.h \
    $$PWD/screenread.h \
    $$PWD/src/facedetectcnn.h \
    $$PWD/src/facedetection_export.h \
    $$PWD/threadworker.h \
    $$PWD/videoread.h

SOURCES += \
    $$PWD/facedetect.cpp \
    $$PWD/myfacedetect.cpp \
    $$PWD/screenread.cpp \
    $$PWD/src/facedetectcnn-data.cpp \
    $$PWD/src/facedetectcnn-model.cpp \
    $$PWD/src/facedetectcnn.cpp \
    $$PWD/threadworker.cpp \
    $$PWD/videoread.cpp

INCLUDEPATH += D:\QT_project\Wechat-Huiyi\WeChat\VideoApi\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\include\opencv2\
INCLUDEPATH += D:\QT_project\Wechat-Huiyi\WeChat\VideoApi\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\include

LIBS += -LD:\QT_project\Wechat-Huiyi\WeChat\VideoApi\OpenCV-MinGW-Build-OpenCV-4.5.5-x64\x64\mingw\lib \
        -lopencv_calib3d455 \
        -lopencv_core455 \
        -lopencv_features2d455 \
        -lopencv_flann455 \
        -lopencv_highgui455 \
        -lopencv_imgproc455 \
        -lopencv_ml455 \
        -lopencv_objdetect455 \
        -lopencv_video455 \
        -lopencv_videoio455 \
        -lopencv_dnn455
