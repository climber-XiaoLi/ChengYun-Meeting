#pragma once

#include<memory.h>


//边界值
#define DEF_SIZE 45
#define DEF_BUFFERSIZE 1000
#define DEF_PORT 8000
#define DEF_SERVERIP "192.168.58.129"  //TODO

#define TRUE true
#define FALSE false

#define DEF_BUFFER         (4096)
#define DEF_CONTENT_SIZE	(1024)
#define MAX_SIZE           (60)
#define MAX_PATH           (260)

//自定义协议   先写协议头 再写协议结构
//登录 注册 获取好友信息 添加好友 聊天 发文件 下线请求
#define DEF_PACK_BASE	(10000)
#define DEF_PACK_COUNT (100)

//注册
#define DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
#define DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)
//登录
#define DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
#define DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)
//创建房间
#define DEF_PACK_CREATEROOM_RQ  (DEF_PACK_BASE + 4)
#define DEF_PACK_CREATEROOM_RS  (DEF_PACK_BASE + 5)
//加入房间
#define DEF_PACK_JOINROOM_RQ  (DEF_PACK_BASE + 6)
#define DEF_PACK_JOINROOM_RS  (DEF_PACK_BASE + 7)
//房间成员列表请求
#define DEF_PACK_ROOM_MEMBER    (DEF_PACK_BASE + 8)
//音频数据
#define DEF_PACK_AUDIO_FRAME    (DEF_PACK_BASE + 9)
//视频数据
#define DEF_PACK_VIDEO_FRAME    (DEF_PACK_BASE + 10)
//退出房间请求
#define DEF_PACK_LEAVEROOM_RQ   (DEF_PACK_BASE + 11)
//退出房间回复
//#define DEF_PACK_LEAVEROOM_RS   (DEF_PACK_BASE + 12)
//音频注册
#define DEF_PACK_AUDIO_REGISTER   (DEF_PACK_BASE + 13)
//视频注册
#define DEF_PACK_VIDEO_REGISTER   (DEF_PACK_BASE + 14)



//返回的结果
//注册请求的结果
#define tel_is_exist		(0)
#define register_success	(1)
#define name_is_exist       (2)
//登录请求的结果
#define user_not_exist		(0)
#define password_error		(1)
#define login_success		(2)


typedef int PackType;

//协议结构
//登录请求
typedef struct STRU_LOGIN_RQ
{
    STRU_LOGIN_RQ()
    {
        m_nType = DEF_PACK_LOGIN_RQ;
        memset(m_tel,0,MAX_SIZE);
        memset(m_password,0,MAX_SIZE);
    }

    PackType m_nType;   //包类型
    char     m_tel[MAX_SIZE] ; //用户ID
    char     m_password[MAX_SIZE];  //密码
} STRU_LOGIN_RQ;


//登录回复
typedef struct STRU_LOGIN_RS
{
    STRU_LOGIN_RS()
    {
        m_nType= DEF_PACK_LOGIN_RS;
        m_userid = 0;
        m_lResult = 0;
        memset(m_name,0,MAX_SIZE);
    }
    PackType m_nType;   //包类型
    int  m_userid;
    int  m_lResult ; //注册结果
    char m_name[MAX_SIZE];

} STRU_LOGIN_RS;

//注册请求
typedef struct STRU_REGISTER_RQ
{
    STRU_REGISTER_RQ():type(DEF_PACK_REGISTER_RQ)
    {
        memset( m_tel  , 0, sizeof(m_tel));
        memset( m_name  , 0, sizeof(m_name));
        memset( m_password , 0, sizeof(m_password) );
    }
    //需要手机号码 , 密码, 昵称
    PackType type;
    char m_tel[MAX_SIZE];
    char m_name[MAX_SIZE];
    char m_password[MAX_SIZE];

}STRU_REGISTER_RQ;

//注册回复
typedef struct STRU_REGISTER_RS
{
    //回复结果
    STRU_REGISTER_RS(): type(DEF_PACK_REGISTER_RS) , result(register_success)
    {
    }
    PackType type;
    int result;

}STRU_REGISTER_RS;

//服务器用于id -> sock映射
typedef struct UserInfo
{
    UserInfo()
    {
        m_sockfd = 0;
        m_audiofd = 0;
        m_videofd = 0;
        m_id = 0;
        m_roomid = 0;
        memset(m_userName, 0 , MAX_SIZE);

    }
    int  m_sockfd;
    int  m_audiofd;
    int  m_videofd;
    int  m_id;
    int  m_roomid;
    char m_userName[MAX_SIZE];

}UserInfo;

//创建房间请求
typedef struct STRU_CREATEROOM_RQ
{
    STRU_CREATEROOM_RQ()
    {
        m_nType = DEF_PACK_CREATEROOM_RQ;
        m_UserID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;

}STRU_CREATEROOM_RQ;

//创建房间回复
typedef struct STRU_CREATEROOM_RS
{
    STRU_CREATEROOM_RS()
    {
        m_nType= DEF_PACK_CREATEROOM_RS;
        m_lResult = 0;
        m_RoomId = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int  m_RoomId;

}STRU_CREATEROOM_RS;

//加入房间请求
typedef struct STRU_JOINROOM_RQ
{
    STRU_JOINROOM_RQ()
    {
        m_nType = DEF_PACK_JOINROOM_RQ;
        m_UserID = 0;
        m_RoomID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;
    int m_RoomID;

}STRU_JOINROOM_RQ;

//加入房间回复
typedef struct STRU_JOINROOM_RS
{
    STRU_JOINROOM_RS()
    {
        m_nType= DEF_PACK_JOINROOM_RS;
        m_lResult = 0;
        m_RoomID = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int m_RoomID;
}STRU_JOINROOM_RS;

//房间成员列表请求
typedef struct STRU_ROOM_MEMBER_RQ
{
    STRU_ROOM_MEMBER_RQ()
    {
        m_nType= DEF_PACK_ROOM_MEMBER;
        m_UserID =0;
        memset(m_UserName,0,MAX_SIZE);
    }
    PackType m_nType;   //包类型
    int m_UserID;
    char m_UserName[MAX_SIZE];

}STRU_ROOM_MEMBER_RQ;

//离开房间请求
typedef struct STRU_LEAVEROOM_RQ
{
    STRU_LEAVEROOM_RQ()
    {
        m_nType = DEF_PACK_LEAVEROOM_RQ;
        m_nUserId = 0;
        m_RoomId = 0;
        memset(szUserName,0,MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int    m_nUserId;     //用户ID
    int    m_RoomId;
    char   szUserName[MAX_SIZE];
}STRU_LEAVEROOM_RQ;

//注册音频
typedef struct STRU_AUDIO_REGISTER{
    STRU_AUDIO_REGISTER():m_nType(DEF_PACK_AUDIO_REGISTER)
    {
        m_nUserId = 0;
    }
    PackType   m_nType;   //包类型
    int    m_nUserId;     //用户ID
};
//注册视频
typedef struct STRU_VIDEO_REGISTER{
    STRU_VIDEO_REGISTER():m_nType(DEF_PACK_VIDEO_REGISTER)
    {
        m_nUserId = 0;
    }
    PackType   m_nType;   //包类型
    int    m_nUserId;     //用户ID
};

///音频数据帧
/// 成员描述
/// int type;
/// int userId;
/// int roomId;
/// int min;  //用于延迟过久，舍弃一些帧的参考时间
/// int sec;
/// int msec;
/// QByteArray audioFrame;
///

///视频数据帧
/// 成员描述
/// int type;
/// int userId;
/// int roomId;
/// int min;
/// int sec;
/// int msec;
/// QByteArray videoFrame;
///


