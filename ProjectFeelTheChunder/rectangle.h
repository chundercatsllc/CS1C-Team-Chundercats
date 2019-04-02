#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle();

    void move();
    void draw();
    void perimeter();
    void area();

};

#endif // RECTANGLE_H
