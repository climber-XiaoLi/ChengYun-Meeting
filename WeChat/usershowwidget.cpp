#include "usershowwidget.h"
#include "ui_usershowwidget.h"
#include<QPainter>

UserShowWidget::UserShowWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserShowWidget)
{
    ui->setupUi(this);
    m_id = 0;
    connect(&m_timer,SIGNAL(timeout()),
            this,SLOT(slot_checkTimer()));
    m_defaultImg.load(":/bq/0.png");
    m_lastTime = QTime::currentTime();
}

UserShowWidget::~UserShowWidget()
{
    delete ui;
}

//设置usershow信息
void UserShowWidget::slot_setInfo(int id, QString name)
{
    m_id = id;
    m_userName = name;
    QString text = QString("用户名：%1").arg(m_userName);
    ui->lb_name->setText( text );
}

//重绘事件
void UserShowWidget::paintEvent(QPaintEvent *event)
{
    //
    QPainter painter(this);
    //画黑背景
    painter.setBrush(Qt::gray);//设置黑色画刷
    painter.drawRect(0,0, this->width(),this->height());
    //画视频帧
    //画图片
    if( m_img.size().height() <= 0 ) return;

    // 计算可用区域（排除名称标签高度）
    int availableWidth = width();
    int availableHeight = height() - ui->lb_name->height();
    //图片缩放scaled（保持原比例4:3 、16:9） QImage --> QPixmap
    // QPixmap pixmap = QPixmap::fromImage( m_img.scaled( QSize( this->width() ,
    //                                                          this->height() - ui->lb_name->height()), Qt::KeepAspectRatio ));
    QPixmap pixmap = QPixmap::fromImage(
        m_img.scaled(availableWidth, availableHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation)
        );
    qDebug() << "可用显示区域：" <<this->width() << "×" << this->height() - ui->lb_name->height();
    qDebug() << "缩放后图片尺寸：" << pixmap.size();

    // 正确计算居中坐标
    int x = (availableWidth - pixmap.width()) / 2;
    int y = ui->lb_name->height() + (availableHeight - pixmap.height()) / 2;
    qDebug() << "绘制坐标(x,y)：" << x << "," << y;

    //painter.drawPixmap( QPoint(x,y) , pixmap);
    // // 5. 绘制图片（指定源/目标矩形，避免裁剪）
    painter.drawPixmap(
        QRect(x, y, pixmap.width(), pixmap.height()),
        pixmap
        //QRect(0, 0, pixmap.width(), pixmap.height())
        );

    // // ========== 调试辅助：绘制边框（可选，验证位置） ==========
    // painter.setPen(Qt::red);
    // painter.drawRect(x, y, pixmap.width(), pixmap.height()); // 图片边框
    // painter.setPen(Qt::blue);
    // painter.drawRect(0, 0, this->width(), this->height());   // 控件边框

    painter.end();

}

//鼠标点击事件
void UserShowWidget::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    Q_EMIT SIG_itemClicked(m_id, m_userName);
}

void UserShowWidget::slot_setImage(QImage &img)
{
    m_img = img;
    //每次记录上次更新时间
    m_lastTime = QTime::currentTime();
    //触发重绘
    this->update();
    //
    m_timer.start(1000);
}

//超时未获得画面
void UserShowWidget::slot_checkTimer()
{
    //如果1s内无画面传输，则设为默认画面
    if(m_lastTime.secsTo(QTime::currentTime()) > 2){
        slot_setImage(m_defaultImg);
        m_timer.stop();
    }
}





