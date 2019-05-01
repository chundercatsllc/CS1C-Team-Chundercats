
#include "line.h"


void Line::move(const int x, const int y) {
    QPoint temp(x, y);
    line_begin = temp;
}


void Line::draw(QPaintDevice* device) {

    getQPainter().begin(device);
    getQPainter().setPen(getPen());
    getQPainter().setBrush(getBrush());
    getQPainter().drawLine(line_begin.x(), line_begin.y(), line_end.x(), line_end.y());
    getQPainter().drawText(line_begin,QString::number(getID()));
    getQPainter().end();

}




	


