#include "mainwindow.h"
#include <QApplication>
#include "./database/dbconnection.h"
#include "create_user.h"
#include <QDialog>
#include "login.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    //MainWindow w;
   // w.show();
    //dbConnection db;
    //db.restTest();
    //QString response = db.getShapeTypes();

    //qDebug()<<response;

	return a.exec();
}
