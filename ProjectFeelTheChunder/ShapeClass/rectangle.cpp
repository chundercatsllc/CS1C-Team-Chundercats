#include "rectangle.h"

void Rectangle::move(const int x, const int y){
	QPoint tmp(x, y);
    coordinate = tmp;
}
void Rectangle::draw(QPaintDevice *device){
	getQPainter().begin(device);
	getQPainter().setPen(getPen());
	getQPainter().setBrush(getBrush());
	getQPainter().drawRect(coordinate.x(),coordinate.y(), width,height);
	getQPainter().drawText(coordinate,QString::number(getID()));
	getQPainter().end();
}
void Rectangle::setDimensions(int width, int height){
	this->width = width;
	this->height = height;
}