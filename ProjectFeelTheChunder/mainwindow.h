#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QComboBox>
#include <QSpinBox>
#include "RenderArea.h"
#include "shape.h"
#include "testimonials.h"
#include "contactus.h"
#include "login.h"

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

        void getShapeType(QComboBox * combo);

        void getPenColor(QComboBox * combo);

        void getPenStyle(QComboBox * combo);

        void getPenCapStyle(QComboBox * combo);

        void getPenJoinStyle(QComboBox * combo);

        void getBrushColor(QComboBox * combo);

        void getBrushStyle(QComboBox * combo);

        Qt::AlignmentFlag getAlign(QComboBox * combo);

        Qt::GlobalColor getTextColor(QComboBox * combo);

        QFont::Weight getTextWeight(QComboBox * combo);

        QFont::Style getTextStyle(QComboBox * combo);

        QString getFontFamily(QComboBox * combo);

        void getPenWidth(QSpinBox * spinster);

        void setShapeNonsense(Shape * shape, Shape::ShapeType, int id, Qt::GlobalColor pc, int pw, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::GlobalColor bc, Qt::BrushStyle bs);

        void comboTrickColors(QComboBox * combo);
        void comboTrickShapes(QComboBox * combo);
        void comboTrickPenStyles(QComboBox * combo);
        void comboTrickPenCapStyles(QComboBox * combo);
        void comboTrickPenJoinStyles(QComboBox * combo);
        void comboTrickBushStyle(QComboBox *combo);
        void comboTrickFlag(QComboBox *combo);
        void comboTrickFontStyle(QComboBox *combo);
        void comboTrickFontFam(QComboBox *combo);
        void comboTrickFontWeight(QComboBox *combo);

        void debugPrintShapeInfo();
private slots:

        void on_start_add_button_clicked();

        void on_build_it_final_button_clicked();

        void on_cancel_add_shape_final_clicked();

        void on_start_edit_button_clicked();

        void on_build_it_button_clicked();

        void on_cancel_button_clicked();

        void on_cancel_button_5_clicked();

        void on_cancel_button_6_clicked();

        void on_start_delete_button_clicked();

        void on_erase_it_button_clicked();

        void on_change_it_button_clicked();

        void on_testimonial_button_clicked();

        void on_thank_kanye_button_clicked();

        void on_login_button_clicked();

        void on_shapeID_edit_spin_valueChanged(int arg1);

        void on_reports_button_clicked();

private:
        Ui::MainWindow *ui;
        Testimonials * testis;
        contactUs    * contactPage;
        Login        * loginPage;
        bool meddleable{false};

        Shape::ShapeType The_shapeType{Shape::ShapeType::Rectangle};
        Qt::GlobalColor  The_penColor{Qt::GlobalColor::blue};
        Qt::PenStyle     The_penStyle{Qt::PenStyle::SolidLine};
        Qt::PenCapStyle  The_penCap{Qt::PenCapStyle::RoundCap};
        Qt::PenJoinStyle The_penJoinStyle{Qt::PenJoinStyle::MiterJoin};
        Qt::GlobalColor  The_brushColor{Qt::GlobalColor::blue};
        Qt::BrushStyle   The_brushStyle{Qt::BrushStyle::SolidPattern};
        int              The_penWidth{4};
};

#endif // MAINWINDOW_H
