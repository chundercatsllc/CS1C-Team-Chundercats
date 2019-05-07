#include "mainwindow.h"
#include <QApplication>
#include "./database/dbconnection.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    dbConnection db;

//    db.getShapes();
	return a.exec();
}
