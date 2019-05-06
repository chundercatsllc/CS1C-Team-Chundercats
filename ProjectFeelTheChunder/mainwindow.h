#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shape.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = nullptr);
		~MainWindow();

        void allowMeddling(bool YN) {meddleable = YN;}

        Shape::ShapeType getShapeType();

        Qt::GlobalColor getPenColor();

        Qt::PenStyle getPenStyle();

        Qt::PenCapStyle getPenCapStyle();

        Qt::PenJoinStyle getPenJoinStyle();

        Qt::GlobalColor getBrushColor();

        Qt::BrushStyle getBrushStyle();

        Qt::AlignmentFlag getAlign();

        Qt::GlobalColor getTextColor();

        QFont::Weight getTextWeight();

        QFont::Style getTextStyle();

        QString getFontFamily();

        int getPenWidth();

private slots:
        void on_pushButton_clicked();

        void on_KANYE_linkActivated(const QString &link);

        void on_add_shape_button_3_clicked();

private:
		Ui::MainWindow *ui;
        bool meddleable{false};

};

#endif // MAINWINDOW_H
