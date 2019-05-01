#include "shape.h"

Shape::Shape(QPaintDevice *device, int id, ShapeType shape):painter{device},id{id},shape{shape}{
	pen=Qt::SolidLine;
	brush=Qt::NoBrush;
}
const Shape& Shape::operator=(const Shape& other)
{
    painter = other.painter;
    pen     = other.pen;
    brush   = other.brush;
    id      = other.id;
    shape   = other.shape;
}
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

void Polyline::draw(QPaintDevice * dev)
{
    painter.begin(dev);
    for(int i = 0; i < numPts; i++)
        pointsAr[i] = pts[i];
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawPolyline(pointsAr, numPts);
    painter.drawText(pts[0],QString::number(getID()));
    painter.end();
}

void Polyline::addPoint(const QPointF &pt)
{
    pts.push_back(pt);
    numPts++;
    if(numPts < DEFAULT_NUM_PTS)
        pointsAr[numPts] = pt;
}

void Polyline::move(const int x, const int y, int vertex)
{
    QPoint temp(x,y);
    if(vertex <= numPts)
        pts[vertex - 1] = temp;
}
