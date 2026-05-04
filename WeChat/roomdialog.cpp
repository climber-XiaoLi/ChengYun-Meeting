#include "roomdialog.h"
#include "ui_roomdialog.h"
#include<QMessageBox>

RoomDialog::RoomDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RoomDialog)
{
    ui->setupUi(this);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0,0,0,0);//上下左右间距
    m_mainLayout->setSpacing(5);              //控件间间距
    //设置一个垂直布局的画布，可以向画布里面添加控件
    ui->wdg_list->setLayout(m_mainLayout);

    //初始化音频
    m_pAudioRead = new AudioRead;
    connect(m_pAudioRead,SIGNAL(SIG_audioFrame(QByteArray)),
            this,SLOT(slot_audioFrame(QByteArray)));
    //初始化 主usershow
    m_imgSmile = QImage(":/bq/0.png");
    ui->wdg_userShow->slot_setImage(m_imgSmile);
    ui->wdg_userShow->slot_setInfo(0, "");
    //测试
    // for(int i=0;i<6;i++){
    //     UserShowWidget * user = new UserShowWidget;
    //     user->slot_setInfo(i+1, QString("测试%1").arg(i+1));
    //     slot_addUserShow(user);
    // }
}

RoomDialog::~RoomDialog()
{
    qDebug() << __func__;
    //回收音频资源
    if(m_pAudioRead){
        m_pAudioRead->pause();
        delete m_pAudioRead;m_pAudioRead = NULL;
    }
    //回收视频资源 todo

    delete ui;
}

//设置房间窗口信息
void RoomDialog::slot_setInfo(QString roomid)
{
    QString title = QString("房间号:%1").arg(roomid);
    setWindowTitle(title);
    ui->lb_title->setText(title);
}

//添加usershow
void RoomDialog::slot_addUserShow(UserShowWidget * user)
{
    user->setMaximumSize(240, 200);
    m_mainLayout->addWidget(user);
    m_mapIDToUserShow[user->m_id] = user;
    //连接
    connect(user,SIGNAL(SIG_itemClicked(int,QString)),
            this,SLOT(slot_setMainUsershow(int,QString)));
}

//移除usershow
void RoomDialog::slot_removeUserShow(UserShowWidget *user)
{
    user->hide();
    m_mainLayout->removeWidget(user);
    m_mapIDToUserShow.erase(user->m_id);
    // 取消连接
    disconnect(user, SIGNAL(SIG_itemClicked(int, QString)),
               this, SLOT(slot_setMainUsershow(int, QString)));
}
//移除usershow
void RoomDialog::slot_removeUserShow(int id)
{
    if(m_mapIDToUserShow.count(id) > 0){
        UserShowWidget * user = m_mapIDToUserShow[id];
        slot_removeUserShow(user);
    }
}

//清空usershow
void RoomDialog::slot_clearUserShow()
{
    for(auto ite = m_mapIDToUserShow.begin(); ite != m_mapIDToUserShow.end(); ++ite){
        slot_removeUserShow(ite->second);
    }
}
//
void RoomDialog::slot_audioFrame(QByteArray ba)
{
    Q_EMIT SIG_audioFrame(ba);
}

//重绘usershow
void RoomDialog::slot_refreshUserShow(int id, QImage &img)
{
    //刷新预览图
    if(ui->wdg_userShow->m_id == id){
        ui->wdg_userShow->slot_setImage(img);
    }
    if(m_mapIDToUserShow.count(id) > 0){
        UserShowWidget * user = m_mapIDToUserShow[id];
        user->slot_setImage(img);
    }
}
//点击放大：设置左侧主usershow控件的信息
void RoomDialog::slot_setMainUsershow(int id, QString name)
{
    if(ui->wdg_userShow->m_id == id){
        ui->wdg_userShow->slot_setImage(m_imgSmile);
        ui->wdg_userShow->slot_setInfo(0, "");
        return;
    }
    ui->wdg_userShow->slot_setInfo(id, name);
}

//退出房间
void RoomDialog::on_pb_close_clicked()
{
    this->close();//触发closeEvent
}

//退出房间
void RoomDialog::on_pb_quit_clicked()
{
    this->close();//触发closeEvent
}

//关闭事件
void RoomDialog::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this,"提示","是否退出会议？") == QMessageBox::Yes){
        //发送 退出房间信号
        Q_EMIT SIG_close();
        event->accept();

        //关闭音频
        m_pAudioRead->pause();
        ui->cb_audio->setCheckState(Qt::Unchecked);
        qDebug() << "关闭麦克风，停止音频采集";
        //关闭视频
        ui->cb_video->setCheckState(Qt::Unchecked);
        qDebug() << "关闭摄像头，停止视频采集";
        //关闭视频
        ui->cb_desk->setCheckState(Qt::Unchecked);
        qDebug() << "关闭桌面共享，停止采集";
        //刷新左侧主usershow
        ui->wdg_userShow->slot_setImage(m_imgSmile);
        ui->wdg_userShow->slot_setInfo(0, "");
        //退出全屏
        this->showNormal();
        m_isFullScreen = false;
        //关闭特效
        ui->cbb_special->setCurrentIndex(0);
        return;
    }
    event->ignore();
}

//打开和关闭 音频
void RoomDialog::on_cb_audio_checkStateChanged(const Qt::CheckState &arg1)
{
    // 控制音频采集
    if (arg1 == Qt::Checked) {
        m_pAudioRead->start();
        qDebug() << "麦克风开启，实时播放采集的音频";
    } else {
        m_pAudioRead->pause();
        qDebug() << "麦克风关闭，停止音频采集和播放";
    }
}

//打开和关闭 视频
void RoomDialog::on_cb_video_checkStateChanged(const Qt::CheckState &arg1)
{
    // 控制视频采集
    if (arg1 == Qt::Checked) {
        //关闭桌面采集
        ui->cb_desk->setCheckState(Qt::Unchecked);

        Q_EMIT SIG_videoStart();
        qDebug() << "摄像头开启，实时采集画面";
    } else {
        Q_EMIT SIG_videoPause();
        qDebug() << "摄像头关闭，停止视频采集";
    }
}

//打开和关闭 共享桌面
void RoomDialog::on_cb_desk_checkStateChanged(const Qt::CheckState &arg1)
{
    // 控制桌面采集
    if (arg1 == Qt::Checked) {
        //关闭视频采集
        ui->cb_video->setCheckState(Qt::Unchecked);

        Q_EMIT SIG_screenStart();
        qDebug() << "共享桌面开启，实时采集画面";
    } else {
        Q_EMIT SIG_screenPause();
        qDebug() << "共享桌面关闭，停止视频采集";
    }
}

//全屏
void RoomDialog::on_pb_max_clicked()
{
    if (!m_isFullScreen) {
        // 切换为全屏模式
        this->showFullScreen(); // 核心API：全屏显示窗口
        m_isFullScreen = true;
        qDebug() << "房间界面已全屏";
    } else {
        // 退出全屏，恢复正常大小
        this->showNormal(); // 核心API：恢复正常窗口
        m_isFullScreen = false;
        qDebug() << "房间界面已退出全屏";
    }
}

//最小化
void RoomDialog::on_pb_min_clicked()
{
    // 核心API：将窗口最小化到任务栏
    this->showMinimized();
    qDebug() << "房间界面已最小化到任务栏";
}

//切换特效
void RoomDialog::on_cbb_special_currentIndexChanged(int index)
{
    Q_EMIT SIG_setMoji(index);
}

