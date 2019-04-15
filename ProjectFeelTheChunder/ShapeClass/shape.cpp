#include "shape.h"

Shape::Shape(QPaintDevice *device, int id, ShapeType shape):painter{device},id{id},shape{shape}{
	pen=Qt::SolidLine;
	brush=Qt::NoBrush;
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
Shape::ShapeType Shape::getShape() const{
	return shape;
}
const QBrush &Shape::getBrush() const{
	return brush;
}
const QPen &Shape::getPen() const{
	return pen;
}
void Shape::setDefaultStyle(){
	pen=Qt::SolidLine;
	brush=Qt::NoBrush;
	painter.setPen(Qt::SolidLine);
	painter.setBrush(Qt::NoBrush);
}
QPainter &Shape::get_qpainter(){
	return painter;
}