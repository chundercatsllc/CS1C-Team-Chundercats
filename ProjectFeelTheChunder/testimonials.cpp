#include "testimonials.h"
#include "ui_testimonials.h"

Testimonials::Testimonials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testimonials)
{
    ui->setupUi(this);
    TheView = new QListWidget(ui->view_testis);
    QString text = "Kanye: I love this program.";
    QListWidgetItem *starter = new QListWidgetItem(text, TheView);
    TheView->addItem(starter);
    TheView->show();
}

Testimonials::~Testimonials()
{
    delete ui;
}

void Testimonials::on_pushButton_clicked()
{
    QString text = ui->add_testi_edit_box->toPlainText();
    QString name = "John Cena";
    name = ui->name_box->text();
    text = name + ": " + text;

    qDebug() << text;
    testimonialList.push_back(text);

    QListWidgetItem *thing = new QListWidgetItem(text, TheView);
    TheView->addItem(thing);
    TheView->show();
}

