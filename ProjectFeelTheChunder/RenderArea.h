#ifndef RenderArea_H
#define RenderArea_H



#include <QFile>
#include <QTextStream>
#include "shape.h"
#include "containers/AwesomeVector.h"
#include <QPaintEvent>
#include <QWidget>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>



//!RenderArea Class: Public Inheritance from QWidget
/*!RenderArea is inheriting from QWidget, thus has all the functionalities of QWidget plus additional functions and variables that allow rendering of shapes defined by the shape class heirarchy.*/
class RenderArea : public QWidget
{
    public:

        //!RenderArea Class Constutor
        /*!RenderArea Constructor takes in one paramater of type QWidget*, initilaized to nullptr to avoid conflict.
        QWidget is the base class for all user-interface objects
        \param *parent is of type QWidget
        */
        RenderArea(QWidget *parent = nullptr);

        //!paintEvent function for RenderArea
        /*!paintEvent function overrides a virtual paintEvent within QWidget, takes in a QPaintEvent pointer.
        \param *event is of type QPaintEvent
        */
        void paintEvent(QPaintEvent *event) override;

        //!sizeHint function for RenderArea
        /*!sizeHint function sets the size of the 2-D "canvas" upon which the shapes will be rendered. sizeHint uses QSize(int, int) to set the size of the "canvas".
        No parameters required.
        */
        QSize sizeHint() const override;

        //!minimumSizeHint function for RenderArea
        /*!See sizeHint */
        QSize minimumSizeHint() const override;


        const AwesomeVector<Shape*>& getShapes();

        //!addShape function for RenderArea
        /*!addShape adds a shape to the end of the class vector ShapeMagazine. addShape requires one parameter
        \param shapeIn* is a pointer of type Shape, nothing is being returned
        */
        void addShape(Shape* shapeIn);

        //!getSize function for RenderArea
        /*!getSize returns the current size of the vector ShapeMagazine.
        No parameters are required, and int value is returned
        */
        int getSize();

        //!getNumShapes function for RenderArea
        int getNumShapes();

        //!chopShape function for RenderArea
        /*chopeSHape function removes the shape specified at a certain index from ShapeMagazine
        \param indexRemove is of type int
        */
        void chopShape(int indexRemove);

        //!moveShape fucntion for RenderArea
        /*!moveShape function finds the shape at the given index and moves it with the given input parameters.
        Moves the vertices of a given shape.
        \param indexMove is of type int
        \param coordMove is of type int
        \param x is of type int
        \param y is of type int
        */
        void moveShape(int indexMove, int coordMove, int x, int y);


   private:

        //!renderArea is of type constant QImage
        /*!QImage is a class that handles image data. QImage is designed for pixel accessing and manipulation.
           QImage is QPaintDevice subclass, thus QPainter can be used to directly to draw onto images.
        */
        const QImage renderArea;


        //!ShapeMagazine is of type AwesomeVector
        /*!AwesomeVector stores pointers of type shape in a vector format.
        moveShape, chopShape, addShape, getShape all use ShapeMagazine to perform necessary operations.
        */
        AwesomeVector<Shape*> ShapeMagazine;

        //!numShapes is of type int
        /*numShapes represents the amount of shape present in ShapeMagazine. */
        int numShapes;

        //!readShapeFile function for RenderArea
        void readShapeFile();

        //!getStringColor function for RenderArea
        /*!getStringColor function takes in a QColor object and converts the QColor to a QString to be saved in a shapes file. Return type is QString.
        \param color is of type QColor.
        */
        QString getStringColor(QColor color);

        //!getStringPenCap function for RenderArea
        /*!getStringPenCap function takes in a Qt::PenCapStyle object and converts the PenCapStyle to a QString to be saved in a shapes file. Return type is QString.
        \param penCapStyle is of type Qt::PenCapStyle.
        */
        QString getStringPenCap(Qt::PenCapStyle penCapStyle);

        //!getStringPenStyle function for RenderArea
        /*!getStringPenStyle function takes in a Qt::PenStyle object and converts the PenStyle to a QString to be saved in a shapes file. Return type is QString.
        \param penStyle is of type Qt::PenCapStyle.
        */
        QString getStringPenStyle(Qt::PenStyle penStyle);

        //!getStringPenJointStyle function for RenderArea
        /*!getStringPenJointStyle function takes in a Qt::PenJoinStyle object and converts the PenJoinStyle to a QString to be saved in a shapes file. Return type is QString.
        \param penJointStyle is of type Qt::PenJoinStyle.
        */
        QString getStringPenJointStyle(Qt::PenJoinStyle penJointStyle);

        //!getStringBrush function for RenderArea
        /*!getStringBrush function takes in a Qt::BrushStyle object and converts the BrushStyle to a QString to be saved in a shapes file. Return type is QString.
        \param brush is of type Qt::BrushStyle.
        */
        QString getStringBrush(Qt::BrushStyle brush);

        //!getStringFlag function for RenderArea
        /*!getStringFlag function takes in a Qt::AlignmentFlag object and converts the AlignmentFlag to a QString to be saved in a shapes file. Return type is QString.
        \param flag is of type Qt::AlignmentFlag.
        */
        QString getStringFlag(Qt::AlignmentFlag  flag);

        //!getStringFontStyle function for RenderArea
        /*!getStringFontStyle function takes in a QtFont::Style object and converts the Style to a QString to be saved in a shapes file. Return type is QString.
        \param fontStyle is of type QFont::Style.
        */
        QString getStringFontStyle(QFont::Style fontStyle);

        //!getStringFontWeight function for RenderArea
        /*!getStringFontWeight function takes in an int and converts the int value to a QString to be saved in a shapes file. Return type is QString.
        \param fontWeight is of type int.
        */
        QString getStringFontWeight(int fontWeight);


        //!getShapeType function for RenderArea
        /*!getShapeType function reads shape type from input file and converts it to a Shape specific type Shape::ShapeType.
        \param shape is of type QString
        */
        Shape::ShapeType  getShapeType(QString shape);

        //!getColor function for RenderArea
        /*!getColor function reads shape color from input file and converts it to Qt's inbuilt color specific type Qt::GlobalColor
        \param color is of type QString
        */
        Qt::GlobalColor   getColor(QString color);

        //!getPenCapStyle function for RenderArea
        /*!getPenCapStyle function reads shape pen cap style from input file and converts it to Qt's inbuilt pen cap specific type Qt::PenCapStyle
        \param cap is of type QString
        */
        Qt::PenCapStyle   getPenCapStyle(QString cap);

        //!getPenStyle function for RenderArea
        /*!getPenStyle function reads shape pen style from input file and converts it to Qt's inbuilt pen style specific type Qt::PenStyle
        \param pen is of type QString
        */
        Qt::PenStyle      getPenStyle(QString pen);

        //!getPenJointStyle function for RenderArea
        /*!getPenJointStyle function reads shape pen joint style from input file and converts it to Qt's inbuilt pen joint style specific type Qt::PenJointStyle
        \param penJoint is of type QString
        */
        Qt::PenJoinStyle  getPenJointStyle(QString penJoint);

        //!getBrushStyle function for RenderArea
        /*!getBrushStyle function reads shape brush style from input file and converts it to Qt's inbuilt brush style specific type Qt::BrushStyle
        \param brushStyle is of type QString
        */
        Qt::BrushStyle    getBrushStyle(QString brushStyle);

        //!getFlag function for RenderArea
        /*!getFlag function reads shape flag from input file and converts it to Qt's inbuilt flag specific type Qt::AlignmentFlag
        \param flag is of type QString
        */
        Qt::AlignmentFlag getFlag(QString flag);

        //!getFontStyle function for RenderArea
        /*!getFontStyle function reads shape font style from input file and converts it to Qt's inbuilt font style specific type QtFont::Style
        \param fontStyle is of type QString
        */
        QFont::Style      getFontStyle(QString fontStyle);

        //!getFontWeight function for RenderArea
        /*!getFontWeight function reads shape font weight from input file and converts it to Qt's inbuilt font weight specific type QtFont::Weight
        \param fontWeight is of type QString
        */
        QFont::Weight     getFontWeight(QString fontWeight);
};


#endif // RenderArea_H
