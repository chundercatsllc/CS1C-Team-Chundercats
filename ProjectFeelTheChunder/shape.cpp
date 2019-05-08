#include "shape.h"

Shape::Shape(QPaintDevice *device, int id, ShapeType shape):painter{device},id{id},shape{shape}{
    pen   = Qt::SolidLine;
    brush = Qt::NoBrush;
}
/*
const Shape& Shape::operator=(const Shape& other)
{
    painter = other.painter;
    pen     = other.pen;
    brush   = other.brush;
    id      = other.id;
    shape   = other.shape;
}*/
void Shape::setShape(ShapeType st){
	this->shape=st;
}
void Shape::setBrush(Qt::GlobalColor gc, Qt::BrushStyle bs){
	brush=QBrush(gc, bs);
}
void Shape::setPen(Qt::GlobalColor gc){
	pen=QPen(gc);
}
void Shape::setPen(Qt::GlobalColor gc, int width, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs){
	pen=QPen(gc, width, ps, pcs, pjs);
}
void Shape::setDefaultStyle(){
	pen=Qt::SolidLine;
	brush=Qt::NoBrush;
	painter.setPen(Qt::SolidLine);
	painter.setBrush(Qt::NoBrush);
}
QPainter &Shape::getQPainter(){
	return painter;
}

Line::Line(QPaintDevice *device, int id) : Shape(device, id, ShapeType::Line), line_begin(1,1), line_end(1,1)
{

}

void Line::move(const int x, const int y, int vert)
{
    QPoint temp(x, y);
    switch(vert)
    {
        case 1: line_begin = temp;
            break;
        case 2:   line_end = temp;
            break;
        default: {}
    }
}

void Line::draw(QPaintDevice *device)
{
    painter.begin(device);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawLine(line_begin,line_end);
    painter.drawText(line_begin,QString::number(getID()));
    painter.end();
}

Polyline::Polyline(QPaintDevice *device, int id) : Shape(device, id, ShapeType::Polyline), pts(DEFAULT_NUM_PTS)
{
    numPts = DEFAULT_NUM_PTS;
}

void Polyline::draw(QPaintDevice * dev)
{
    painter.begin(dev);
    for(int i = 0; i < numPts; i++)
        pointsAr[i] = pointsAr[i];
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPolyline(pointsAr, numPts);
    painter.drawText(pointsAr[0],QString::number(getID()));
    painter.end();
}

void Polyline::addPoint(const QPoint &pt)
{
    pts.push_back(pt);
    numPts++;
    if(numPts < DEFAULT_NUM_PTS)
        pointsAr[numPts] = pt;
}

void Polyline::move(int x, int y, int vertex)
{
    QPoint temp(x,y);
    if(vertex <= numPts)
    {
        pointsAr[vertex - 1] = temp;
        pts.set(vertex - 1, temp);
    }
    else {
        qDebug() << "unable to move polyline";
    }
}

Polygon::Polygon(QPaintDevice *device, int id) : Shape(device, id, ShapeType::Polygon), vertVect(DEFAULT_NUM_VERTS)
{
    numVerts = 0;
}

void Polygon::draw(QPaintDevice *device)
{
    painter.begin(device);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawConvexPolygon(vertsArray, numVerts);
    painter.drawText(vertsArray[0] ,QString::number(getID()));
    painter.end();
}

double Polygon::area()
{
    double area = 0;

    for(int i = 0; i < vertVect.sizeOf(); i++)
    {
        if(i == vertVect.sizeOf()-1)
        {
            area += vertVect[i].x() * vertVect[0].y();
            area -= vertVect[i].y() * vertVect[0].x();

        }
        else
        {
            area += vertVect[i].x() * vertVect[i+1].y();
            area -= vertVect[i].y() * vertVect[i+1].x();

        }

    }
    return (qAbs(area) / 2);
}

double Polygon::perimeter()
{
    double perimeter = 0;

    for(int i = 0; i < vertVect.sizeOf()-1; i++)
    {
        perimeter += (qSqrt((vertVect[i+1].x() - vertVect[i].x()) * (vertVect[i+1].x() - vertVect[i].x())
                  +  (vertVect[i+1].y() - vertVect[i].y()) * (vertVect[i+1].y() - vertVect[i].y())));

    }
    return perimeter;
}

void Polygon::move(const int x, const int y, int vertex)
{
    QPoint temp(x,y);
    if(vertex <= numVerts)
    {
        vertVect.set(vertex - 1, temp);
        vertsArray[vertex - 1] = temp;
    }
    else {
        qDebug() << "unable to move polyline";
    }

}

void Polygon::setNumVertices(int numVertices)
{
    if(numVertices > 0 && numVertices < 8)
        numVerts = numVertices;
    else
        qDebug() << "Number of vertices is invalid";
}

void Polygon::addVertex(const QPoint &vertex)
{
    vertVect.push_back(vertex);
    vertsArray[numVerts] = vertex;
    numVerts++;
}

int Polygon::getNumVertices()
{
    return numVerts;
}

AwesomeVector<QPoint> & Polygon::getVertices()
{
    return vertVect;
}

Text::Text(QPaintDevice* dev, int id) : Shape(dev, id, ShapeType::Text), location(1, 1)
{
    text  = "empty";
}

void Text::draw(QPaintDevice *device)
{
    painter.begin(device);
    painter.setFont(font);
    painter.setPen(pen);
    painter.drawText(location.x(), location.y(), boxWidth, boxHeight, flag, text);
    painter.drawText(location,QString::number(getID()));
    painter.end();
}

double Text::area()
{
    return double(boxWidth * boxHeight);
}

QFont& Text::getFont()
{
    return font;
}

Qt::AlignmentFlag Text::getFlag()
{
    return flag;
}

QString Text::getText()
{
    return text;
}

void Text::move(const int x, const int y, int junk)
{
    QPoint temp(x, y);
    location = temp;
}

double Text::perimeter()
{
    return 2.0 * (boxWidth + boxHeight);
}

void Text::setFlag(Qt::AlignmentFlag flags)
{
    flag = flags;
}

void Text::setDimensions(int w, int h)
{
    boxWidth = w;
    boxHeight = h;
}

void Text::setFont(QString family, QFont::Style style, int size, QFont::Weight weight, Qt::GlobalColor color)
{
    font.setFamily(family);
    font.setStyle(style);
    font.setPointSize(size);
    font.setWeight(weight);
    pen.setColor(color);
}

void Text::setLocation(int x, int y)
{
    location = { x, y };
}

void Text::setText(QString newText)
{
    text = newText;
}

void Text::setLocation(QPoint pt)
{
    location = pt;
}

Ellipse::Ellipse(QPaintDevice *dev, int id) : Shape(dev, id, ShapeType::Ellipse), location(1,1)
{
    width = 1;
    height = 1;
}

void Ellipse::draw(QPaintDevice *device)
{
    painter.begin(device);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(location.x(), location.y(), width, height);
    painter.drawText(location,QString::number(getID()));
    painter.end();
}

void Ellipse::move(int x, int y, int na)
{
    QPoint temp(x,y);
    location = temp;
}

double Ellipse::area()
{
    return width * height * M_PI;
}

double Ellipse::perimeter()
{
    return 3 * M_PI * (width + height) - qSqrt((3 * width + height) * (width + 3 * height));
}

double Ellipse::getWidth()
{
    return width;
}

double Ellipse::getHeight()
{
    return height;
}

QPoint& Ellipse::getLocation()
{
    return location;
}

void Ellipse::setDimensions(int w, int h)
{
    if(w > 0 && h > 0)
    {
        width  = w;
        height = h;
    }
    else
        qDebug() << "Width and height have to be positive";
}

void Ellipse::setLocation(int x, int y)
{
    QPoint temp(x, y);
    location  = temp;
}

void Ellipse::setLocation(QPoint pt)
{
    location = pt;
}

Rectangle::Rectangle(QPaintDevice *device, int id) : Shape(device, id, ShapeType::Rectangle), location(1,1)
{
    width = 1;
    height = 1;
}

void Rectangle::draw(QPaintDevice *device)
{
    painter.begin(device);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(location.x(), location.y(), width, height);
    painter.drawText(location ,QString::number(getID()));
    painter.end();

}

void Rectangle::move(int x, int y, int junk)
{
    QPoint temp(x,y);
    location = temp;
}

double Rectangle::area()
{
    return width * height;
}

double Rectangle::perimeter()
{
    return 2 * width + 2 * height;
}

void Rectangle::setLocation(int x, int y)
{
    QPoint temp(x, y);
    location = temp;
}

void Rectangle::setLocation(QPoint pt)
{
    location = pt;
}

void Rectangle::setDimensions(int w, int h)
{
    if(w > 0)
        width = w;
    else
        qDebug() << "Width cannot be negative.";

    if(h > 0)
        height = h;
    else
        qDebug() << "Height cannot be negative";
}

void Rectangle::setAll(int w, int h, int x, int y)
{
    setLocation(x,y);
    setDimensions(w,h);
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getHeight()
{
    return height;
}

QPoint& Rectangle::getLocation()
{
    return location;
}

