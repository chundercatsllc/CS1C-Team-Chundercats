#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"

class Polygon : public Shape
{
public:
    Polygon();

    void move();
    void draw();
    void perimeter();
    void area();

};

#endif // POLYGON_H
