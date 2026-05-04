/********************************************************************************
** Form generated from reading UI file 'usershowwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSHOWWIDGET_H
#define UI_USERSHOWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserShowWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lb_name;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *UserShowWidget)
    {
        if (UserShowWidget->objectName().isEmpty())
            UserShowWidget->setObjectName("UserShowWidget");
        UserShowWidget->resize(240, 200);
        UserShowWidget->setMinimumSize(QSize(240, 200));
        UserShowWidget->setMaximumSize(QSize(16777215, 16777215));
        UserShowWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(UserShowWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lb_name = new QLabel(UserShowWidget);
        lb_name->setObjectName("lb_name");
        lb_name->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        lb_name->setFont(font);
        lb_name->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lb_name);

        verticalSpacer = new QSpacerItem(20, 167, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(UserShowWidget);

        QMetaObject::connectSlotsByName(UserShowWidget);
    } // setupUi

    void retranslateUi(QWidget *UserShowWidget)
    {
        UserShowWidget->setWindowTitle(QCoreApplication::translate("UserShowWidget", "Form", nullptr));
        lb_name->setText(QCoreApplication::translate("UserShowWidget", "\347\224\250\346\210\267\345\220\215\357\274\232\346\265\213\350\257\225\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserShowWidget: public Ui_UserShowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSHOWWIDGET_H
