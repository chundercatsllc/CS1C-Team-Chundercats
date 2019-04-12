#ifndef POLYLINE_H
#define POLYLINE_H
#include "shape.h"

class Polyline : public Shape
{
public:
    Polyline();

    void move();
    void draw();
    void perimeter();
    void area();

};

#endif // POLYLINE_H
