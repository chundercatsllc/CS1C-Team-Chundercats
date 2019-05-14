#include "login.h"
#include "ui_login.h"


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    QString user_name = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    dbConnection db;
    QString result = db.userLogin(user_name,password);
    if(result == "user"||result == "admin"){
        QMessageBox::information(this,"Login","Login Successful! Welcome, "+result+" "+user_name);
           coolcool = true;
    }else{
        QMessageBox::warning(this,"Login",result);
        coolcool = false;
    }

}
