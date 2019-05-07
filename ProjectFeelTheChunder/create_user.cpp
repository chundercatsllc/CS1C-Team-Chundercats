#include "create_user.h"
#include "ui_create_user.h"
#include "./database/dbconnection.h"

create_user::create_user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_user)
{
    ui->setupUi(this);
}

create_user::~create_user()
{
    delete ui;
}

void create_user::on_new_user_pushButton_clicked()
{
    QString user_name = ui->new_user_name_lineEdit->text();
    QString password = ui->new_password_lineEdit->text();
    QString confirm = ui->confirm_password_lineEdit->text();
    QString admin_code = ui->admin_code_lineEdit->text();
    dbConnection db;
    if(confirm == password){
        QString result = db.createUser(user_name,password,admin_code);
        if(result == "success"){
            QMessageBox::information(this,"Account Creation","Account Successfully Created! welcome, "+user_name+"!");
            ui->new_user_name_lineEdit->clear();
            ui->new_password_lineEdit->clear();
            ui->confirm_password_lineEdit->clear();
            ui->admin_code_lineEdit->clear();
        }else if(result == "exists"){
            QMessageBox::warning(this,"Account Creation","An Account with that User Name Already Exists.");
            ui->new_user_name_lineEdit->clear();
        }else{
            QMessageBox::warning(this,"Account Creation",result);
        }
    }else{
        QMessageBox::warning(this,"Account Creation","Confirm password does not match Password");
        ui->new_password_lineEdit->clear();
        ui->confirm_password_lineEdit->clear();
    }
}
