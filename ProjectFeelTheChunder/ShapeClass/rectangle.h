#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape{
public:
	Rectangle(QPaintDevice *device = nullptr, int id = -1) : Shape(device, id, ShapeType::Rectangle){}
	~Rectangle() override {}
	
	void setCoordinate(const QPoint& x){coordinate = x;}
	
	void setDimensions(int width, int height);

	void move(const int x, const int y);			// Absolute points from center
	void draw(QPaintDevice *device);
	double perimeter() override{return(2 * width)+(2 * height);}
	double area() override {return(width * height);}
	
	QPoint &getCoordinate(){return coordinate;}
	
	int getWidth() {return width;}
	int getHeight() {return height;}
private:
	QPoint coordinate;
	int width;
	int height;
};

#endif // RECTANGLE_H
