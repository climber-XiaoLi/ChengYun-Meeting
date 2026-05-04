/********************************************************************************
** Form generated from reading UI file 'wechatdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WECHATDIALOG_H
#define UI_WECHATDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeChatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_content;
    QPushButton *pb_icon;
    QLabel *lb_name;
    QPushButton *pb_set;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *pb_join;
    QToolButton *pb_create;
    QToolButton *pb_tool3;

    void setupUi(QDialog *WeChatDialog)
    {
        if (WeChatDialog->objectName().isEmpty())
            WeChatDialog->setObjectName("WeChatDialog");
        WeChatDialog->resize(450, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        WeChatDialog->setFont(font);
        verticalLayout = new QVBoxLayout(WeChatDialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_content = new QWidget(WeChatDialog);
        wdg_content->setObjectName("wdg_content");
        wdg_content->setAutoFillBackground(false);
        wdg_content->setStyleSheet(QString::fromUtf8("background-color: rgb(54, 54, 54);\n"
"color: rgb(255, 255, 255);"));
        pb_icon = new QPushButton(wdg_content);
        pb_icon->setObjectName("pb_icon");
        pb_icon->setGeometry(QRect(20, 10, 60, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tx/5.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(60, 60));
        pb_icon->setFlat(true);
        lb_name = new QLabel(wdg_content);
        lb_name->setObjectName("lb_name");
        lb_name->setGeometry(QRect(100, 30, 271, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(12);
        font1.setBold(false);
        lb_name->setFont(font1);
        pb_set = new QPushButton(wdg_content);
        pb_set->setObjectName("pb_set");
        pb_set->setGeometry(QRect(400, 30, 30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/sett.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pb_set->setIcon(icon1);
        pb_set->setIconSize(QSize(30, 30));
        pb_set->setFlat(true);
        scrollArea = new QScrollArea(wdg_content);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 160, 450, 441));
        scrollArea->setFrameShape(QFrame::Shape::Box);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 446, 437));
        scrollArea->setWidget(scrollAreaWidgetContents);
        widget = new QWidget(wdg_content);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-2, 81, 451, 76));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb_join = new QToolButton(widget);
        pb_join->setObjectName("pb_join");
        pb_join->setMinimumSize(QSize(70, 0));
        pb_join->setMaximumSize(QSize(70, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(10);
        pb_join->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/color.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pb_join->setIcon(icon2);
        pb_join->setIconSize(QSize(50, 50));
        pb_join->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        pb_join->setAutoRaise(true);

        horizontalLayout->addWidget(pb_join);

        pb_create = new QToolButton(widget);
        pb_create->setObjectName("pb_create");
        pb_create->setMinimumSize(QSize(70, 0));
        pb_create->setMaximumSize(QSize(70, 16777215));
        pb_create->setFont(font2);
        pb_create->setIcon(icon2);
        pb_create->setIconSize(QSize(50, 50));
        pb_create->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        pb_create->setAutoRaise(true);

        horizontalLayout->addWidget(pb_create);

        pb_tool3 = new QToolButton(widget);
        pb_tool3->setObjectName("pb_tool3");
        pb_tool3->setMinimumSize(QSize(70, 0));
        pb_tool3->setMaximumSize(QSize(70, 16777215));
        pb_tool3->setFont(font2);
        pb_tool3->setIcon(icon2);
        pb_tool3->setIconSize(QSize(50, 50));
        pb_tool3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        pb_tool3->setAutoRaise(true);

        horizontalLayout->addWidget(pb_tool3);


        verticalLayout->addWidget(wdg_content);


        retranslateUi(WeChatDialog);

        QMetaObject::connectSlotsByName(WeChatDialog);
    } // setupUi

    void retranslateUi(QDialog *WeChatDialog)
    {
        WeChatDialog->setWindowTitle(QCoreApplication::translate("WeChatDialog", "WeChatDialog", nullptr));
        pb_icon->setText(QString());
        lb_name->setText(QCoreApplication::translate("WeChatDialog", "\346\265\213\350\257\225\347\224\250\346\210\267", nullptr));
        pb_set->setText(QString());
        pb_join->setText(QCoreApplication::translate("WeChatDialog", "\345\212\240\345\205\245\344\274\232\350\256\256", nullptr));
        pb_create->setText(QCoreApplication::translate("WeChatDialog", "\345\210\233\345\273\272\344\274\232\350\256\256", nullptr));
        pb_tool3->setText(QCoreApplication::translate("WeChatDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeChatDialog: public Ui_WeChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHATDIALOG_H
