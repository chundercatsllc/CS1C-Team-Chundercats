#include "mainwindow.h"
#include "shape.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //setWindowIcon(QIcon(":/pix/icon.png"));

    //AwesomeVector<Shape *> shapeMagazine;

	ui->setupUi(this);

}

MainWindow::~MainWindow()
{
	delete ui;
}
