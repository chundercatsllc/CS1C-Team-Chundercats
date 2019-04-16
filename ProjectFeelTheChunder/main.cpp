#include "mainwindow.h"
#include <QApplication>
#include "line.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

    Line line1;


	return a.exec();
}
