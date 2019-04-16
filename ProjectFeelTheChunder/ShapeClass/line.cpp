#include "line.h"

Line::Line(QPaintDevice* qdevice = nullptr, int id = 1):Shape(qdevice, id, ShapeType::Line){

    line_begin.setX = 0;
    line_begin.setY = 50;

}
void Line::move(){
    int i = 0;
}


void setpoints(const QPoint& line_begin, const QPoint& line_end){

    int i = 0;
}

void Line::draw(const int x, const int y){

    get_qpainter().setPen(get_pen());
    get_qpainter().setBrush(get_brush());
    get_qpainter().save();
    get_qpainter().translate(x, y);
    get_qpainter().drawline(line_begin, line_end);
    get_qpainter().restore();
}

	
}
void Line::perimeter(){
    int i = 0;
}
void Line::area(){
    int i = 0;
}
