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

/*!The Shape Class is the base abstract data type for the 2-D Modeling shape hierarchy. The Shape class is an abstract data type as the functions void move, void draw, double perimeter, and double area are all pure virtual functions. The Shape Class has public inheritance from the QPainter class. The QPainter Class contains various methods that allows any classes inheriting from the it have drawing attributes and other functionality. The QPainter performs low level painting on widgets and other paint devices.
*/


class Shape : public QPainter{
public:

    //!QPainter Object
    /*!QPainter is a distinct class that performs low-level paintings on widgets and other paint devices. */
    QPainter painter;

    //!QPen Object
    /*!QPen is a distinct class that defines how QPainter should draw line and outlines of shapes. */
    QPen     pen;

    //!QBrush Object
    /*!QBrush is a distinct class that defines the fill pattern of shapes drawn by QPainter. */
    QBrush   brush;

    //!Enumeration of ShapeType classes
    /*!This enumeration is used when reading to and from a shape file. */
    enum class ShapeType{null,Line,Polyline,Polygon,Rectangle,Ellipse,Text};

    //!Shape Class constructor takes in 3 arguments.
    /*!
    \param *device is a pointer to an object of type QPaintDevice, initialized to nullptr to avoid conflict.
    \param ID is a variable of type int that gives a shape a unique identification.
    \param shapey is of an enum type ShapeType
    */
    Shape(QPaintDevice *device = nullptr, int ID = -1, ShapeType shapey = ShapeType::null);

    //!Shape Class Destructor
    /*!Deallocates any dynamic memory, shape class is an abstract base class that uses virtual functions, therefore shape destructor must be virtual. */
    virtual ~Shape(){}

    //!setShape takes in a ShapeType argument
    /*!The passed in argument must be of ShapeType. setShape sets shape to the ShapeType argument.
    The passed in argument must be of ShapeType. setShape sets shape to the ShapeType argument being passed in.
    ShapeType is an enum containing multiple types of shapes.
    */
    void setShape(ShapeType);

    //!setBrush takes in two Qt type parameters and sets it equal to member variable object shape.
    /*!setBrush function takes in built-in Qt::GlobalColor and Qt::BrushStyle, which are Qt namespaces, and sets brush equal to QBrush(gc, bs).
    QBrush(gc, bs) calls the constructor of QBrush which is a built-in class that defines the fill pattern for shapes.
    */
    void setBrush(Qt::GlobalColor, Qt::BrushStyle);

    //!setPen takes in two built-in Qt namespaces.
    /*!setPen function takes in built-in Qt::GlobalColor and sets brush equal to QPen(gc).
    QPen(gc) calls the constructor of QPen which is a built-in class that defines the lines and outlines of the shapes.
    */
    void setPen(Qt::GlobalColor);

    //!Alternative setPen sets pen equal to four Qt type parameters and one int parameter.
    /*!Alternative setPen takes in built-in Qt::GlobaColor, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, and int width and sets pen equal to QPen(gc, width, ps, pcs, pjs).
    QPen(gc, width, ps, pcs, pjs) calls the constructor of QPen which is a built-in class that defines the lines and outlines of the shapes.
    */
    void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);

    //!setBrush takes in a QBrush variable and sets brush to brsh
    /* \param brsh is of type QBrush */
    void setBrush(QBrush brsh){brush = brsh;}

    //!setPen takes in a QPen variable and sets pen to pn
    /* \param pn is of type QPen */
    void setPen(QPen pn)      {pen   = pn;}

    //!setID takes in a int ID and sets id to ID
    /* \param ID  is of type int */
    void setID(int ID)        {id    = ID;}

    //!getShape returns shape object.
    ShapeType     getShape() const {return shape;}

    //!getBrush returns brush object.
    const QBrush &getBrush() const {return brush;}

    //!getPen returns pen object.
    const QPen   &getPen()   const {return pen;}

    //!getID returns id variable.
    int           getID()    const {return id;}

    //!setDefaultStyle sets pen and brush member objects to a "default setting" provided by Qt namespaces.
    /*!Qt::GlobalColor and Qt::BrushStyle are used to set pen and brush.  */
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
    \param *device is a pointer of type QPaintDevice
    */
    virtual void draw(QPaintDevice *device) = 0;

    //!Pure Virtual perimeter function
    /*!No default parameters */
    virtual double perimeter() = 0;

    //!Pure Virtual area function
    /*!No default parameters */
    virtual double area() = 0;

protected:

    //!getPainter returns member object painter.
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
    The class member variable numVerts is set equal to numVertices
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

    //!function to return points to make shapes.
    AwesomeVector<QPoint>& getVertices();

private:

    //!vector of type QPoint which holds vertices to make polygon.
    AwesomeVector<QPoint> vertVect;

    //!Array of type QPoint, contains number of vertices for polygon
    QPoint vertsArray[DEFAULT_NUM_VERTS];

    //!Variable to store the number of vertices in polygon
    int     numVerts;
};



//!Line Class: Public Inheritance from Shape Class
class Line : public Shape{

public:

    //!Line Class Constructor
    /*!Line Class constructor takes in two parameters
    \param *device is a pointer of type QPaintDevice, initialized to nullptr to avoid conflicts
    \param id is of type int
    */
    Line(QPaintDevice* device = nullptr, int id = -1);

    //!Line Class Destructor
    ~Line() override {}

    //!setPoints function for Line
    /*!setPoints function allows the line to be set with given starting and ending points
    The class member variables line_begin and line_end are set to parameters x,y
    \param x is a constant reference of type QPoint
    \param y is a constant reference of type QPoint
    */
    void setPoints(const QPoint& x, const QPoint& y){line_begin = x; line_end = y;}

    //!move function to move a line
    /*!move function overrides the virtual move from abstract base class Shape. Function does not return any type.
    \param x is of type constant int
    \param y is of type constant int
    \param vert is of type int
    */
    virtual void move(const int x, const int y, int vert) override;

    //!draw function to draw a line
    /*!draw function overrides the virtual draw from abstract base class shape. Funtion does not return any type.
    \param *device is a pointer of type QPaintDevice
    */
    virtual void draw(QPaintDevice* device) override;

    //!perimeter function to calculate perimeter of a line
    /*!perimeter function overrides the virtual perimeter function of abstract base class shape. Function returns a double.
    No parameters are passed into perimeter, line does not have perimeter so the function is defined only by "return 0".
    Function definition must be defined as return 0, else line class will be recognized as an abstract class.
    */
    virtual double perimeter() override {return 0;}

    //!area function to calculate area of a line
    /*!area function overrides the virtual area function of abstract base class shape. Function returns a double.
    No parameters are passed into area, line does not have area so the function is defined only by "return 0".
    Function definition must be defined as return 0, else line class will be recognized as an abstract class.
    */
    virtual double area() override {return 0;}

private:

    //!line_begin is of type QPoint, used to set beginning of line
    QPoint line_begin;

    //!line_end is of type QPoint, used to set end of line
    QPoint line_end;
};



const int DEFAULT_NUM_PTS = 8;

//!Polyline Class: Public Inheritance from Shape Class
class Polyline : public Shape
{
public:

    //!Polyline Class constructor
    /*!Polyline Class constructor takes in two arguments
    \param *device is a pointer of type QPaintDevice, initialized to nullptr to avoid conflict
    \param id is of type int
    */
    Polyline(QPaintDevice* device = nullptr, int id = -1);

    //!Polyline Class destructor
    ~Polyline()  override {}


    //!addPoint function to add points to a polyline
    /*!addPoint takes in at most one argument
    \param pt is a constant reference of type QPoint
    */
    void addPoint(const QPoint& pt);

    //!addNumPoints function to set class member variable numPts, takes in an int
    /*!\param is an int */
    void addNumPoints(int num) {numPts = num;}


    //!draw function to draw a polyline
    /*!draw function overrides the virtual draw from abstract base class shape. Funtion does not return any type.
    \param *device is a pointer of type QPaintDevice
    */
    virtual void draw(QPaintDevice *device) override;

    //!move function to move a polyline
    /*!move function overrides the virtual move from abstract base class Shape. Function does not return any type.
    \param x is of type int
    \param y is of type int
    \param vertex is of type int
    */
    void move(int x, int y, int vertex) override;

    //!perimeter function to calculate perimeter of a polyline
    /*!perimeter function overrides the virtual perimeter function of abstract base class shape. Function returns a double.
    No parameters are passed into perimeter, polyline does not have perimeter so the function is defined only by "return 0".
    Function definition must be defined as return 0, else line class will be recognized as an abstract class.
    */
    double perimeter() override {return 0;}

    //!area function to calculate area of a polyline
    /*!area function overrides the virtual area function of abstract base class shape. Function returns a double.
    No parameters are passed into area, polyline does not have area so the function is defined only by "return 0".
    Function definition must be defined as return 0, else line class will be recognized as an abstract class.
    */
    double area() override {return 0;}


    //!function to return points to make shapes.
    AwesomeVector<QPoint>& getPoints() {return pts;}

    //!getNumPoints returns the number of points within polyline
    int getNumPoints() {return numPts;}

private:

   //!Vector to hold points of type QPoint to make shape.
    AwesomeVector<QPoint> pts;

    //!numPts is of type int and tells us how many points the shape contains.
    int numPts;

    //!pointsAr is an array of type QPoint, stores the points of polyline
    QPoint pointsAr[DEFAULT_NUM_PTS];
};



//!Text Class: Public Inheritance From Shape Class
class Text : public Shape
{
public:

    //!Text Class Constructor
    /*!Text Class constructor takes in 2 arguments
    \param *dev is a pointer of type QPaintDevice, initialized to nullptr to avoid conflict.
    \param id is of type int
    */
    Text(QPaintDevice* dev = nullptr, int id = -1);

    //Text Class Destructor
    ~Text() override {}


    //!draw function to draw a text
    /*!draw function overrides the virtual draw from abstract base class shape. Funtion does not return any type.
    \param *dev is a pointer of type QPaintDevice
    */
    void draw(QPaintDevice *dev)      override;

     //!move function to move a text
    /*!move function overrides the virtual move from abstract base class Shape. Function does not return any type.
    \param x is of type int
    \param y is of type int
    \param junk is of type int
    */
    void move(int x, int y, int junk) override;


    //!area function to calculate area of a text
    /*!area function overrides the virtual area function of abstract base class shape. Function returns a double.
    No parameters are passed into area.
    */
    double area()      override;

    //!perimeter function to calculate permiter of a text
    /*!perimeter function overrides the virtual perimter function of abstract base class shape. Function returns a double.
    No parameters are passed into area.
    */
    double perimeter() override;


    //!setText function to set the font of the text
    /*!setText requires a QString parameter
    \param newText is of type QString
    */
    void setText(QString newText);

    //!setBoxWidth function
    /*!setBoxWidth sets class member variable boxWidth to parameter newBoxWidth.
    \param newBoxWidth is of type int
    */
    void setBoxWidth(int newBoxWidth);

    //!setBoxHeight function
    /*setBoxHeigt sets class member variable boxHeight to parameter newBoxHeight.
    \param newBoxHeight is of type int
    */
    void setBoxHeight(int newBoxHeight);

    //!setFlag function
    /*setFlag function sets the Qt attribute AlignmentFLag to flag
    \param flag is of type Qt::AlignmentFlag
    */
    void setFlag(Qt::AlignmentFlag flag);

    //!setLocation function for text
    /*!setLocation function requires two arguments. Takes the two arguments and makes a coordinate pair consisting of these values.
    \param x is of type int
    \param y is of type int
    */
    void setLocation(int x, int y);

    //!SetLocation function for text
    /*!setLocation function requires a single parameter. The class memeber variable location is set to the QPoint parameter passed in.
    \param pt is of type QPoint
    */
    void setLocation(QPoint pt);

    //!setDimensions function for text
    /*!setDimensions function requires two parameters. The class member variables boxWidth and boxHeight are set from these parameters.
    \param w is of type int
    \param h is of type int
    */
    void setDimensions(int w, int h);

    //!getFont function returns the font of the text.
    QFont& getFont();

    //!getFlag function returns the horizontal or vertical flag.
    Qt::AlignmentFlag getFlag();

    //!getText returns the text object which provides a unicode character string.
    QString getText();

private:

    //!text is of type QString. QString provides a unicode character string
    QString text;

    //!font is of type QFont. QFont specifies a font used for drawing text.
    QFont   font;

    //!flag is of type AlignmentFlag
    /*!AlignmentFlag is an enum contains horizontal and vertical flags that can be combined to produce the required effect. */
    Qt::    AlignmentFlag flag;

    //!boxWidth is of type int
    int     boxWidth;

    //!boxHeight is of type int
    int     boxHeight;

    //!location of type QPoint
    QPoint location;
};


//!Rectangle Class: Public Inheritance from Shape Class
class Rectangle : public Shape
{
public:

    //!Rectangle Class Constructor
    /*!Rectangle Class constructor takes in two arguments.
    \param *device is a pointer of type QPaintDevice, initialized to nullptr to avoid conflict
    \param id is of type int
    */
    Rectangle(QPaintDevice *device = nullptr, int id = -1);

    //!Rectangle Class Destructor
    ~Rectangle() override {}

    //!draw function to draw a rectangle
    /*!draw function overrides the virtual draw from abstract base class shape. Funtion does not return any type.
    \param *device is a pointer of type QPaintDevice
    */
    void draw(QPaintDevice *device) override;

    //!move function to move a rectangle
    /*!move function overrides the virtual move from abstract base class Shape. Function does not return any type.
    \param x is of type int
    \param y is of type int
    \param junk is of type int
    */
    void move(int x, int y, int junk) override;

    //!area function to calculate area of rectangle
    /*!area function overrides the virtual area function of abstract base class shape. Function returns a double.
    No parameters are passed into area.
    */
    double area() override;

    //!perimeter function to calculate perimeter of rectangle
    /*!perimeter function overrides the virtual perimeter function of abstract base class shape. Function returns a double.
    No parameters are passed into perimeter.
    */
    double perimeter() override;

    //!setLocation function for rectangle
    /*!setLocation function requires two arguments. Takes the two arguments and makes a coordinate pair (QPoint) consisting of these values.
    \param x is of type int
    \param y is of type int
    */
    void setLocation(int x, int y);

    //!setLocation function for rectangle
    /*!setLocation function requires a single parameter. The class memeber variable location is set to the QPoint parameter passed in.
    \param pt is of type QPoint
    */
    void setLocation(QPoint pt);

    //!setDimensions function for rectangle
    /*!setDimensions function requires two parameters. The class member variables width and height are set from these parameters.
    \param w is of type double
    \param h is of type double
    */
    void setDimensions(double w, double h);

    //setAll function for rectangle
    /*!setAll function requires four parameters. The class member functions width, height, location are set from these arguments. In this function, the setLocation and setDimension functions are being called.
    \param w is of type double
    \param h is of type double
    \param x is of type int
    \param y is of type int
    */
    void setAll(double w, double h, int x, int y);

    //!getWidth function for rectangle class, function returns a double width
    double getWidth();

    //!getHeight function for rectangle class, function returns a double height
    double getHeight();

    //!getLocation function for rectangle class, function returns a QPoint location
    QPoint& getLocation();

private:

    //!width is of type double
    double width;

    //!height is of type double
    double height;

    //!location is of type QPoint
    QPoint location;
};



//!Ellipse Class: Public Inheritance from Shape Class
class Ellipse :public Shape
{
public:

    //!Ellipse Class constructor
    /*!Ellipse constructor requires two parameters.
    \param *device is a pointer of type QPaintDevice, initialized to nullptr to avoid conflict
    \param id is of type int
    */
    Ellipse(QPaintDevice* device = nullptr, int id = -1);

    //!Ellipse Class destructor
    ~Ellipse() override {}


    //!move function to move an ellipse
    /*!move function overrides the virtual move from abstract base class Shape. Function does not return any type.
    \param x is of type int
    \param y is of type int
    \param na is of type int
    */
    void move(int x, int y, int na) override;

    //!draw function to draw an ellipse
    /*!draw function overrides the virtual draw from abstract base class shape. Funtion does not return any type.
    \param *device is a pointer of type QPaintDevice
    */
    void draw(QPaintDevice* device) override;

    //!area function to calculate area of ellipse
    /*!area function overrides the virtual area function of abstract base class shape. Function returns a double.
    No parameters are passed into area.
    */
    double area()      override;

    //!perimeter function to calculate perimeter of ellipse
    /*!perimeter function overrides the virtual perimeter function of abstract base class shape. Function returns a double.
    No parameters are passed into area.
    */
    double perimeter() override;

    //!getWidth function for ellipse class, function returns a double width
    double getWidth();

    //!getHeight function for ellipse class, function returns a double height
    double getHeight();

    //!getLocation function for ellipse class, function returns a QPoint location
    QPoint& getLocation();

    //!setDimensions function for ellipse
    /*!setDimensions function requires two parameters. The class member variables width and height are set from these parameters.
    \param w is of type double
    \param h is of type double
    */
    void setDimensions(double w, double h);

    //!setLocation function for ellipse
    /*!setLocation function requires two arguments. Takes the two arguments and makes a coordinate pair (QPoint) consisting of these values.
    \param x is of type int
    \param y is of type int
    */
    void setLocation(int x, int y);

    //!setLocation function for ellipse
    /*!setLocation function requires a single parameter. The class memeber variable location is set to the QPoint parameter passed in.
    \param pt is of type QPoint
    */
    void setLocation(QPoint pt);

private:

    //!width is of type double
    double width;

    //!height is of type double
    double height;

    //!location is of type QPoint
    QPoint location;
};


#endif // SHAPE_H
