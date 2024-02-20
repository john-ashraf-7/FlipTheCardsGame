/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usernameLE;
    QLineEdit *passwordLE;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *errorMsg;
    QMenuBar *menubar;
    QMenu *menuLogin_Window;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 454);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 70, 161, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 160, 91, 16));
        usernameLE = new QLineEdit(centralwidget);
        usernameLE->setObjectName("usernameLE");
        usernameLE->setGeometry(QRect(330, 70, 211, 24));
        passwordLE = new QLineEdit(centralwidget);
        passwordLE->setObjectName("passwordLE");
        passwordLE->setGeometry(QRect(330, 160, 211, 24));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(450, 280, 151, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 280, 151, 51));
        errorMsg = new QLabel(centralwidget);
        errorMsg->setObjectName("errorMsg");
        errorMsg->setGeometry(QRect(310, 370, 191, 16));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuLogin_Window = new QMenu(menubar);
        menuLogin_Window->setObjectName("menuLogin_Window");
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(usernameLE, passwordLE);
        QWidget::setTabOrder(passwordLE, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        menubar->addAction(menuLogin_Window->menuAction());

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Username</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Password</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginWindow", "Register", nullptr));
        errorMsg->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#aa0000;\">Invalid username or password</span></p></body></html>", nullptr));
        menuLogin_Window->setTitle(QCoreApplication::translate("LoginWindow", "Login Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
