#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPainter>

class Shape
{
public:
    Shape();
    Shape(const Shape &);
    virtual ~Shape() = 0;

    virtual void move() = 0;
    virtual void draw() = 0;
    virtual void perimeter() = 0;
    virtual void area() = 0;
protected:
    QPainter painter;
    int id;

};

#endif // SHAPE_H
