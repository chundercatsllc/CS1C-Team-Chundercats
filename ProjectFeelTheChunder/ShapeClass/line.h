#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape
{
public:
    Line();

    void move();
    void draw();
    void perimeter();
    void area();

};

#endif // LINE_H
