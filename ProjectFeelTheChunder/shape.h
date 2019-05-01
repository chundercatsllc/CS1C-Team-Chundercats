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
    File: shape.h
    Base class of all renderable objects
*/

#ifndef SHAPE_H
#define SHAPE_H

#include <QPaintDevice>
#include <QPoint>
#include <QString>
#include <QPainter>
#include "vector.h"

using namespace VecSTD;

//ShapeString
const QString shapeTypeStr[7] ={"No Shape", "Line", "Polyline", "Polygon", "Rectangle", "Ellipse", "Text"} ;

//Shape ENUM
enum class ShapeType {NoShape, LineType, PolylineType, PolygonType, RectangleType, EllipseType, TextType, SquareType, CircleType};

/**shape class
@brief - shape class that is base
*/
class Shape : public QPainter
{
    public:
        QPainter painter; /**<painter variable*/

        QPen penType;/**<pen variable*/

        QBrush brushType; /**<brush variable*/

        /** gets the shape
        @return shapeType - returns the shape type
        */
        ShapeType getShape() const {return shapeType;}

        /** gets the ID
        @return shape_ID - returns the shape ID
        */
        int getId() const {return shape_ID;}

        /** gets the pen
        @return penType - returns the pen type
        */
        QPen getPen() const {return penType;}

        /** Constructor
        @param device - set to null pointer
        @param id - set to -1
        @param shape - set to no shape
        */
        Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape) :

             QPainter(device), shape_ID(id), shapeType(shape){}
             
        /** Sets the shape type
        @param s - shape type
        */
        void setShape(ShapeType s) {shapeType = s;}
        
        /** sets the ID
        @param _id - ID
        */
        void setId(int _id) {shape_ID = _id;}
        
        /** Sets the Pen
        @param color - color of the pen
        */
        void setPen(Qt::GlobalColor color);
        
        /** Sets the Pen
        @param pen - pen type
        */
        void setPen(QPen pen){penType = pen;}
        
        /** Sets the Pen
        @param GlobalColor - color
        @param width - the width of the pen
        @param PenStyle - the style of the pen
        @param PenCapStyle - the style cap of the pen
        @param PenJoinStyle - the join style of the pen
        */
        void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
        
        /** Sets the Brush
        @param GlobalColor - color
        @param BrushStyle - style of the brush*/
        void setBrush(Qt::GlobalColor, Qt::BrushStyle);
        
        /** Sets the Brush
        @param brush - brush object
        */
        void setBrush(QBrush brush){brushType = brush;}
        
        /** Returns the brush type.
        @return brushType - returns the brush type
        */
        QBrush getBrush() {return brushType;}
        
        /** Destructor */
        virtual ~Shape() {}

        /** draws the device
        @param device - the device to draw
        */
        virtual void draw(QPaintDevice *device)= 0;

        /** moves the shape
        @param x - x coordinate
        @param y - y coordinate
        @param coordNum - coordinate number
        */
        virtual void move(const int x, const int y, int coordNum) = 0;

        /** sets the perimeter*/
        virtual double perimeter() = 0;

        /** sets the area */
        virtual double area() = 0;

    private:
        int shape_ID; /**<shape ID*/
        ShapeType shapeType; /**<shape type enum*/

};

/**line class
@brief - line class that derived from shape base
*/
class Line : public Shape
{
    public:
        /** Copy constructor
        @param device - the device set to nullptr
        @param id - set to -1
        */
        Line(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::LineType) {}

        /** destructor */
        ~Line() override {}

        /** sets the points
        @param begin - the beginning
        @param end - the end
        */
        void setPoints(const QPoint& begin, const QPoint& end);

        /** draws the shape
        @param device - the device to draw
        */
        virtual void draw(QPaintDevice *device) override
        {
            painter.begin(device);
            painter.setPen(penType);
            painter.setBrush(brushType);
            painter.drawLine(begin,end);
            painter.drawText(begin,QString::number(getId()));
            painter.end();
        }
        
        /** moves the object
        @param x - x coordinate
        @param y - y coordinate
        @param coordNum - the coordinate number
        */
        void move(const int x, const int y, int coordNum) override;

        /** sets the perimeter
        @return 0 - returns the perimeter as set to 0
        */
        double perimeter() override {return 0;}

        /** sets the area
        @return 0 - returns the area as 0
        */
        double area() override {return 0;}

        /** gets the beginning point
        @return begin - returns the beginning point
        */
        QPoint& getBeginPoint() { return begin;}

        /** gets the end point
        @return end - returns the ending point
        */
        QPoint& getEndPoint() {return end;}

    private:
        QPoint begin;/**<begin coord*/
        QPoint end;/**<begin coord*/

};

/**polyline class
@brief - polyline class that derived from shape base
*/
class Polyline : public Shape
{
    public:
        /** constructor */
        Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::PolylineType) {}
        
        /** destructor */
        ~Polyline()  override {}

        /** adds point
        @param point - point being added
        */
        void addPoint(const QPointF& point);

        /** adds num points
        @param numIn - number input
        */
        void addNumPoints(int numIn){ numPoints = numIn;}

        /** draws the object
        @param device - device to draw
        */
        virtual void draw(QPaintDevice *device) override
        {
            painter.begin(device);
            for(int i = 0; i < numPoints; i++)
            {
                polyLinePointsAr[i] = points[i];
            }
            painter.setPen(penType);
            painter.setBrush(brushType);
            painter.drawPolyline(polyLinePointsAr, numPoints);
            painter.drawText(points[0],QString::number(getId()));
            painter.end();
        }

        /** moves the object
        @param x - x coordinate
        @param y - y coordinate
        @param coordNum - the coordinate number
        */
        void move(const int x, const int y, int coordNum) override;
        
        /* gets perimeter
        @return perimeter - returns perimeter
        */
        double perimeter() override {return 0;}
        
        /* gets area
        @return area - returns area
        */
        double area() override {return 0;}
        
        /* gets points
        @return points - returns vector type points
        */
        vector<QPointF>& getPoints() {return points;}

        /* gets the num points
        @return numPoints - returns numPoints
        */
        int getNumPoints() {return numPoints;}

    private:
        vector<QPointF> points;/**<coordinate points*/
        int numPoints; /**<number of coord*/
        QPointF polyLinePointsAr[8]; /**<coordinate points as array*/

};

/**polygon class
@brief - polygon class that derived from shape base
*/
class Polygon : public Shape
{
    public:
        /** constructor */
        Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::PolygonType) {}

        /** destructor */
        ~Polygon() override {}

        /** adds point
        @param point - point that is being added
        */
        void addPoint(const QPointF& point);

        /** adds num points
        @param numIn - number being set to numPoints
        */
        void addNumPoints(int numIn){ numPoints = numIn;}

        /** draws the shape
        @param device - device to draw
        */
        virtual void draw(QPaintDevice *device) override
        {
            painter.begin(device);
            for(int i = 0; i < numPoints; i++)
            {
                polygonPointsAr[i] = points[i];
            }
            painter.setPen(penType);
            painter.setBrush(brushType);
            painter.drawPolygon(polygonPointsAr, numPoints);
            painter.drawText(points[0],QString::number(getId()));
            painter.end();
        }
        /** moves the object
        @param x - x coordinate
        @param y - y coordinate
        @param coordNum - the coordinate number
        */
        void move(const int x, const int y, int coordNum) override;
        
        /* gets perimeter
        @return perimeter - returns perimeter
        */
        double perimeter() override;
        
        /* gets area
        @return area - returns area
        */
        double area() override;
        
        /* gets points
        @return points - returns vector type points
        */
        vector<QPointF>& getPoints() { return points;}

        /* gets numPoints
        @return numPoints - returns numPoints
        */
        int getNumPoints() {return numPoints;}

    private:
        vector<QPointF> points; /**<coordinate points*/
        int numPoints; /**<number coordinate points*/
        QPointF polygonPointsAr[8]; /**<coordinate points as array*/

};

/**rectangle class
@brief - rectangle class that derived from shape base
*/
class Rectangle : public Shape
{
    public:
        /** constructor */
        Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::RectangleType) {}

        /** destructor */
        ~Rectangle() override {}

        /** sets the position
        @param point - point to be set to position
        */
        void setPosition(const QPoint& point) {position = point;}

        /** sets the dimensions
        @param width - width of the rectangle
        @param height - height of the triangle
        */
        void setDimensions(int width, int height);

        /** draws the rectangle
        @param device - the shape
        */
        void draw(QPaintDevice* device) override
        {
            painter.begin(device);
            painter.setPen(penType);
            painter.setBrush(brushType);
            painter.drawRect(position.x(),position.y(), width,height);
            painter.drawText(position,QString::number(getId()));
            painter.end();
        }
        
        /* gets perimeter
        @return perimeter - returns perimeter
        */
        double perimeter() override;
        
        /* gets area
        @return area - returns area
        */
        double area() override;
        
        /** moves the object
        @param x - x coordinate
        @param y - y coordinate
        @param coordNum - the coordinate number
        */
        void move(const int x, const int y, int coordNum) override;

        /** gets the position
        @return - returns the position
        */
        QPoint& getPosition() {return position;}

        /** gets the width
        @return width - width of the rectangle
        */
        int getWidth() {return width;}

        /** gets the height
        @return height - height of the rectangle
        */
        int getHeight() {return height;}

    private:
        QPoint position; /**<position*/
        int width/**<width*/, height; /**<height*/

};

/**ellipse class
@brief - ellipse class that derived from shape base
*/
class Ellipse : public Shape
{
    public:
        /** constructor*/
        Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::EllipseType) {}

        /** destructor */
        ~Ellipse() override {}

        /** sets the position */
        void setPosition(const QPointF& point) {position = point;}

        /** sets the dimensions
        @param width - width of the ellipse
        @param height - height of the ellipse
        */
        void setDimensions(float width, float height) {this->width = width; this->height = height;}

        /** draws the ellips
        @param device - device being used
        */
        void draw(QPaintDevice *device) override
        {
            painter.begin(device);
            painter.setPen(penType);
            painter.setBrush(brushType);
            painter.drawEllipse(position.x(), position.y(),width,height);
            painter.drawText(position,QString::number(getId()));
            painter.end();
        }
        /* gets perimeter
        @return perimeter - returns perimeter
        */
        double perimeter() override;
        
        /* gets area
        @return area - returns area
        */
        double area() override;
        
        /** moves the object
        @param x - x coordinate
        @param y - y coordinate
        @param coordNum - the coordinate number
        */
        void move(const int x, const int y, int coordNum) override;

        /** gets the position of the ellips
        @return position - returns the position
        */
        QPointF& getPosition() {return position;}

        /** gets the width of the ellipse
        @return width - returns the width
        */
        double getWidth() {return width;}

        /** gets the height
        @return height - returns the height
        */
        double getHeight() {return height;}

    private:
        QPointF position; /**<position*/
        double width/**<width*/, height;/**<height*/

};

/**text class
@brief - text class that derived from shape base
*/
class Text: public Shape
{
    public:
        Text(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::TextType) {}

        ~Text() override {}

        void setPosition(const QPoint& point) {position = point;}

        void setDimensions(int w, int h);

        void draw(QPaintDevice* device) override
        {
            painter.begin(device);
            painter.setFont(font);
            painter.setPen(penType);
            painter.drawText(position.x(), position.y(), width, height, alignmentFlags, text);
            painter.drawText(position,QString::number(getId()));
            painter.end();
        }
        /** moves the object
        @param x - x coordinate
        @param y - y coordinate
        @param coordNum - the coordinate number
        */
        void move(const int x, const int y, int coordNum) override;
        
        /* gets area
        @return area - returns area
        */
        double area() override;

        /* gets perimeter
        @return perimeter - returns perimeter
        */
        double perimeter() override;
        
        /** sets the alignment
        @param flags - alignment
        */
        void setAlignment(Qt::AlignmentFlag flags);

        /** sets the font
        @param fontFamIn - Times New Roman, etc.
        @param fontStyleIn - Italic, Bold, etc.
        @param pointSizeIn - how big the font is
        @param weightIn - how thick the font is
        @param colorIn - what color the text is
        */
        void setFont(QString fontFamIn, QFont::Style fontStyleIn, int pointSizeIn, QFont::Weight weightIn, Qt::GlobalColor colorIn);

        /** sets the font
        @param fontIn - the font to be set
        */
        void setFont(QFont fontIN){font = fontIN;}

        /** sets the text
        @param textIn - text to be set
        */
        void setText(const QString& textIn);

        /** sets the position of the text
        @param x - x coordinate
        @param y - y coordinate
        */
        void setPosition(int x, int y);

        /** gets the font */
        QFont& getFont();

        /** gets the alignment */
        Qt::AlignmentFlag getAlignment() const;

        /** gets the text */
        QString getText() const;

        /** gets the position
        @return position - returns the position
        */
        QPoint getPosition() {return position;}

        /** gets the width of the text
        @return width - width of the text
        */
        int getWidth() {return width;}

        /** gets the height of the text
        @return height - height of the text
        */
        int getHeight() {return height;}

    private:
        QPoint            position; /**<position*/
        int               width; /**<width*/
        int               height; /**<height*/
        QFont             font; /**<font*/
        QString           text; /**<text*/
        Qt::AlignmentFlag alignmentFlags; /**<alignment flags*/


};

#endif // SHAPE_H
