#include "contactus.h"
#include "ui_contactus.h"

contactUs::contactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contactUs)
{
    ui->setupUi(this);
//    QMovie *movie = new QMovie(":/pix/obamanation.gif");
//    QLabel *processLabel = new QLabel(ui->logo);
//    processLabel->setMovie(movie);
//    movie->start();

}

contactUs::~contactUs()
{
    delete ui;
}
