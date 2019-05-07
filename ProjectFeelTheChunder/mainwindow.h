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

        void setShapeNonsense(Shape * shape, Shape::ShapeType, int id, Qt::GlobalColor pc, int pw, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::GlobalColor bc, Qt::BrushStyle bs);

private slots:

        void on_add_shape_button_3_clicked();

        void on_start_add_button_clicked();

        bool on_build_it_final_button_clicked();

        bool on_cancel_add_shape_final_clicked();

private:
		Ui::MainWindow *ui;
        bool meddleable{false};
        bool addify{false};
};

#endif // MAINWINDOW_H
