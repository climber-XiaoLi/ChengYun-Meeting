#ifndef USERSHOWWIDGET_H
#define USERSHOWWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include<QImage>
#include<QMouseEvent>
#include<QTimer>
#include<QTime>
//#include"roomdialog.h"

namespace Ui {
class UserShowWidget;
}

class UserShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserShowWidget(QWidget *parent = nullptr);
    ~UserShowWidget();
signals:
    void SIG_itemClicked(int id, QString name);

public slots:
    //设置usershow信息
    void slot_setInfo(int id, QString name);
    //绘图事件
    void paintEvent(QPaintEvent * event);
    //鼠标点击事件
    void mousePressEvent(QMouseEvent * event);
    //设置m_img，并触发重绘
    void slot_setImage(QImage &img);
    //检测
    void slot_checkTimer();
private:
    Ui::UserShowWidget *ui;
    int m_id;
    QString m_userName;

    QImage m_img;
    QImage m_defaultImg;
    friend class RoomDialog;

    QTimer m_timer;
    QTime m_lastTime;
};

#endif // USERSHOWWIDGET_H
