#include "ckernel.h"
#include"qDebug"
#include<QMessageBox>
#include<QTime>

//设置协议映射关系
#define NetPackMap(a) m_netPackMap[a - DEF_PACK_BASE]
void Ckernel::setNetPackMap()
{
    memset(m_netPackMap,0,sizeof(m_netPackMap));
    //m_netPackMap[DEF_PACK_LOGIN_RS - DEF_PACK_BASE] = &Ckernel::slot_dealLoginRs;
    NetPackMap(DEF_PACK_LOGIN_RS)      = &Ckernel::slot_dealLoginRs;
    NetPackMap(DEF_PACK_REGISTER_RS)   = &Ckernel::slot_dealRegisterRs;
    NetPackMap(DEF_PACK_CREATEROOM_RS) = &Ckernel::slot_dealCreateRoomRs;
    NetPackMap(DEF_PACK_JOINROOM_RS)   = &Ckernel::slot_dealJoinRoomRs;
    NetPackMap(DEF_PACK_ROOM_MEMBER)   = &Ckernel::slot_dealRoomMemberRq;
    NetPackMap(DEF_PACK_LEAVEROOM_RQ)  = &Ckernel::slot_dealLeaveRoomRq;
    NetPackMap(DEF_PACK_AUDIO_FRAME)   = &Ckernel::slot_dealAudioFrameRq;
    NetPackMap(DEF_PACK_VIDEO_FRAME)   = &Ckernel::slot_dealVideoFrameRq;
}
#include<QSettings>
#include<QApplication>
#include<QFileInfo>
//初始化配置
void Ckernel::initConfig()
{
    m_serverIP = DEF_SERVERIP;
    //路径设置，exe同级目录下->applicationDirPath  config.ini
    QString path = QApplication::applicationDirPath() + "/config.ini";
    //判断是否存在
    QFileInfo info(path);
    QSettings settings(path, QSettings::IniFormat, NULL);//有打开 没有创建
    if(info.exists()){
        //加载配置文件 ip设置为配置文件里面的ip
        //移动到Net组
        settings.beginGroup("Net");
        //读取 ip->addr->赋值
        QVariant ip = settings.value("ip");
        QString strIP = ip.toString();
        //结束
        settings.endGroup();
        if(!strIP.isEmpty()){
            m_serverIP = strIP;
        }
    }else{
        //没有配置文件，写入默认的
        settings.beginGroup("Net");
        settings.setValue("ip", m_serverIP);
        settings.endGroup();
    }
    qDebug() << m_serverIP;
}

Ckernel::Ckernel(QObject *parent)
    : QObject{parent},m_id(0),m_roomid(0)
{
    qDebug()<< "主线程ID:" << QThread::currentThreadId();//打印主线程id
    setNetPackMap();
    initConfig();

    //初始化主窗口
    m_pWeChatDlg = new WeChatDialog;
    connect(m_pWeChatDlg,SIGNAL(SIG_close()),
            this,SLOT(slot_destroy()));
    connect(m_pWeChatDlg,SIGNAL(SIG_createRoom()),
            this,SLOT(slot_createRoom()));
    connect(m_pWeChatDlg,SIGNAL(SIG_joinRoom()),
            this,SLOT(slot_joinRoom()));
    //m_pWeChatDlg->show();

    //初始化登录窗口
    m_pLoginDlg = new LoginDialog;
    connect(m_pLoginDlg, SIGNAL(SIG_close()),
            this, SLOT(slot_destroy()));
    connect(m_pLoginDlg, SIGNAL(SIG_loginCommit(QString,QString)),
            this, SLOT(slot_loginCommit(QString,QString)));
    connect(m_pLoginDlg, SIGNAL(SIG_registerCommit(QString,QString,QString)),
            this, SLOT(slot_registerCommit(QString,QString,QString)));
    m_pLoginDlg->show();

    //初始化房间窗口
    m_pRoomDlg = new RoomDialog;
    connect(m_pRoomDlg,SIGNAL(SIG_close()),
            this,SLOT(slot_quitRoom()));
    //直接连接到m_pRoomDlg的m_pAudioRead的信号
    connect(m_pRoomDlg,SIGNAL(SIG_audioFrame(QByteArray)),
            this,SLOT(slot_audioFrame(QByteArray)));
    connect(m_pRoomDlg,SIGNAL(SIG_videoStart()),
            this,SLOT(slot_startVideo()));
    connect(m_pRoomDlg,SIGNAL(SIG_videoPause()),
            this,SLOT(slot_pauseVideo()));
    connect(m_pRoomDlg,SIGNAL(SIG_screenStart()),
            this,SLOT(slot_startScreen()));
    connect(m_pRoomDlg,SIGNAL(SIG_screenPause()),
            this,SLOT(slot_pauseScreen()));

    //初始化视频输入对象
    m_pVideoRead = new VideoRead;
    connect(m_pVideoRead,SIGNAL(SIG_sendVideoFrame(QImage)),
            this,SLOT(slot_sendVideoFrame(QImage)));
    connect(m_pRoomDlg,SIGNAL(SIG_setMoji(int)),
            m_pVideoRead,SLOT(slots_setMoji(int)));
    //初始化屏幕采集对象
    m_pScreenRead = new ScreenRead;
    connect(m_pScreenRead,SIGNAL(SIG_sendScreenFrame(QImage)),
            this,SLOT(slot_sendVideoFrame(QImage)));

    //添加网络
    m_pClient = new TcpClientMediator;
    m_pClient->OpenNet(m_serverIP.toStdString().c_str(), DEF_PORT);
    connect(m_pClient, SIGNAL(SIG_ReadyData(uint,char*,int)),
            this, SLOT(slot_dealData(uint,char*,int)));
    //初始化 音频和视频TCP连接
    for(int i =0;i<2;i++){
        m_pAVClient[i] = new TcpClientMediator;
        m_pAVClient[i]->OpenNet(m_serverIP.toStdString().c_str(), DEF_PORT);
        connect(m_pAVClient[i], SIGNAL(SIG_ReadyData(uint,char*,int)),
                this, SLOT(slot_dealData(uint,char*,int)));
    }

    //初始化 发送视频帧线程
    m_pSendVideoWorker = QSharedPointer<SendVideoWorker>(new SendVideoWorker);
    connect(this,SIGNAL(SIG_SendVideo(char*,int)),
            m_pSendVideoWorker.data(),SLOT(slot_sendVideo(char*,int)));
    connect(this,SIGNAL(SIG_SendVideo(QImage)),
            m_pSendVideoWorker.data(),SLOT(slot_sendVideo(QImage)));
}

//回收
void Ckernel::slot_destroy()
{
    qDebug() << __func__;
    if(m_pWeChatDlg){
        m_pWeChatDlg->hide();
        delete m_pWeChatDlg; m_pWeChatDlg = NULL;
    }
    if(m_pLoginDlg){
        m_pLoginDlg->hide();
        delete m_pLoginDlg; m_pLoginDlg = NULL;
    }
    if(m_pRoomDlg){
        m_pRoomDlg->hide();
        delete m_pRoomDlg; m_pRoomDlg = NULL;
    }
    if(m_pClient){
        m_pClient->CloseNet();
        delete m_pClient; m_pClient = NULL;
    }
    //todo
    exit(0);
}

//开启视频
void Ckernel::slot_startVideo()
{
    m_pVideoRead->slots_openVideo();
}
//关闭视频
void Ckernel::slot_pauseVideo()
{
    m_pVideoRead->slots_closeVideo();
}
//开启桌面共享
void Ckernel::slot_startScreen()
{
    m_pScreenRead->slots_openVideo();
}
//开启桌面共享
void Ckernel::slot_pauseScreen()
{
    m_pScreenRead->slots_closeVideo();
}

//提交登录信息
void Ckernel::slot_loginCommit(QString tel, QString pass)
{
    std::string strTel =tel.toStdString();
    std::string strPass = pass.toStdString();

    STRU_LOGIN_RQ rq;
    strcpy(rq.m_tel, strTel.c_str());
    strcpy(rq.m_password, strPass.c_str());

    m_pClient->SendData(0/*给服务器发*/, (char*)&rq, sizeof(rq));
}

//提交注册信息
void Ckernel::slot_registerCommit(QString tel, QString pass, QString name)
{
    std::string strTel =tel.toStdString();
    std::string strPass = pass.toStdString();
    std::string strName = name.toStdString();// 格式 utf8

    STRU_REGISTER_RQ rq;
    strcpy(rq.m_tel, strTel.c_str());
    strcpy(rq.m_password, strPass.c_str());
    //兼容中文 utf8 QString --> std::string --> char*
    strcpy(rq.m_name, strName.c_str());

    m_pClient->SendData(0/*给服务器发*/, (char*)&rq, sizeof(rq));
}

//发送 创建房间 请求
void Ckernel::slot_createRoom()
{
    //判断是否在房间内
    if(m_roomid != 0){
        QMessageBox::about(m_pWeChatDlg,"提示","已经在房间内，无法创建，先退出");
        return;
    }
    //发命令 创建房间
    STRU_CREATEROOM_RQ rq;
    rq.m_UserID = m_id;

    m_pClient->SendData(0, (char*)&rq, sizeof(rq));
}

#include<QInputDialog>
#include<QRegularExpression>
//发送 加入房间 请求
void Ckernel::slot_joinRoom()
{
    //判断是否在房间内
    if(m_roomid != 0){
        QMessageBox::about(m_pWeChatDlg,"提示","已经在房间内，无法加入，先退出");
        return;
    }
    //弹出窗口 填房间号
    QString strRoom = QInputDialog::getText(m_pWeChatDlg, "加入房间", "输入房间号");
    //合理化判断
    QRegularExpression reg("^[0-9]{1,8}$");
    if(!reg.match(strRoom).hasMatch()){
        QMessageBox::about(m_pWeChatDlg,"提示","房间号输入不合法，长度不超过8位");
        return;
    }
    qDebug()<< strRoom;
    //发命令 加入房间
    STRU_JOINROOM_RQ rq;
    rq.m_UserID = m_id;
    rq.m_RoomID = strRoom.toInt();

    m_pClient->SendData(0, (char*)&rq, sizeof(rq));
}

//发送退出房间
void Ckernel::slot_quitRoom()
{
    //发送
    STRU_LEAVEROOM_RQ rq;
    rq.m_nUserId = m_id;
    rq.m_RoomId = m_roomid;
    strcpy(rq.szUserName, m_name.toStdString().c_str());

    m_pClient->SendData(0, (char*)&rq, sizeof(rq));
    //关闭视频 音频 todo
    m_pVideoRead->slots_closeVideo();
    m_pScreenRead->slots_closeVideo();

    //回收所有人的 音频播放对象
    for(auto ite = m_mapIDToAudioWrite.begin(); ite != m_mapIDToAudioWrite.end();){
        AudioWrite * aw = ite->second;
        ite = m_mapIDToAudioWrite.erase(ite);
        delete aw;
    }
    //回收资源
    m_pRoomDlg->slot_clearUserShow();
    m_roomid = 0;
}

//发送音频帧
void Ckernel::slot_audioFrame(QByteArray ba)
{
    qDebug()<< "sendAudio";
    //打包
    int nPackSize = 6*sizeof(int) + ba.size();
    char * buf = new char[nPackSize];
    char * tmp = buf;
    QTime tm = QTime::currentTime();
    //序列化
    *(int*)tmp = DEF_PACK_AUDIO_FRAME;
    tmp += sizeof(int);
    *(int*)tmp = m_id;
    tmp += sizeof(int);
    *(int*)tmp = m_roomid;
    tmp += sizeof(int);
    *(int*)tmp = tm.minute();
    tmp += sizeof(int);
    *(int*)tmp = tm.second();
    tmp += sizeof(int);
    *(int*)tmp = tm.msec();
    tmp += sizeof(int);
    memcpy(tmp, ba.data(), ba.size());

    m_pAVClient[audio_client]->SendData(0, buf, nPackSize);
    delete []buf;
}

//发送视频帧-----JEPG压缩
#include<QBuffer>
void Ckernel::slot_sendVideoFrame(QImage img)
{
    //刷新Room内自己的video画面
    m_pRoomDlg->slot_refreshUserShow(m_id, img);

    // ========== 1. 打印压缩前的视频帧大小（Qt6 正确API） ==========
    qsizetype sizeBefore = img.sizeInBytes();
    double sizeBeforeKB = static_cast<double>(sizeBefore) / 1024.0;
    qDebug() << "【视频帧压缩前】原始大小：" << sizeBefore << "字节 ("
             << QString::number(sizeBeforeKB, 'f', 2) << " KB)";

    //压缩 为"JEPG"格式
    QByteArray ba;
    QBuffer qbuf(&ba);
    bool compressOk = img.save(&qbuf, "JPEG", 60);
    // 校验压缩结果
    if(!compressOk || ba.isEmpty()){
        qWarning() << "JPEG 压缩失败，数据为空";
        return;
    }

    // ========== 2. 打印压缩后的视频帧大小 ==========
    qsizetype sizeAfter = ba.size();
    double sizeAfterKB = static_cast<double>(sizeAfter) / 1024.0;
    double compressRatio = 0.0;
    if (sizeBefore > 0) {
        compressRatio = (1 - static_cast<double>(sizeAfter)/sizeBefore) * 100;
    }
    qDebug() << "【视频帧压缩后】JPEG 大小：" << sizeAfter << "字节 ("
             << QString::number(sizeAfterKB, 'f', 2) << " KB)";
    qDebug() << "【压缩效果】压缩率：" << QString::number(compressRatio, 'f', 2) << "% "
             << "(节省了" << QString::number((sizeBefore - sizeAfter)/1024.0, 'f', 2) << " KB)";

    //打包视频帧
    int nPackSize = 6*sizeof(int) + ba.size();
    char * buf = new char[nPackSize];
    if(!buf){ // 内存分配失败处理
        qWarning() << "内存分配失败，无法打包视频帧";
        return;
    }
    char * tmp = buf;
    QTime tm = QTime::currentTime();
    // 序列化（严格按顺序写入，避免重复写入）
    *(int*)tmp = DEF_PACK_VIDEO_FRAME; tmp += sizeof(int);
    *(int*)tmp = m_id;                 tmp += sizeof(int);
    *(int*)tmp = m_roomid;             tmp += sizeof(int);
    *(int*)tmp = tm.minute();          tmp += sizeof(int);
    *(int*)tmp = tm.second();          tmp += sizeof(int);
    *(int*)tmp = tm.msec();            tmp += sizeof(int);
    memcpy(tmp, ba.data(), ba.size());

    //将视频发送变为一个信号，放到另一个线程m_pSendVideoWorker执行
    // m_pClient->SendData(0, buf, nPackSize);
    // delete []buf;
     Q_EMIT SIG_SendVideo(buf, nPackSize);
    //Q_EMIT SIG_SendVideo(img);
}
//多线程 -- 发送视频帧
void Ckernel::slot_SendVideo_thread(char *buf, int nlen)
{
    qDebug()<< "slot_SendVideo_thread:" << QThread::currentThreadId();//线程id
    //压缩也在这里做todo
    //
    char * tmp = buf;
    tmp += sizeof(int);
    tmp += sizeof(int);
    tmp += sizeof(int);
    int min = *(int*)tmp; tmp += sizeof(int);
    int sec = *(int*)tmp; tmp += sizeof(int);
    int msec = *(int*)tmp; tmp += sizeof(int);
    //当前时间
    QTime nowtm = QTime::currentTime();
    //数据包生成时间
    QTime tm(nowtm.hour(),min,sec,msec);
    //延迟超过300ms：舍弃数据报
    if(tm.msecsTo(nowtm) > 100){
        qDebug() << "over 100ms send fail-----------------------------------------------------------";
        delete []buf;
        return;
    }
    m_pAVClient[video_client]->SendData(0, buf, nlen);
    delete []buf;
}

//多线程 -- 压缩 发送视频帧
void Ckernel::slot_SendVideo_thread(QImage img)
{
    qDebug()<< "slot_SendVideo_thread:" << QThread::currentThreadId();//线程id
    //压缩 为"JEPG"格式
    QByteArray ba;
    QBuffer qbuf(&ba);
    img.save(&qbuf, "JPEG", 60);
    //打包
    int nPackSize = 6*sizeof(int) + ba.size();
    char * buf = new char[nPackSize];
    char * tmp = buf;
    QTime tm = QTime::currentTime();
    //序列化
    *(int*)tmp = DEF_PACK_VIDEO_FRAME;
    tmp += sizeof(int);
    *(int*)tmp = m_id;
    tmp += sizeof(int);
    *(int*)tmp = m_roomid;
    tmp += sizeof(int);
    *(int*)tmp = tm.minute();
    tmp += sizeof(int);
    *(int*)tmp = tm.second();
    tmp += sizeof(int);
    *(int*)tmp = tm.msec();
    tmp += sizeof(int);
    memcpy(tmp, ba.data(), ba.size());

    m_pClient->SendData(0, buf, nPackSize);
    delete []buf;
}

//处理网络数据
void Ckernel::slot_dealData(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //获取数据包协议
    int type =*(int*)buf;
    //判断协议类型是否合法
    if(type >= DEF_PACK_BASE && type < DEF_PACK_BASE + DEF_PACK_COUNT){
        //取得协议头，根据协议映射关系，执行对应函数指针
        PFUN pf = NetPackMap(type);
        if(pf){
            (this->*pf)(sock, buf, nlen);
        }
    }
    delete[] buf;//回收！
}

//处理登陆回复
void Ckernel::slot_dealLoginRs(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    STRU_LOGIN_RS * rs = (STRU_LOGIN_RS*)buf;
    //根据不同结果 ，得到不同信息
    switch(rs->m_lResult){
    case user_not_exist:
        QMessageBox::about(m_pLoginDlg,"提示","手机号不存在，登录失败");
        break;
    case password_error:
        QMessageBox::about(m_pLoginDlg,"提示","密码错误，登录失败");
        break;
    case login_success:
        {
            QString strName = QString("用户[%1]登录成功！").arg(rs->m_name);
            QMessageBox::about(m_pLoginDlg,"提示",strName);
            //id记录
            m_name = QString::fromStdString(rs->m_name);
            m_pWeChatDlg->setInfo(rs->m_name);
            m_id = rs->m_userid;
            //ui跳转
            m_pLoginDlg->hide();
            m_pWeChatDlg->showNormal();
            //注册 音频和视频
            STRU_AUDIO_REGISTER rq_audio;
            STRU_VIDEO_REGISTER rq_video;
            rq_audio.m_nUserId = m_id;
            rq_video.m_nUserId = m_id;
            m_pAVClient[audio_client]->SendData(0, (char*)&rq_audio, sizeof(rq_audio));
            m_pAVClient[video_client]->SendData(0, (char*)&rq_video, sizeof(rq_video));
        }
        break;
    default:break;
    }
}

//处理注册回复
void Ckernel::slot_dealRegisterRs(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    STRU_REGISTER_RS * rs = (STRU_REGISTER_RS*)buf;
    //根据不同结果 弹出不同提示框
    switch(rs->result){
    case tel_is_exist:
        QMessageBox::about(m_pLoginDlg,"提示","手机号已存在，注册失败");
        break;
    case register_success:
        QMessageBox::about(m_pLoginDlg,"提示","注册成功");
        break;
    case name_is_exist:
        QMessageBox::about(m_pLoginDlg,"提示","昵称已存在，注册失败");
        break;
    default:break;
    }
}

//处理创建房间回复
void Ckernel::slot_dealCreateRoomRs(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    STRU_CREATEROOM_RS * rs = (STRU_CREATEROOM_RS*)buf;
    //显示房间界面
    m_roomid = rs->m_RoomId;
    //创建自己的usershow，放入房间
    UserShowWidget * user = new UserShowWidget;
    user->slot_setInfo(m_id, m_name);
    QImage img = QImage(":/bq/0.png");
    user->slot_setImage(img);
    m_pRoomDlg->slot_addUserShow(user);
    //设置房间信息
    m_pRoomDlg->slot_setInfo(QString::number(rs->m_RoomId));
    //m_pRoomDlg->slot_refreshUserShow(0, img);
    m_pRoomDlg->showNormal();
}

//处理加入房间回复
void Ckernel::slot_dealJoinRoomRs(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    STRU_JOINROOM_RS * rs = (STRU_JOINROOM_RS*)buf;
    //加入失败：退出
    if(rs->m_lResult == 0){
        QMessageBox::about(m_pWeChatDlg,"提示","加入房间失败，房间id不存在");
        return;
    }
    //加入成功：
    //创建自己的usershow控件，放入房间
    UserShowWidget * user = new UserShowWidget;
    user->slot_setInfo(m_id, m_name);
    QImage img = QImage(":/bq/0.png");
    user->slot_setImage(img);
    m_pRoomDlg->slot_addUserShow(user);
    //设置房间信息
    m_pRoomDlg->slot_setInfo(QString::number(rs->m_RoomID));
    //m_pRoomDlg->slot_refreshUserShow(0, img);
    m_roomid = rs->m_RoomID;
    //跳转
    m_pRoomDlg->showNormal();
}

//处理房间成员请求
void Ckernel::slot_dealRoomMemberRq(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    STRU_ROOM_MEMBER_RQ * rq = (STRU_ROOM_MEMBER_RQ*)buf;
    //创建用户对应的UserShow控件, 放入房间
    UserShowWidget * user = new UserShowWidget;
    user->slot_setInfo(rq->m_UserID, QString::fromStdString(rq->m_UserName));
    QImage img = QImage(":/bq/0.png");
    user->slot_setImage(img);
    m_pRoomDlg->slot_addUserShow(user);
    //创建用户对应的音频播放对象，放入m_mapIDToAudioWrite
    if(m_mapIDToAudioWrite.count(rq->m_UserID) == 0){
        AudioWrite * aw = new AudioWrite;           //同一台电脑第二用户加入房间，卡顿原因：有申请了一个音频输出对象，占用电脑播放器
        m_mapIDToAudioWrite[rq->m_UserID] = aw;
    }
    //视频 todo

}

//处理退出房间
void Ckernel::slot_dealLeaveRoomRq(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    STRU_LEAVEROOM_RQ * rq = (STRU_LEAVEROOM_RQ*)buf;
    //移除 退出人的usershow控件
    if(rq->m_RoomId == m_roomid){
        m_pRoomDlg->slot_removeUserShow(rq->m_nUserId);
    }
    //移除 退出人的音频播放对象
    if(m_mapIDToAudioWrite.count(rq->m_nUserId) > 0){
        AudioWrite * aw = m_mapIDToAudioWrite[rq->m_nUserId];
        delete aw;
        m_mapIDToAudioWrite.erase(rq->m_nUserId);
    }
}

//处理音频帧
void Ckernel::slot_dealAudioFrameRq(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    //反序列化
    char * tmp = buf;
    tmp += sizeof(int);
    int userid = *(int*)tmp;
    tmp += sizeof(int);
    int roomid = *(int*)tmp;
    tmp += sizeof(int);
    //跳过时间
    tmp += sizeof(int);
    tmp += sizeof(int);
    tmp += sizeof(int);
    int nFrameLen = nlen - 6*sizeof(int);
    //获取音频帧
    QByteArray ba(tmp, nFrameLen);
    //找到 ID 对应的 音频输出对象， 播放
    if(roomid == m_roomid){
        if(m_mapIDToAudioWrite.count(userid) > 0){
            AudioWrite * aw = m_mapIDToAudioWrite[userid];
            aw->slot_playAudio(ba);
        }
    }

}

//处理视频帧
void Ckernel::slot_dealVideoFrameRq(uint sock, char *buf, int nlen)
{
    qDebug() << __func__;
    //拆包
    //反序列化
    char * tmp = buf;
    tmp += sizeof(int);
    int userid = *(int*)tmp;
    tmp += sizeof(int);
    int roomid = *(int*)tmp;
    tmp += sizeof(int);
    //跳过时间
    tmp += sizeof(int);
    tmp += sizeof(int);
    tmp += sizeof(int);
     //获取视频帧
    int nFrameLen = nlen - 6*sizeof(int);
    QByteArray ba(tmp, nFrameLen);
    QImage img;
    img.loadFromData(ba);
    //img.loadFromData((const uchar*)tmp, nFrameLen);
    //刷新房间内ID对应usershow的画面
    if(roomid == m_roomid){
        m_pRoomDlg->slot_refreshUserShow(userid, img);
    }
}













