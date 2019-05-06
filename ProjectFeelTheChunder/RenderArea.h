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

        //!
        void chopShape(int indexRemove);
        void moveShape(int indexMove, int coordMove, int x, int y); //Move shape


   //     void writeShapeFile(); //Writing to shape File

   private:
        const QImage renderArea;
        AwesomeVector<Shape*> ShapeMagazine;
        int numShapes;

        void readShapeFile();

        QString getStringColor(QColor color);
        QString getStringPenCap(Qt::PenCapStyle penCapStyle);
        QString getStringPenStyle(Qt::PenStyle penStyle);
        QString getStringPenJointStyle(Qt::PenJoinStyle penJointStyle);
        QString getStringBrush(Qt::BrushStyle brush);
        QString getStringFlag(Qt::AlignmentFlag  flag);
        QString getStringFontStyle(QFont::Style fontStyle);
        QString getStringFontWeight(int fontWeight);

        Shape::ShapeType  getShapeType(QString shape);
        Qt::GlobalColor   getColor(QString color);
        Qt::PenCapStyle   getPenCapStyle(QString cap);
        Qt::PenStyle      getPenStyle(QString pen);
        Qt::PenJoinStyle  getPenJointStyle(QString penJoint);
        Qt::BrushStyle    getBrushStyle(QString brushStyle);
        Qt::AlignmentFlag getFlag(QString flag);
        QFont::Style      getFontStyle(QString fontStyle);
        QFont::Weight     getFontWeight(QString fontWeight);
};


#endif // RenderArea_H
