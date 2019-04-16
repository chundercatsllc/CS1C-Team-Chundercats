#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    username = "admin";
    password = "oofda";
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    if(ui->userBox->text() == username)
    {
        qDebug() << "username worked";
    }
    if(ui->passBox->text() == password)
    {
        qDebug() << "password worked";
    }

}

