#include "line.h"

Line::Line(QPaintDevice* qdevice = nullptr, int id = 1):Shape(qdevice, id, ShapeType::Line){

    line_begin.setX(0);
    line_end.setY(50);

}
void Line::move(const int, const int){
    int i = 0;
}


void Line::setpoints(const QPoint& line_begin, const QPoint& line_end){

    int i = 0;
}

void Line::draw(QPaintDevice* qdevice){
int i = 0;

}

	

double Line::perimeter(){
    int i = 0;
}

double Line::area(){
    int i = 0;
}
