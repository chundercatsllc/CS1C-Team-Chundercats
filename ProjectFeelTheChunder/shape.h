#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPaintDevice>
#include <QString>
#include <QPoint>
#include <QPainter>
#include <QtMath>
#include <QDebug>
#include "containers/AwesomeVector.h"


//!Shape Class: Public Inheritance from QPainter Class.

/*!The Shape Class has public inheritance from the QPainter class. The QPainter Class contains various methods that allows any classes inheriting from the it have drawing attributes and other functionality. The Shape class is an abstract data type as the functions void move, void draw, double perimeter, and double area are all pure virtual functions.
*/


class Shape : public QPainter{
public:

    //!QPainter Object
    QPainter painter;

    //!QPen Object
    /*!QPen is a distinct class. */
    QPen     pen;

    //!QBrush Object
    /*!QBrush is a distinct class. */
    QBrush   brush;

    //!Enumeration of ShapeType classes
    enum class ShapeType{null,Line,Polyline,Polygon,Rectangle,Ellipse,Text};

    //!Shape Class constructor takes in 3 arguments.
    /*!
    \param *device is a pointer to an object of type QPaintDevice
    \param ID is an int
    \param shapey is of an enum type ShapeType
    */
    Shape(QPaintDevice *device = nullptr, int ID = -1, ShapeType shapey = ShapeType::null);

    //!Shape Class Destructor
    /*!Deallocates any memory stored in the heap. */
    virtual ~Shape(){}

    //!setShape takes in a ShapeType argument
    /*
    The passed in argument must be of ShapeType. setShape sets shape to the ShapeType argument.
    */
    void setShape(ShapeType);

    //!setBrush takes two
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);
    void setPen(Qt::GlobalColor);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);

    //!setBrush takes in a QBrush variable and sets brush to brsh
    /* \param brsh */
    void setBrush(QBrush brsh){brush = brsh;}

    //!setPen takes in a QPen variable and sets pen to pn
    /* \param pn */
    void setPen(QPen pn)      {pen   = pn;}

    //!setID takes in a int ID and sets id to ID
    /* \param ID */
    void setID(int ID)        {id    = ID;}


    ShapeType     getShape() const {return shape;}
    const QBrush &getBrush() const {return brush;}
    const QPen   &getPen()   const {return pen;}
    int           getID()    const {return id;}

    void setDefaultStyle();

    //!Pure Virtual move function
    /*!
    \param tX is of type const int
    \param tY is of type const int
    \param ptIndex is of type int
    */
    virtual void move(const int tX, const int tY, int ptIndex) = 0;

    //!Pure Virtual draw function
    /*!
    \param *device is of type QPaintDevice
    */
    virtual void draw(QPaintDevice *device) = 0;

    //!Pure Virtual perimeter function
    /*!No default parameters */
    virtual double perimeter() = 0;

    //!Pure Virtual area function
    /*!No default parameters */
    virtual double area() = 0;

protected:


    QPainter &getQPainter();

private:

    //!id is of type int
    int id;

    //!shape is of type ShapeType
    ShapeType shape;
};


const int DEFAULT_NUM_VERTS = 8;

//!Polygon Class: Public Inheritance from Shape Class

class Polygon : public Shape
{
public:

    //!Polygon Class constructor
    /*!
    \param *dev is a pointer of type QPaintDevice, intialized to nullptr to avoid conflicts
    \param id is of type int
    */
    Polygon(QPaintDevice* dev = nullptr, int id = -1);

    //!Polygon Class Destructor
    ~Polygon() override {}

    //!draw function to draw a Polygon
    /*!
    draw function overrides the virtual draw from abstract class Shape. Function does not return any type.
    \param *dev is a pointer of type QPaintDevice.
    */
    virtual void   draw(QPaintDevice *dev) override;

    //!move function to move a polygon
    /*!
    move function overrides the virtual move from abstract base class Shape. Function does not return any type.
    \param x is of type int
    \param y is of type int
    \param vertex is of type int
    */
    virtual void   move(int x, int y, int vertex) override;

    //!area function to calculate area of polygon
    /*!
    area function overrides the virtual area from abstract base class Shape. Function returns a double.
    area function does not take in any parameters.
    */
    virtual double area() override;

    //!perimter function to calculate perimeter of polygon
    /*!
    perimeter function overrides the virtual perimeter abstract base class Shape. Function returns a double.
    perimeter function does not take in any parameters.
    */
    virtual double perimeter() override;

    //!setNumVertices function sets the nummber of vertices for the polygon
    /*!
    numVerts is set equal to numVertices
    \param numVertices is of type int
    */
    void setNumVertices(int numVertices);

    //!getNumVertices function returns the value of numVerts.
    /*!No Parameters required, return type if of type int*/
    int  getNumVertices();

    //!function to add a vertex to a polygon
    /*!
    addVertex function requires one parameter, no type is returned by the function
    \param vertex is constant reference of type QPoint []
    */
    void addVertex(const QPoint& vertex);


    AwesomeVector<QPoint>& getVertices();

private:

    AwesomeVector<QPoint> vertVect;

    //!Array of type QPoint, contains number of vertices for polygon
    QPoint vertsArray[DEFAULT_NUM_VERTS];

    //!Variable to store the number of vertices in polygon
    int     numVerts;
};

class Line : public Shape{

public:
    Line(QPaintDevice* device = nullptr, int id = -1);
    ~Line() override {}

    void setPoints(const QPoint& x, const QPoint& y){line_begin = x; line_end = y;}

    virtual void move(const int x, const int y, int vert) override;
    virtual void draw(QPaintDevice* device) override;
    virtual double perimeter() override {return 0;}
    virtual double area() override {return 0;}

private:
    QPoint line_begin;
    QPoint line_end;
};

const int DEFAULT_NUM_PTS = 8;
class Polyline : public Shape
{
public:
     Polyline(QPaintDevice* device = nullptr, int id = -1);
    ~Polyline()  override {}

    void addPoint(const QPoint& pt);

    void addNumPoints(int num) {numPts = num;}

    virtual void draw(QPaintDevice *device) override;

    void move(int x, int y, int vertex) override;

    double perimeter() override {return 0;}

    double area() override {return 0;}

    AwesomeVector<QPoint>& getPoints() {return pts;}

    int getNumPoints() {return numPts;}
private:
    AwesomeVector<QPoint> pts;
    int numPts;
    QPoint pointsAr[DEFAULT_NUM_PTS];
};

class Text : public Shape
{
public:
     Text(QPaintDevice* dev = nullptr, int id = -1);
    ~Text() override {}

    void draw(QPaintDevice *dev)      override;
    void move(int x, int y, int junk) override;
    double area()      override;
    double perimeter() override;

    void setText(QString newText);
//    void setFont(QString family, QFont::Style style, int size, QFont::Weight weight, Qt::GlobalColor color);

    void setBoxWidth(int newBoxWidth);
    void setBoxHeight(int newBoxHeight);
    void setFlag(Qt::AlignmentFlag flag);

    void setLocation(int x, int y);
    void setLocation(QPoint pt);
    void setDimensions(int w, int h);

    QFont& getFont();
    Qt::AlignmentFlag getFlag();
    QString getText();

private:
    QString text;
    QFont   font;
    Qt::    AlignmentFlag flag;
    int     boxWidth;
    int     boxHeight;
    QPoint location;
};

class Rectangle : public Shape
{
public:
    Rectangle(QPaintDevice *device = nullptr, int id = -1);
    ~Rectangle() override {}

    void draw(QPaintDevice *device) override;
    void move(int x, int y, int junk) override;
    double area() override;
    double perimeter() override;

    void setLocation(int x, int y);
    void setLocation(QPoint pt);
    void setDimensions(double w, double h);
    void setAll(double w, double h, int x, int y);

    double getWidth();
    double getHeight();
    QPoint& getLocation();
private:
    double width;
    double height;
    QPoint location;
};

class Ellipse :public Shape
{
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1);
    ~Ellipse() override {}

    void move(int x, int y, int na) override;
    void draw(QPaintDevice* device) override;
    double area()      override;
    double perimeter() override;

    double getWidth();
    double getHeight();
    QPoint& getLocation();

    void setDimensions(double w, double h);
    void setLocation(int x, int y);
    void setLocation(QPoint pt);
private:
    double width;
    double height;
    QPoint location;
};


#endif // SHAPE_H
