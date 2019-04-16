#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMessageBox>
#include "./database/dbconnection.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString user_name = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    dbConnection db;
    QString result = db.userLogin(user_name,password);
    if(result == "user"||result == "admin"){
        QMessageBox::information(this,"Login","Login Successful! Welcome, "+result+" "+user_name);
    }else{
        QMessageBox::warning(this,"Login",result);
    }
}
