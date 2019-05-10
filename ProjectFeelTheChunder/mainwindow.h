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



//!MainWindow Class: Public Inheritance from QMainWindow
/*!QMainWindow provides a main application window. This mainwindow provides a framework for building an apllication based user interface.
   MainWindow adds additional features to QMainWindow with the use of QComboBox and QSpinBox. */
class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:


        //!Main Window Contructor
        /*!Constructs a MainWindow using a pointer of type QWidget, which is the base class of user interface objects (receives keyboard, mouse, and other events to draw images).*/
        explicit MainWindow(QWidget *parent = nullptr);

        //!Destructor for MainWindow
        /*Destroys the main window, clears overhead. */
        ~MainWindow();


        void allowMeddling(bool YN) {meddleable = YN;}

        //!getShapeType function for MainWindow
        /*!getShapeType function sets the shape according to the user's selection(QComboBox index) using the drop down menu(QComboBox feature) on the main window.
        Shape::ShapeType::<shape> is used to fetch shape.
        \param combo is of type QComboBox
        */
        void getShapeType(QComboBox * combo);

        //!getPenColor function for MainWindow
        /*getpenColor function sets the pen color according to the user's selection(QComboBox index) using the drop down menu(QComboBox feature) on the main window.
        No value or reference returned.
        \param combo is a pointer of type QComboBox
        */
        void getPenColor(QComboBox * combo);

        //!getPenStyle function for MainWindow
        /*getpenStyle function sets the pen style according to the user's selection(QComboBox index) using the drop down menu(QComboBox feature) on the main window.
        No value or reference returned.
        \param combo is a pointer of type QComboBox
        */
        void getPenStyle(QComboBox * combo);

        //!getPenCapStyle function for MainWindow
        /*getpenCapStyle function sets the pen cap style according to the user's selection(QComboBox index) using the drop down menu(QComboBox feature) on the main window.
        No value or reference returned.
        \param combo is a pointer of type QComboBox
        */
        void getPenCapStyle(QComboBox * combo);

        //!getPenJoinStyle function for MainWindow
        /*getpenJoinStyle function sets the pen join style according to the user's selection(QComboBox index) using the drop down menu(QComboBox feature) on the main window.
        No value or reference returned.
        \param combo is a pointer of type QComboBox
        */
        void getPenJoinStyle(QComboBox * combo);

        //!getBrushColor function for MainWindow
        /*getBrushColor function sets the brush color according to the user's selection(QComboBox index) using the drop down menu(QComboBox feature) on the main window.
        No value or reference returned.
        \param combo is a pointer of type QComboBox
        */
        void getBrushColor(QComboBox * combo);

        //!getBrushStyle function for MainWindow
        /*getBrushStyle function sets the brush style according to the user's selection(QComboBox index) using the drop down menu(QComboBox feature) on the main window.
        No value or reference returned.
        \param combo is a pointer of type QComboBox
        */
        void getBrushStyle(QComboBox * combo);

        //!getAlign function for MainWindow
        /*!getAlign function sets the alignment according to the user's selection(QComboBox index) using the drop menu(QComboBox feature) on the main window.
        With the respective user selection from the QComboBox feature, a Qt::AlignmentFlag is returned.
        \param combo is a pointer of type QComboBox
        */
        Qt::AlignmentFlag getAlign(QComboBox * combo);

        //!getTextColor function for MainWindow
        /*!getTextColor function sets the text color according to the user's selection(QComboBox index) using the drop menu(QComboBox feature) on the main window.
        With the respective user selection from the QComboBox feature, a Qt::GlobalColor is returned.
        \param combo is a pointer of type QComboBox
        */
        Qt::GlobalColor getTextColor(QComboBox * combo);

        //!getTextWeight function for MainWindow
        /*!getTextWeight function sets the text weight according to the user's selection(QComboBox index) using the drop menu(QComboBox feature) on the main window.
        With the respective user selection from the QComboBox feature, a QFont::Weight is returned.
        \param combo is a pointer of type QComboBox
        */
        QFont::Weight getTextWeight(QComboBox * combo);

        //!getTextStyle function for MainWindow
        /*!getTextStyle function sets the text style according to the user's selection(QComboBox index) using the drop menu(QComboBox feature) on the main window.
        With the respective user selection from the QComboBox feature, a QFont::Style is returned.
        \param combo is a pointer of type QComboBox
        */
        QFont::Style getTextStyle(QComboBox * combo);

        //!getFontFamily function for MainWindow
        /*!getFontFamily function sets the font family according to the user's selection(QComboBox index) using the drop menu(QComboBox feature) on the main window.
        With the respective user selection from the QComboBox feature, a QString is returned.
        \param combo is a pointer of type QComboBox
        */
        QString getFontFamily(QComboBox * combo);

        void getPenWidth(QSpinBox * spinster);


        //!setShapeNonsense function for MainWindow
        /*!setShapeNonsense sets the characteristics of shape. Takes in ALL characterictics of shape as parameters.
        Parameters will be passed to setShape, setBrush, setPen, and setID
        All Qt based attributes will be passed to shape's setPen together.
        \param shape is of type Shape
        \param id is of type int
        \param pc is of type Qt::GlobalColor
        \param pw is of type int
        \param ps is of type Qt::PenStyle
        \param pcs is of type Qt::PenCapStyle
        \param pjs is of type Qt::PenJoinStyle
        \param bc is of type Qt::GlobalColor
        \param bs is of type Qt::BrushStyle
        */
        void setShapeNonsense(Shape * shape, Shape::ShapeType, int id, Qt::GlobalColor pc, int pw, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs, Qt::GlobalColor bc, Qt::BrushStyle bs);


        //!comboTrickColors function for MainWindow
        /*!comboTrickColors function adds a drop down menu for colors on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickColors(QComboBox * combo);

        //!comboTrickShapes function for MainWindow
        /*!comboTrickShapes function adds a drop down menu for shapes on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickShapes(QComboBox * combo);

        //!comboTrickPenStyles function for MainWindow
        /*!comboTrickPenStyles function adds a drop down menu for pen styles on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickPenStyles(QComboBox * combo);

        //!comboTrickPenCapStyles function for MainWindow
        /*!comboTrickPenCapStyles function adds a drop down menu for pen cap styles on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickPenCapStyles(QComboBox * combo);

        //!comboTrickPenJoinStyles function for MainWindow
        /*!comboTrickPenJoinStyles function adds a drop down menu for pen join styles on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickPenJoinStyles(QComboBox * combo);

        //!comboTrickBushStyle function for MainWindow
        /*!comboTrickBushStyle function adds a drop down menu for brush style on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickBushStyle(QComboBox *combo);

        //!comboTrickFlag function for MainWindow
        /*!comboTrickFlag function adds a drop down menu for flags on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickFlag(QComboBox *combo);

        //!comboTrickFontStyle function for MainWindow
        /*!comboTrickFontStyle function adds a drop down menu for font styles on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickFontStyle(QComboBox *combo);

        //!comboTrickFontFam function for MainWindow
        /*!comboTrickFontFam function adds a drop down menu for font families on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickFontFam(QComboBox *combo);

        //!comboTrickFontWeight function for MainWindow
        /*!comboTrickFontWeight function adds a drop down menu for font weights on the main window. QComboBox pointer required as a paramter.
        No value or reference is returned.
        \param combo is a pointer of type QComboBox
        */
        void comboTrickFontWeight(QComboBox *combo);

        void debugPrintShapeInfo();
private slots:

        void on_start_add_button_clicked();

        //!Function builds the shape on the main window
        /*!Function contains nested switch cases. The outermost switch statement determines the shapetype, Shape::ShapeType::<shape> is used to execute each case.
        Shapes with multiple vertices have nested switch cases. The number of vertices determine a case by case execuation.
        Each case in the outermost switch statement calls setShapeNonsense function, passing all shape characteristics to build the shape.
        No parameters required, no value/reference returned.
        */
        void on_build_it_final_button_clicked();execute a case

        void on_cancel_add_shape_final_clicked();

        void on_start_edit_button_clicked();

        void on_build_it_button_clicked();

        //!Function to return to the UI start up page from add page.
        /*!This function executes when the user wants to cancel adding a shape. The add page(Widget) is reset to the start page. */
        void on_cancel_button_clicked();

        //!Function to return to the UI start up page from edit page.
        /*!This function executes when the user wants cancel editing a shape. The edit page(Widget) is reset to the start page. */
        void on_cancel_button_5_clicked();

        //!Function to return to the UI start up page from delete page.
        /*!This function executes when the user wants to cancel deleting a shape. The delete page(Widget) is reset to the start page. */
        void on_cancel_button_6_clicked();

        void on_start_delete_button_clicked();

        void on_erase_it_button_clicked();

        void on_change_it_button_clicked();

        //!Function to show testimonials, no parameters required, no value/reference returned
        void on_testimonial_button_clicked();

        //!Function to show contact information, no paramters required, no value/reference returned
        void on_thank_kanye_button_clicked();

        //!Function to show the login page, no parameters required, no value/refernce returned
        void on_login_button_clicked();

private:
        Ui::MainWindow *ui;
        Testimonials * testis;
        contactUs * contactPage;
        Login * loginPage;
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
