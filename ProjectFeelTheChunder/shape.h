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

class Shape : public QPainter{
public:
    QPainter painter;
    QPen     pen;
    QBrush   brush;

    enum class ShapeType{null,Line,Polyline,Polygon,Rectangle,Ellipse,Text};

    Shape(QPaintDevice *device = nullptr, int ID = -1, ShapeType shapey = ShapeType::null);
    virtual ~Shape(){}

   // const Shape& operator=(const Shape& other);
    void setShape(ShapeType);
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);
    void setPen(Qt::GlobalColor);
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);

    void setBrush(QBrush brsh){brush = brsh;}
    void setPen(QPen pn)      {pen   = pn;}
    void setID(int ID)        {id    = ID;}

    ShapeType     getShape() const {return shape;}
    const QBrush &getBrush() const {return brush;}
    const QPen   &getPen()   const {return pen;}
    int           getID()    const {return id;}

    void setDefaultStyle();

    virtual void move(const int tX, const int tY, int ptIndex) = 0;
    virtual void draw(QPaintDevice *device) = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;
protected:
    QPainter &getQPainter();

private:
    int id;
    ShapeType shape;
};

const int DEFAULT_NUM_VERTS = 8;
class Polygon : public Shape
{
public:
    Polygon(QPaintDevice* dev = nullptr, int id = -1);
    ~Polygon() override {}

    virtual void   draw(QPaintDevice *dev) override;
    virtual void   move(int x, int y, int vertex) override;
    virtual double area() override;
    virtual double perimeter() override;

    void setNumVertices(int numVertices);
    int  getNumVertices();
    void addVertex(const QPoint& vertex);
    AwesomeVector<QPoint>& getVertices();
private:
    AwesomeVector<QPoint> vertVect;
    QPoint vertsArray[DEFAULT_NUM_VERTS];
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

const QString STstringAR[]  = {"Line", "Polyline", "Polygon", "Rectangle", "Ellipse", "Text", "null"};
const QString CstringAR[]   = {"White", "Black", "Red", "Green", "Blue", "Cyan", "Magenta", "Yellow", "Gray"};
const QString PSstringAR[]  = {"Solid Line", "Dash Line", "Dot Line", "Dash Dot Line", "Dash Dot Dot Line", "No Pen"};
const QString PCSstringAR[] = {"Square Cap", "Flat Cap", "Round Cap"};
const QString PJSstringAR[] = {"Bevel Join", "Miter Join", "Round Join"};
const QString BSstringAR[]  = {"No Brush", "Solid Pattern", "Horizontal Pattern", "Vertical Pattern"};
#endif // SHAPE_H
