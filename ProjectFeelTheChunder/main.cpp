#include "mainwindow.h"
#include "./FileParser/parse.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	// Temporary file parser test:
	parse file1;
	file1.set_file("shapes.txt");

	file1.parseInput(1);
	// ---------------------------

	return a.exec();
}
