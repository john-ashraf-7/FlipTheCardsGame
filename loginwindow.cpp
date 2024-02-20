#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "maingame.h"

QString username[5] = {"admin", "Besho", "John", "Omar", "3BHD"};
QString passwords[5] = {"admin", "besho1234", "john1234", "omar1234", "3BHD1234"};


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->errorMsg->setVisible(false);
    ui->passwordLE->setEchoMode(QLineEdit::Password);

    QPixmap admin(":/new/pics/adminpng.png");
    QPixmap besho(":/new/pics/Besho.jpg");
    QPixmap john(":/new/pics/John.jpg");
    QPixmap omar(":/new/pics/Omar.jpg");
    QPixmap abhd(":/new/pics/3BHD.jpg");
    admin = admin.scaled(100,100);
    besho = besho.scaled(100,100);
    john = john.scaled(100,100);
    omar = omar.scaled(100,100);
    abhd = abhd.scaled(100,100);
    pics[0].setPixmap(admin);
    pics[1].setPixmap(besho);
    pics[2].setPixmap(john);
    pics[3].setPixmap(omar);
    pics[4].setPixmap(abhd);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_clicked()
{
    QString user = ui->usernameLE->text();
    QString pass = ui->passwordLE->text();
    QPixmap pic;
    if(user == "" || pass == ""){
        ui->errorMsg->setVisible(true);
        return;
    }
    bool found = false;
    for(int i = 0; i < 5; i++){
        if(user == username[i]){
            if(pass == passwords[i]){
                found = true;
                pic = pics[i].pixmap();
            }
        }
    }
    if(found){
        hide();
        MainGame *main1 = new MainGame(user, pic);
    }
    else {
        ui->errorMsg->setVisible(true);
        return;
    }
}
