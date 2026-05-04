#ifndef CLOGIC_H
#define CLOGIC_H

#include"TCPKernel.h"

class CLogic
{
public:
    CLogic( TcpKernel* pkernel )
    {
        m_pKernel = pkernel;
        m_sql = pkernel->m_sql;
        m_tcp = pkernel->m_tcp;
        m_mapIDToUserInfo = &(pkernel->m_mapIDToUserInfo);
        m_mapRoomidToIdList = &(pkernel->m_mapRoomidToIdList);
    }
public:
    //设置协议映射
    void setNetPackMap();
    /************** 发送数据*********************/
    void SendData( sock_fd clientfd, char*szbuf, int nlen )
    {
        m_pKernel->SendData( clientfd ,szbuf , nlen );
    }
    /************** 网络处理 *********************/
    //注册
    void RegisterRq(sock_fd clientfd, char*szbuf, int nlen);
    //登录
    void LoginRq(sock_fd clientfd, char*szbuf, int nlen);
    //创建房间
    void CreateRoomRq(sock_fd clientfd, char*szbuf, int nlen);
    //加入房间
    void JoinRoomRq(sock_fd clientfd, char*szbuf, int nlen);
    //离开房间
    void LeaveRoomRq(sock_fd clientfd, char*szbuf, int nlen);
    //处理音频帧
    void AudioFrameRq(sock_fd clientfd, char*szbuf, int nlen);
    //处理视频帧
    void VideoFrameRq(sock_fd clientfd, char*szbuf, int nlen);
    //注册音频
    void AudioRegister(sock_fd clientfd, char*szbuf, int nlen);
    //注册视频
    void VideoRegister(sock_fd clientfd, char*szbuf, int nlen);
    /*******************************************/

private:
    TcpKernel* m_pKernel;
    CMysql * m_sql;
    Block_Epoll_Net * m_tcp;
    MyMap<int,UserInfo*> * m_mapIDToUserInfo;
    MyMap<int,list<int>> * m_mapRoomidToIdList;
};

#endif // CLOGIC_H
