#include "testimonials.h"
#include "ui_testimonials.h"

Testimonials::Testimonials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testimonials)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie(":/pix/obamanation.gif");
    QLabel *processLabel = new QLabel(ui->epicness);
    processLabel->setMovie(movie);
    movie->start();


    QString text = ui->add_testi_edit_box->toPlainText();
    qDebug() << text;

}

Testimonials::~Testimonials()
{
    delete ui;
}
