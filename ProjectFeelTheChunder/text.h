#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

class Text : public Shape
{
public:
    Text();

    void move();
    void draw();
    void perimeter();
    void area();

};

#endif // TEXT_H
