#include "mainwindow.h"
#include <QApplication>
#include "./database/dbconnection.h"
#include "create_user.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    create_user c;
    c.show();

//    dbConnection db;

//    db.getShapes();
	return a.exec();
}
