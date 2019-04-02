#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse();


    void move();
    void draw();
    void perimeter();
    void area();
};

#endif // ELLIPSE_H
