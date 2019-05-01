#ifndef LINE_H
#define LINE_H
#include "shape.h"
/*
class Line : public Shape{

public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Line){};

    void setpoints(const QPoint& x, const QPoint& y){line_begin = x; line_end = y;}

    virtual void move(const int x, const int y) ;
    virtual void draw(QPaintDevice* device) ;
    virtual double perimeter()  {};
    virtual double area()  {};

    ~Line() override;

private:

    QPoint line_begin;
    QPoint line_end;


};
*/
#endif // LINE_H
