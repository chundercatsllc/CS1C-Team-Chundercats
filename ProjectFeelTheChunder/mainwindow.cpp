#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_painter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //QPixmap pix("C:/Users/Django Sr/Pictures/Joshua Tree/IMG_2723.jpg");
    //ui->pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
