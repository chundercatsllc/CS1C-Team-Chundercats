/*
 *  2D Graphics Modeler
 *  December 2018
 *
 *  Oscar Lopez <olopez23@saddleback.edu>
 *  Jeff Adams <jadams62@saddleback.edu>
 *  Isaac Estrada <iestrada5@saddleback.edu>
 *  Caroline Ta <tta24@saddleback.edu>
 *  Travis Nguyen <tnguyen603@saddleback.edu>
 *  Taylor Paczkowski <tpaczkowski0@saddleback.edu>
 *  
 *  Descr: 2D Graphics Modeler for CS1C Fall 2018
 *  Teacher: John Kath
 *
 *  Draws shapes using QPainter. Shapes can be loaded from a file, added
 *  to a vector, manipulated and later saved. A login is required to access
 *  the program.
 *
 **/
/*
    File: canvas.h
    Base class of all renderable objects
*/

#ifndef CANVAS_H
#define CANVAS_H

#include <QFile>
#include <QTextStream>
#include "ShapeClass/shape.h"
#include "containers/AwesomeVector.h"
#include "FileParser/parse.h"
#include <QPaintEvent>
#include <QWidget>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>

/**
@brief used to control canvas, display shapes and contains vector of shapes
*/
class Canvas : public QWidget
{
    public:
    /** Default constructor
    */
        Canvas(QWidget *parent = 0);

    /** Gets size of canvas
    @return size of canvas
    */
        QSize sizeHint() const override;
        
    /** Set minimum size of canvas
    @return min size of canvas
    */
        QSize minimumSizeHint() const override;

    /** Get the ID count of the amount of shapes ever added to canvas
    @return ID count
    */
        int getRealID(){return IDCount;}

    /** Get the vector that contains the shape list
    @return vector of shapes on canvas
    */
        AwesomeVector<Shape*> GetList(){return ShapeMagazine;}

    /** Add a shape to the canvas by adding to vector
    */
        void shapeAdd(Shape* shapeIn);

    /** Get the size of the list
    @return size of shape list
    */
        int getSizing(){return ShapeMagazine.sizeOf();}

    /** Removes shape by searching for specific ID
    @param indexRemove - ID number 
    */
        void shapeRemove(int indexRemove);//Shape remove

    /** Moves shape of canvas by changing coordinate values of a shape.
        Searches for a specific shape by looking at ID
        @param indexMove - shapeID of shape that will be moved
        @param coordMove - which coordinate to change ex: 1st, 2nd, etc
        @param x - change of x coordinate
        @param y - change of y coordinate
    */
        void shapeMove(int indexMove, int coordMove, int x, int y); //Move shape

    /** Draws shapes to canvas
    @param event - will act on paint event
    */
        void paintEvent(QPaintEvent *event) override; //Paint event ovverride

    /** Writes to shape.txt file to save changes 
    */
        void writeShapeFile(); //Writing to shape File

   private:
        AwesomeVector<Shape*> ShapeMagazine; /**<Keeps track of shapes*/
        int IDCount{1};/**<Count of total amount of shapes added to canvas*/
        const QImage target;

        /** Reads to shape.txt to read in previous saves
        */
        void readShapeFile(); /**<Read Shape File*/

        //STRING TO QT
        /** Changes string to enum of shape type
        @param shapeTypeStr - string of shape type
        @return Enum of shapeType
        */
        Shape::ShapeType str2shape(QString shapeName);

        /** Changes string to qt global color
        @param colorStr - string of shape color
        @return Qt color
        */
        Qt::GlobalColor str2color(QString colorStr);

        /** Changes string to qt pen cap style
        @param capStr - string of cap style
        @return Qt pen cap style
        */
        Qt::PenCapStyle strToQTCapStyle(QString capStr);

        /** Changes string to qt pen style
        @param penStr - string of pen style
        @return Qt pen style
        */
        Qt::PenStyle strToQTPenStyle(QString penStr);

        /** Changes string to qt pen join style
        @param penJoinStyleStrIn - string of pen join style
        @return Qt pen join style
        */
        Qt::PenJoinStyle strToQTPenJoinStyle(QString penJoinStyleStrIn);

        /** Changes string to qt brush style
        @param brushStyleStr - string of brush style
        @return Qt brush style
        */
        Qt::BrushStyle strToQTBushStyle(QString brushStyleStr);

        /** Changes string to qt alignment flag
        @param alignStrIn - string of alignment
        @return Qt alignment flag
        */
        Qt::AlignmentFlag strToQTAlignment(QString alignStrIn);

        /** Changes string to qt text font style
        @param textFontStyleStrIn - string of font style
        @return Qt text font style
        */
        QFont::Style strToQTTextStyle(QString textFontStyleStrIn);

        /** Changes string to qt text font weight
        @param textFontWeightStrIn - string of font weight
        @return Qt text weight
        */
        QFont::Weight strToQTTextWeight(QString textFontWeightStrIn);

        /** Changes qt color to string
        @param strColorIn - qt color
        @return string of color
        */
        QString QTColorToStr(QColor strColorIn);

        /** Changes qt pen cap style to string
        @param penCapStyleStrIn - qt pen cap style
        @return string of cap style
        */
        QString QTCapStyleToStr(Qt::PenCapStyle penCapStyleStrIn);

        /** Changes qt pen style to string
        @param penStyleStrIn - qt pen style
        @return string of pen style
        */
        QString   QTPenStyleToStr(Qt::PenStyle penStyleStrIn);

        /** Changes qt pen join to string
        @param penJoinStyleStrIn - qt pen join style
        @return string of pen join style
        */
        QString QTPenJoinStyleToStr(Qt::PenJoinStyle penJoinStyleStrIn);

        /** Changes qt brush style to string
        @param brushStyleStr - qt brush style
        @return string of brush style
        */
        QString QTBushStyleToStr(Qt::BrushStyle brushStyleStr);

        /** Changes qt alignment to string
        @param alignStrIn - qt alignment
        @return string of alignment
        */
        QString QTAlignmentToStr(Qt::AlignmentFlag  alignStrIn);

        /** Changes qt text font style to string
        @param textFontStyleStrIn - qt text font style
        @return string text font style
        */
        QString QTTextStyleToStr(QFont::Style textFontStyleStrIn);

        /** Changes qt text font weight to string
        @param textFontWeightStrIn - qt text font weight
        @return string text font weight
        */
        QString QTTextWeightToStr(int textFontWeightStrIn);

};


#endif // CANVAS_H
