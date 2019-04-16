#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape{

public:
    Line(QPaintDevice* qdevice = nullptr, int id = -1) : Shape(qdevice, id, ShapeType::Line) {} ;

    void setpoints(const QPoint&, const QPoint&);

	void move();
    void draw(const int x = 0, const int y = 0);
//	void perimeter();
//	void area();

    ~Line();

private:

    QPoint line_begin;
    QPoint line_end;

};

#endif // LINE_H
