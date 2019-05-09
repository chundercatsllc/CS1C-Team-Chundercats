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

}

Testimonials::~Testimonials()
{
    delete ui;
}
