#include "mainwindow.h"
#include "vectors.h"
#include "shape.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Vectors<Shape> ShapeMagazine;



    return a.exec();
}
