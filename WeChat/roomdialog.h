#ifndef ROOMDIALOG_H
#define ROOMDIALOG_H

#include <QDialog>
#include<QVBoxLayout>
#include"usershowwidget.h"
#include"audioread.h"
#include"audiowrite.h"

namespace Ui {
class RoomDialog;
}

class RoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoomDialog(QWidget *parent = nullptr);
    ~RoomDialog();
signals:
    void SIG_close();
    void SIG_audioFrame(QByteArray ba);
    //开启视频
    void SIG_videoStart();
    //关闭视频
    void SIG_videoPause();
    //开启桌面
    void SIG_screenStart();
    //关闭桌面
    void SIG_screenPause();
    //设置特效类型
    void SIG_setMoji(int newMoji);

public slots:
    //设置房间信息
    void slot_setInfo(QString roomid);
    //添加usershow控件
    void slot_addUserShow(UserShowWidget * user);
    //移除
    void slot_removeUserShow(UserShowWidget * user);
    void slot_removeUserShow(int id);
    //清空
    void slot_clearUserShow();
    //向kernal发送SIG_audioFrame
    void slot_audioFrame(QByteArray ba);
    //重绘usershow
    void slot_refreshUserShow(int id, QImage &img);
    //设置左侧主usershow控件
    void slot_setMainUsershow(int id, QString name);
private slots:
    void on_pb_close_clicked();

    void on_pb_quit_clicked();

    void closeEvent(QCloseEvent * event);

    void on_cb_audio_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_video_checkStateChanged(const Qt::CheckState &arg1);

    void on_cb_desk_checkStateChanged(const Qt::CheckState &arg1);
private slots:
    //全屏
    void on_pb_max_clicked();
    //最小化
    void on_pb_min_clicked();

    void on_cbb_special_currentIndexChanged(int index);

private:
    Ui::RoomDialog *ui;

    QVBoxLayout * m_mainLayout;
    //map记录房间内成员 id --> usershow映射
    std::map<int, UserShowWidget *> m_mapIDToUserShow;

    ///音频 一个采集 多个播放
    AudioRead * m_pAudioRead;

    bool m_isFullScreen = false; // 记录全屏状态
    QImage m_imgSmile;
};

#endif // ROOMDIALOG_H
