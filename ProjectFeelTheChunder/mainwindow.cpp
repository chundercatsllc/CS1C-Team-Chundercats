#include "mainwindow.h"
#include "shape.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //setWindowIcon(QIcon(":/pix/icon.png"));

    //AwesomeVector<Shape *> shapeMagazine;

    //ui->setupUi(this);
    QMovie *movie = new QMovie(":/pix/loader.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();

}

MainWindow::~MainWindow()
{
	delete ui;
}
