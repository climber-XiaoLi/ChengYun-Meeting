/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QTabWidget *tw_page;
    QWidget *page_1;
    QPushButton *pb_clear;
    QPushButton *pb_commit;
    QLabel *lb_password;
    QLabel *lb_tel;
    QLineEdit *le_password;
    QLineEdit *le_tel;
    QWidget *page_2;
    QPushButton *pb_clear_register;
    QPushButton *pb_commit_register;
    QLabel *lb_tel_register;
    QLabel *lb_password_register;
    QLabel *lb_confirm_register;
    QLineEdit *le_tel_register;
    QLineEdit *le_password_register;
    QLineEdit *le_confirm_register;
    QLineEdit *le_name_register;
    QLabel *lb_name_register;
    QLabel *lb_icon;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(600, 400);
        tw_page = new QTabWidget(LoginDialog);
        tw_page->setObjectName("tw_page");
        tw_page->setGeometry(QRect(230, 0, 371, 401));
        QFont font;
        font.setPointSize(10);
        tw_page->setFont(font);
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        pb_clear = new QPushButton(page_1);
        pb_clear->setObjectName("pb_clear");
        pb_clear->setGeometry(QRect(160, 290, 56, 30));
        pb_commit = new QPushButton(page_1);
        pb_commit->setObjectName("pb_commit");
        pb_commit->setGeometry(QRect(250, 290, 56, 30));
        pb_commit->setFont(font);
        lb_password = new QLabel(page_1);
        lb_password->setObjectName("lb_password");
        lb_password->setGeometry(QRect(30, 40, 40, 30));
        lb_tel = new QLabel(page_1);
        lb_tel->setObjectName("lb_tel");
        lb_tel->setGeometry(QRect(30, 110, 40, 30));
        le_password = new QLineEdit(page_1);
        le_password->setObjectName("le_password");
        le_password->setGeometry(QRect(100, 110, 221, 30));
        le_password->setEchoMode(QLineEdit::EchoMode::Password);
        le_password->setClearButtonEnabled(true);
        le_tel = new QLineEdit(page_1);
        le_tel->setObjectName("le_tel");
        le_tel->setGeometry(QRect(100, 40, 221, 30));
        tw_page->addTab(page_1, QString());
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pb_clear_register = new QPushButton(page_2);
        pb_clear_register->setObjectName("pb_clear_register");
        pb_clear_register->setGeometry(QRect(160, 290, 56, 30));
        pb_commit_register = new QPushButton(page_2);
        pb_commit_register->setObjectName("pb_commit_register");
        pb_commit_register->setGeometry(QRect(250, 290, 56, 30));
        pb_commit_register->setFont(font);
        lb_tel_register = new QLabel(page_2);
        lb_tel_register->setObjectName("lb_tel_register");
        lb_tel_register->setGeometry(QRect(20, 30, 40, 30));
        lb_password_register = new QLabel(page_2);
        lb_password_register->setObjectName("lb_password_register");
        lb_password_register->setGeometry(QRect(20, 90, 40, 30));
        lb_confirm_register = new QLabel(page_2);
        lb_confirm_register->setObjectName("lb_confirm_register");
        lb_confirm_register->setGeometry(QRect(20, 140, 40, 30));
        le_tel_register = new QLineEdit(page_2);
        le_tel_register->setObjectName("le_tel_register");
        le_tel_register->setGeometry(QRect(110, 30, 221, 30));
        le_password_register = new QLineEdit(page_2);
        le_password_register->setObjectName("le_password_register");
        le_password_register->setGeometry(QRect(110, 90, 221, 30));
        le_password_register->setEchoMode(QLineEdit::EchoMode::Password);
        le_confirm_register = new QLineEdit(page_2);
        le_confirm_register->setObjectName("le_confirm_register");
        le_confirm_register->setGeometry(QRect(110, 140, 221, 30));
        le_confirm_register->setEchoMode(QLineEdit::EchoMode::Password);
        le_name_register = new QLineEdit(page_2);
        le_name_register->setObjectName("le_name_register");
        le_name_register->setGeometry(QRect(110, 200, 221, 30));
        lb_name_register = new QLabel(page_2);
        lb_name_register->setObjectName("lb_name_register");
        lb_name_register->setGeometry(QRect(20, 200, 40, 30));
        tw_page->addTab(page_2, QString());
        lb_icon = new QLabel(LoginDialog);
        lb_icon->setObjectName("lb_icon");
        lb_icon->setGeometry(QRect(0, 0, 223, 400));
        lb_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/register.png")));
        lb_icon->setScaledContents(true);
        QWidget::setTabOrder(le_tel_register, le_password_register);
        QWidget::setTabOrder(le_password_register, le_confirm_register);
        QWidget::setTabOrder(le_confirm_register, le_name_register);
        QWidget::setTabOrder(le_name_register, pb_commit_register);
        QWidget::setTabOrder(pb_commit_register, pb_clear_register);
        QWidget::setTabOrder(pb_clear_register, le_tel);
        QWidget::setTabOrder(le_tel, le_password);
        QWidget::setTabOrder(le_password, pb_commit);
        QWidget::setTabOrder(pb_commit, pb_clear);
        QWidget::setTabOrder(pb_clear, tw_page);

        retranslateUi(LoginDialog);

        tw_page->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        pb_clear->setText(QCoreApplication::translate("LoginDialog", "\346\270\205\347\251\272", nullptr));
        pb_commit->setText(QCoreApplication::translate("LoginDialog", "\346\217\220\344\272\244", nullptr));
        lb_password->setText(QCoreApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        lb_tel->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        le_password->setText(QCoreApplication::translate("LoginDialog", "1", nullptr));
        le_tel->setText(QCoreApplication::translate("LoginDialog", "13104282882", nullptr));
        tw_page->setTabText(tw_page->indexOf(page_1), QCoreApplication::translate("LoginDialog", "  \347\231\273\345\275\225  ", nullptr));
        pb_clear_register->setText(QCoreApplication::translate("LoginDialog", "\346\270\205\347\251\272", nullptr));
        pb_commit_register->setText(QCoreApplication::translate("LoginDialog", "\346\217\220\344\272\244", nullptr));
        lb_tel_register->setText(QCoreApplication::translate("LoginDialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        lb_password_register->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        lb_confirm_register->setText(QCoreApplication::translate("LoginDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        le_tel_register->setToolTip(QCoreApplication::translate("LoginDialog", "<html><head/><body><p>\350\276\223\345\205\2458-11\344\275\215\346\211\213\346\234\272\345\217\267</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        le_password_register->setToolTip(QCoreApplication::translate("LoginDialog", "<html><head/><body><p>\350\276\223\345\205\24520\344\275\215\344\273\245\345\206\205\345\257\206\347\240\201</p><p>\345\217\257\344\273\245\346\230\257\345\255\227\347\254\246\346\210\226\346\225\260\345\255\227</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        le_confirm_register->setToolTip(QCoreApplication::translate("LoginDialog", "<html><head/><body><p>\347\241\256\350\256\244\345\257\206\347\240\201\357\274\214\344\277\235\350\257\201\344\270\244\346\254\241\350\276\223\345\205\245\344\270\200\350\207\264</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        le_name_register->setToolTip(QCoreApplication::translate("LoginDialog", "<html><head/><body><p>\350\276\223\345\205\24510\344\275\215\344\273\245\345\206\205\347\232\204\346\230\265\347\247\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lb_name_register->setText(QCoreApplication::translate("LoginDialog", "\346\230\265\347\247\260", nullptr));
        tw_page->setTabText(tw_page->indexOf(page_2), QCoreApplication::translate("LoginDialog", "  \346\263\250\345\206\214  ", nullptr));
        lb_icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
