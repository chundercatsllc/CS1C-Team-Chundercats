#include "rectangle.h"

void Rectangle::move(const int x, const int y) override{
	QPoint tmp(x, y);
    coordinate = tmp;
}
void Rectangle::draw(QPaintDevice *device) override{
	painter.begin(device);
	painter.setPen(penType);
	painter.setBrush(brushType);
	painter.drawRect(coordinate.x(),coordinate.y(), width,height);
	painter.drawText(coordinate,QString::number(getId()));
	painter.end();
}
void Rectangle::setDimensions(int width, int height){
	this->width = width;
	this->height = height;
}