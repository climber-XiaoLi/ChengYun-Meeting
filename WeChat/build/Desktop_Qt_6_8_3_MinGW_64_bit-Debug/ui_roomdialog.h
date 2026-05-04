/********************************************************************************
** Form generated from reading UI file 'roomdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMDIALOG_H
#define UI_ROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <usershowwidget.h>

QT_BEGIN_NAMESPACE

class Ui_RoomDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_title;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_min;
    QPushButton *pb_max;
    QPushButton *pb_close;
    QHBoxLayout *horizontalLayout;
    QWidget *wdg_left;
    QHBoxLayout *horizontalLayout_4;
    UserShowWidget *wdg_userShow;
    QWidget *wdg_right;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QWidget *wdg_list;
    QSpacerItem *verticalSpacer;
    QWidget *wdg_bottom;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cb_video;
    QCheckBox *cb_audio;
    QCheckBox *cb_desk;
    QComboBox *cbb_special;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_quit;

    void setupUi(QDialog *RoomDialog)
    {
        if (RoomDialog->objectName().isEmpty())
            RoomDialog->setObjectName("RoomDialog");
        RoomDialog->resize(800, 600);
        RoomDialog->setMinimumSize(QSize(800, 600));
        RoomDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(RoomDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_title = new QWidget(RoomDialog);
        wdg_title->setObjectName("wdg_title");
        wdg_title->setMinimumSize(QSize(800, 40));
        wdg_title->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(wdg_title);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lb_title = new QLabel(wdg_title);
        lb_title->setObjectName("lb_title");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        lb_title->setFont(font);

        horizontalLayout_2->addWidget(lb_title);

        horizontalSpacer = new QSpacerItem(592, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_min = new QPushButton(wdg_title);
        pb_min->setObjectName("pb_min");
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));
        pb_min->setAutoDefault(false);

        horizontalLayout_2->addWidget(pb_min);

        pb_max = new QPushButton(wdg_title);
        pb_max->setObjectName("pb_max");
        pb_max->setMinimumSize(QSize(30, 30));
        pb_max->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pb_max);

        pb_close = new QPushButton(wdg_title);
        pb_close->setObjectName("pb_close");
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pb_close);


        verticalLayout->addWidget(wdg_title);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName("horizontalLayout");
        wdg_left = new QWidget(RoomDialog);
        wdg_left->setObjectName("wdg_left");
        wdg_left->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(wdg_left);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        wdg_userShow = new UserShowWidget(wdg_left);
        wdg_userShow->setObjectName("wdg_userShow");

        horizontalLayout_4->addWidget(wdg_userShow);


        horizontalLayout->addWidget(wdg_left);

        wdg_right = new QWidget(RoomDialog);
        wdg_right->setObjectName("wdg_right");
        wdg_right->setMinimumSize(QSize(249, 520));
        wdg_right->setMaximumSize(QSize(250, 16777215));
        verticalLayout_2 = new QVBoxLayout(wdg_right);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(wdg_right);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 248, 518));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        wdg_list = new QWidget(scrollAreaWidgetContents);
        wdg_list->setObjectName("wdg_list");

        verticalLayout_3->addWidget(wdg_list);

        verticalSpacer = new QSpacerItem(20, 505, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        horizontalLayout->addWidget(wdg_right);


        verticalLayout->addLayout(horizontalLayout);

        wdg_bottom = new QWidget(RoomDialog);
        wdg_bottom->setObjectName("wdg_bottom");
        wdg_bottom->setMinimumSize(QSize(800, 40));
        wdg_bottom->setMaximumSize(QSize(16777215, 40));
        wdg_bottom->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(wdg_bottom);
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        cb_video = new QCheckBox(wdg_bottom);
        cb_video->setObjectName("cb_video");
        cb_video->setMinimumSize(QSize(0, 20));

        horizontalLayout_3->addWidget(cb_video);

        cb_audio = new QCheckBox(wdg_bottom);
        cb_audio->setObjectName("cb_audio");
        cb_audio->setMinimumSize(QSize(0, 20));

        horizontalLayout_3->addWidget(cb_audio);

        cb_desk = new QCheckBox(wdg_bottom);
        cb_desk->setObjectName("cb_desk");
        cb_desk->setMinimumSize(QSize(0, 20));

        horizontalLayout_3->addWidget(cb_desk);

        cbb_special = new QComboBox(wdg_bottom);
        cbb_special->addItem(QString());
        cbb_special->addItem(QString());
        cbb_special->addItem(QString());
        cbb_special->setObjectName("cbb_special");

        horizontalLayout_3->addWidget(cbb_special);

        horizontalSpacer_2 = new QSpacerItem(490, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pb_quit = new QPushButton(wdg_bottom);
        pb_quit->setObjectName("pb_quit");
        pb_quit->setMinimumSize(QSize(70, 30));
        pb_quit->setMaximumSize(QSize(70, 30));
        pb_quit->setFont(font);

        horizontalLayout_3->addWidget(pb_quit);


        verticalLayout->addWidget(wdg_bottom);


        retranslateUi(RoomDialog);

        QMetaObject::connectSlotsByName(RoomDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomDialog)
    {
        RoomDialog->setWindowTitle(QCoreApplication::translate("RoomDialog", "Dialog", nullptr));
        lb_title->setText(QCoreApplication::translate("RoomDialog", "\346\210\277\351\227\264\345\217\267\357\274\23200000000", nullptr));
        pb_min->setText(QString());
        pb_max->setText(QString());
        pb_close->setText(QString());
        cb_video->setText(QCoreApplication::translate("RoomDialog", "\350\247\206\351\242\221", nullptr));
        cb_audio->setText(QCoreApplication::translate("RoomDialog", "\351\237\263\351\242\221", nullptr));
        cb_desk->setText(QCoreApplication::translate("RoomDialog", "\346\241\214\351\235\242", nullptr));
        cbb_special->setItemText(0, QCoreApplication::translate("RoomDialog", "\346\227\240\346\273\244\351\225\234", nullptr));
        cbb_special->setItemText(1, QCoreApplication::translate("RoomDialog", "\345\205\224\350\200\263\346\234\265", nullptr));
        cbb_special->setItemText(2, QCoreApplication::translate("RoomDialog", "\345\234\243\350\257\236\345\270\275\345\255\220", nullptr));

        pb_quit->setText(QCoreApplication::translate("RoomDialog", "\351\200\200\345\207\272\346\210\277\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomDialog: public Ui_RoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
