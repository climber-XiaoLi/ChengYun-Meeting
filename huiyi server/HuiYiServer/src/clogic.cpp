#include "clogic.h"

void CLogic::setNetPackMap()
{
    NetPackMap(DEF_PACK_REGISTER_RQ)    = &CLogic::RegisterRq;
    NetPackMap(DEF_PACK_LOGIN_RQ)       = &CLogic::LoginRq;
    NetPackMap(DEF_PACK_CREATEROOM_RQ)  = &CLogic::CreateRoomRq;
    NetPackMap(DEF_PACK_JOINROOM_RQ)    = &CLogic::JoinRoomRq;
    NetPackMap(DEF_PACK_LEAVEROOM_RQ)   = &CLogic::LeaveRoomRq;
    NetPackMap(DEF_PACK_AUDIO_FRAME)    = &CLogic::AudioFrameRq;
    NetPackMap(DEF_PACK_VIDEO_FRAME)    = &CLogic::VideoFrameRq;
    NetPackMap(DEF_PACK_AUDIO_REGISTER) = &CLogic::AudioRegister;
    NetPackMap(DEF_PACK_VIDEO_REGISTER) = &CLogic::VideoRegister;
}

#define _DEF_COUT_FUNC_    cout << "clientfd:"<< clientfd <<" "<< __func__ << endl;

//注册
void CLogic::RegisterRq(sock_fd clientfd,char* szbuf,int nlen)
{
    //cout << "clientfd:"<< clientfd << __func__ << endl;
    _DEF_COUT_FUNC_
    //1、拆包
    STRU_REGISTER_RQ * rq = (STRU_REGISTER_RQ*) szbuf;
    STRU_REGISTER_RS rs;
    //获取tel password name
    //查表 t_user 根据tel 查tel
    char sqlStr[1024]={0};//""
    sprintf(sqlStr,"select tel from t_user where tel = '%s';",rq->m_tel);
    list<string> resList;
    if(!m_sql->SelectMysql(sqlStr, 1, resList)){
        printf("SelectMysql error:%s\n",sqlStr);
        return;
    }
    //有user存在：返回已注册
    if(resList.size()>0){
        rs.result = tel_is_exist;
    }else{
    //没有user存在：查表t_user 根据name 查name
        char sqlStr[1024]={0};
        resList.clear();
        sprintf(sqlStr,"select name from t_user where name = '%s';",rq->m_name);
        if(!m_sql->SelectMysql(sqlStr, 1, resList)){
            printf("SelectMysql error:%s\n",sqlStr);
            return;
        }
        if(resList.size()>0){
            //有name：返回昵称已存在
            rs.result = name_is_exist;
        }else{
            //没有name：写入表tel pass name 头像id 签名，返回注册成功
            rs.result = register_success;
            sprintf(sqlStr,"insert into t_user(tel, passwd, name, iconid, feeling) values('%s','%s','%s','%d','%s');"
                    ,rq->m_tel,rq->m_password,rq->m_name,1,"比较懒，什么也没有写");
            if(!m_sql->UpdataMysql(sqlStr)){
                printf("UpdataMysql error:%s\n", sqlStr);
            }
        }
    }
    m_tcp->SendData(clientfd, (char*)&rs, sizeof(rs));
}

//登录
void CLogic::LoginRq(sock_fd clientfd ,char* szbuf,int nlen)
{
//    cout << "clientfd:"<< clientfd << __func__ << endl;
    _DEF_COUT_FUNC_
    //1、拆包
    STRU_LOGIN_RQ * rq = (STRU_LOGIN_RQ*)szbuf;
    STRU_LOGIN_RS rs;
    //根据tel 查 pass id name
    char strSql[1024] = {0};
    list<string> lstRes;
    sprintf(strSql,"select passwd,id,name from t_user where tel='%s';",rq->m_tel);
    if(!m_sql->SelectMysql(strSql, 3, lstRes)){
        printf("SelectMysql error:%s\n",strSql);
        return;
    }
    if(lstRes.size() == 0){
        //查不到：返回 用户不存在
        rs.m_lResult = user_not_exist;
    }else{
        //查到：比较pass是否一致
        if(strcmp(rq->m_password,lstRes.front().c_str()) != 0){
            //密码不一致：返回 密码错误
            rs.m_lResult = password_error;
        }else{
            //密码一致：
            lstRes.pop_front();
            int id = atoi(lstRes.front().c_str());
            lstRes.pop_front();
            //sock要保存起来，id -> sock 的映射
            UserInfo * pInfo = new UserInfo;
            pInfo->m_id = id;
            pInfo->m_roomid = 0;
            pInfo->m_sockfd = clientfd;
            strcpy(pInfo->m_userName, lstRes.front().c_str());
            lstRes.pop_front();
            //判断id是否已经在线：在线 强制下线
            if(m_mapIDToUserInfo->IsExist(pInfo->m_id)){
                //todo 强制下线
            }
            m_mapIDToUserInfo->insert(pInfo->m_id, pInfo);
            //返回 id name 结果（登陆成功）
            rs.m_userid = id;
            rs.m_lResult = login_success;
            strcpy(rs.m_name, pInfo->m_userName);
        }
    }
    m_tcp->SendData(clientfd, (char*)&rs, sizeof(rs));
}

//创建房间
void CLogic::CreateRoomRq(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_
    //拆包
    STRU_CREATEROOM_RQ * rq = (STRU_CREATEROOM_RQ*)szbuf;
    //创建随机数 房间号1-8位
    int roomid = 0;
    do{
        roomid = rand()%99999999 + 1;
    }while(m_mapRoomidToIdList->IsExist(roomid));//新的房间号
    //创建房间id列表 请求者id加入列表
    list<int> lst;
    lst.push_back(rq->m_UserID);
    //map中插入 roomid -> list 映射
    m_mapRoomidToIdList->insert(roomid, lst);
    printf("create room success,roomid:%d\n",roomid);
    //返回：房间号 结果
    STRU_CREATEROOM_RS rs;
    rs.m_RoomId = roomid;
    rs.m_lResult = 1;

    m_tcp->SendData(clientfd, (char*)&rs, sizeof(rs));
}

//加入房间
void CLogic::JoinRoomRq(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_
    //拆包
    STRU_JOINROOM_RQ * rq = (STRU_JOINROOM_RQ*)szbuf;
    //查看房间是否存在
    STRU_JOINROOM_RS rs;
    if(!m_mapRoomidToIdList->IsExist(rq->m_RoomID)){
        //房间不存在：返回失败
        rs.m_lResult = 0;
        rs.m_RoomID = rq->m_RoomID;
        m_tcp->SendData(clientfd, (char*)&rs, sizeof(rs));
        return;
    }
    //房间存在：返回成功
    rs.m_lResult = 1;
    rs.m_RoomID = rq->m_RoomID;
    m_tcp->SendData(clientfd, (char*)&rs, sizeof(rs));
    //根据roomid 拿到 房间成员id列表
    list<int> lstRoomMem;
    if(!m_mapRoomidToIdList->find(rq->m_RoomID, lstRoomMem)){
        printf("find lstRoomMem from m_mapRoomidToIdList failed\n");
        return;
    }
    //joinner信息
    UserInfo * joinnerInfo;
    m_mapIDToUserInfo->find(rq->m_UserID, joinnerInfo);

    STRU_ROOM_MEMBER_RQ joinrq;
    joinrq.m_UserID = rq->m_UserID;
    strcpy(joinrq.m_UserName, joinnerInfo->m_userName);
    //循环遍历 -- 互换信息
    for(auto ite = lstRoomMem.begin(); ite != lstRoomMem.end(); ++ite){
        int Memid = *ite;
        if(!m_mapIDToUserInfo->IsExist(Memid)) continue;
        UserInfo * memberInfo;
        m_mapIDToUserInfo->find(Memid, memberInfo);

        STRU_ROOM_MEMBER_RQ memrq;
        memrq.m_UserID = memberInfo->m_id;
        strcpy(memrq.m_UserName, memberInfo->m_userName);
        //把加入人的信息 发个 房间内每个成员
        m_tcp->SendData(memberInfo->m_sockfd, (char*)&joinrq, sizeof(joinrq));
        //把房间内每个成员信息 发给 加入人
        m_tcp->SendData(clientfd, (char*)&memrq, sizeof(memrq));
    }
    //将加入人 添加进 房间成员列表,更新m_mapRoomidToIdList
    lstRoomMem.push_back(joinnerInfo->m_id);
    m_mapRoomidToIdList->insert(rq->m_RoomID, lstRoomMem);
}

//离开房间
void CLogic::LeaveRoomRq(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_
    //拆包
    STRU_LEAVEROOM_RQ * rq = (STRU_LEAVEROOM_RQ*)szbuf;
    //查看房间是否存在
    if(!m_mapRoomidToIdList->IsExist(rq->m_RoomId)){
        return;
    }
    //房间存在：获取房间成员id列表
    list<int> lst ;
    m_mapRoomidToIdList->find(rq->m_RoomId, lst);
    //遍历
    for(auto ite = lst.begin(); ite!=lst.end();){
        int userid = *ite;
        //判断id是否是退出者
        if(userid == rq->m_nUserId){
            //如果是退出者id：从房间列表移除
            ite = lst.erase(ite);
        }else{
            //如果是其他用户：如果在线，则转发退出信息
            if(m_mapIDToUserInfo->IsExist(userid)){
                UserInfo * info;
                m_mapIDToUserInfo->find(userid, info);
                m_tcp->SendData(info->m_sockfd, szbuf, nlen);
            }
            ite++;
        }
    }
    //列表成员数 == 0：移除该房间
    if(lst.size() == 0){
        m_mapRoomidToIdList->erase(rq->m_RoomId);
        return;
    }
    //列表成员数 > 0：更新房间成员列表
    m_mapRoomidToIdList->insert(rq->m_RoomId, lst);
}

//处理音频帧
void CLogic::AudioFrameRq(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_
    //拆包
    char * tmp = szbuf;
    tmp += sizeof (int);
    //获取userid
    int senderid = *(int*)tmp;
    tmp += sizeof (int);
    //获取房间id
    int roomid = *(int*)tmp;
    //看房间是否存在
    if(!m_mapRoomidToIdList->IsExist(roomid)) return;
    //获取房间成员列表
    list<int> lst;
    m_mapRoomidToIdList->find(roomid, lst);
    //循环
    for(auto ite = lst.begin(); ite!=lst.end();ite++){
        int userid = *ite;
        //不转发给sender
        if(userid == senderid) continue;
        //查看成员是否在线
        UserInfo * userinfo;
        if(!m_mapIDToUserInfo->find(userid, userinfo)) continue;
        //转发给 其他成员
        //m_tcp->SendData(userinfo->m_sockfd, szbuf, nlen);
        m_tcp->SendData(userinfo->m_audiofd, szbuf, nlen);
    }
}

//处理视频帧
void CLogic::VideoFrameRq(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_
    //拆包
    char * tmp = szbuf;
    tmp += sizeof (int);
    //获取userid
    int senderid = *(int*)tmp;
    tmp += sizeof (int);
    //获取房间id
    int roomid = *(int*)tmp;
    //看房间是否存在
    if(!m_mapRoomidToIdList->IsExist(roomid)) return;
    //获取房间成员列表
    list<int> lst;
    m_mapRoomidToIdList->find(roomid, lst);
    //循环
    for(auto ite = lst.begin(); ite!=lst.end();ite++){
        int userid = *ite;
        //不转发给sender
        if(userid == senderid) continue;
        //查看成员是否在线
        UserInfo * userinfo;
        if(!m_mapIDToUserInfo->find(userid, userinfo)) continue;
        //转发给 其他成员
        //m_tcp->SendData(userinfo->m_sockfd, szbuf, nlen);
        m_tcp->SendData(userinfo->m_videofd, szbuf, nlen);
    }
}

//音频注册
void CLogic::AudioRegister(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_
    //拆包
    STRU_AUDIO_REGISTER * rq = (STRU_AUDIO_REGISTER *)szbuf;
    int userid = rq->m_nUserId;
    //根据id找到userInfo节点更新
    UserInfo * info;
    if(m_mapIDToUserInfo->find(userid, info))
        info->m_audiofd = clientfd;
}
//视频注册
void CLogic::VideoRegister(sock_fd clientfd, char *szbuf, int nlen)
{
    _DEF_COUT_FUNC_
    //拆包
    STRU_VIDEO_REGISTER * rq = (STRU_VIDEO_REGISTER *)szbuf;
    int userid = rq->m_nUserId;
    //根据id找到userInfo节点更新
    UserInfo * info;
    if(m_mapIDToUserInfo->find(userid, info))
        info->m_videofd = clientfd;
}























