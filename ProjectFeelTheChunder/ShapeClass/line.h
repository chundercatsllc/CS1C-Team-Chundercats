#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape{

public:
    Line(QPaintDevice* qdevice = nullptr, int id = -1);// : Shape(qdevice, id, Shape::Line);

    void setpoints(const QPoint&, const QPoint&);

    virtual void move(const int, const int);
    virtual void draw(QPaintDevice*);
    virtual double perimeter();
    virtual double area();

    ~Line();

private:

    QPoint line_begin;
    QPoint line_end;

};

#endif // LINE_H
