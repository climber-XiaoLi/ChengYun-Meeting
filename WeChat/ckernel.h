#ifndef CKERNEL_H
#define CKERNEL_H

#include <QObject>
#include"wechatdialog.h"
#include"TcpClientMediator.h"
#include"packdef.h"
#include"logindialog.h"
#include"roomdialog.h"
#include"videoread.h"
#include"screenread.h"

//协议映射表使用的类型
class Ckernel;
typedef void (Ckernel::*PFUN)(uint sock,char* buf,int nlen);

class SendVideoWorker;
class Ckernel : public QObject
{
    Q_OBJECT
public:
    explicit Ckernel(QObject *parent = nullptr);

    //单例
    static Ckernel* GetInstance(){
        static Ckernel kernel;
        return & kernel;
    }

signals:
    void SIG_SendVideo(char * buf, int nlen);
    void SIG_SendVideo(QImage img);
public slots:
    //设置协议映射关系
    void setNetPackMap();
    //初始化配置
    void initConfig();
    //回收
    void slot_destroy();

    //视频 音频 开关
    void slot_startVideo();
    void slot_pauseVideo();
    //桌面共享 开关
    void slot_startScreen();
    void slot_pauseScreen();

    ///发送网络信息
    //发送登录信息
    void slot_loginCommit(QString tel,QString pass);
    //发送注册信息
    void slot_registerCommit(QString tel,QString pass,QString name);
    //创建房间
    void slot_createRoom();
    //加入房间
    void slot_joinRoom();
    //退出房间
    void slot_quitRoom();
    //发送音频帧
    void slot_audioFrame(QByteArray ba);
    //发送视频帧(摄像头、桌面屏幕)
    void slot_sendVideoFrame(QImage img);
    //多线程发送视频帧
    void slot_SendVideo_thread(char * buf, int nlen);
    void slot_SendVideo_thread(QImage img);

    ///网络信息处理
    void slot_dealData(uint sock,char* buf,int nlen);
    //登录回复
    void slot_dealLoginRs(uint sock,char* buf,int nlen);
    //注册回复
    void slot_dealRegisterRs(uint sock,char* buf,int nlen);
    //创建房间回复
    void slot_dealCreateRoomRs(uint sock,char* buf,int nlen);
    //加入房间回复
    void slot_dealJoinRoomRs(uint sock,char* buf,int nlen);
    //处理房间成员请求
    void slot_dealRoomMemberRq(uint sock,char* buf,int nlen);
    //处理退出房间
    void slot_dealLeaveRoomRq(uint sock,char* buf,int nlen);
    //处理音频帧
    void slot_dealAudioFrameRq(uint sock,char* buf,int nlen);
    //处理视频帧
    void slot_dealVideoFrameRq(uint sock,char* buf,int nlen);

private:
    WeChatDialog * m_pWeChatDlg;
    LoginDialog * m_pLoginDlg;
    RoomDialog * m_pRoomDlg;
    INetMediator * m_pClient;
    enum client_type{audio_client = 0, video_client};
    INetMediator * m_pAVClient[2];

    //协议映射表
    PFUN m_netPackMap[DEF_PACK_COUNT];

    ///音频：一个采集对象 多个播放对象 map
    std::map<int, AudioWrite *> m_mapIDToAudioWrite;
    ///视频：一个采集对象
    VideoRead * m_pVideoRead;
    ///桌面：一个采集对象
    ScreenRead * m_pScreenRead;

    //发送视频帧线程
    QSharedPointer<SendVideoWorker> m_pSendVideoWorker;



    int m_id;      //用户id
    QString m_name;//用户名字
    int m_iconid;  //用户头像id
    int m_roomid;  //房间id
    //服务器IP
    QString  m_serverIP;
};

//视频发送线程
class SendVideoWorker : public ThreadWorker{
    Q_OBJECT
public slots:
    //多线程发送视频帧
    void slot_sendVideo(char * buf, int nlen){
        Ckernel::GetInstance()->slot_SendVideo_thread(buf, nlen);
    };

    void slot_sendVideo(QImage img){
        Ckernel::GetInstance()->slot_SendVideo_thread(img);
    };
private:

};

#endif // CKERNEL_H
