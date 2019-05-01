#include "shape.h"
#include<QtMath>

/*************************************************************************

Shape Methods

**************************************************************************/

void Shape::setPen(Qt::GlobalColor color)

{
    QPen pen;

    penType = pen;
}

void Shape::setPen(Qt::GlobalColor color, int width, Qt::PenStyle pen_style,
                   Qt::PenCapStyle cap_style, Qt::PenJoinStyle join_style)
{
    QPen pen;

    pen.setColor(color);

    pen.setWidth(width);

    pen.setStyle(pen_style);

    pen.setCapStyle((cap_style));

    pen.setJoinStyle(join_style);

    penType = pen;

}

void Shape::setBrush(Qt::GlobalColor color, Qt::BrushStyle brush_style)
{
    QBrush brush;

    brush.setColor(color);

    brush.setStyle(brush_style);

    brushType = brush;

}

/*************************************************************************

Line Methods

**************************************************************************/

void Line::setPoints(const QPoint &begin, const QPoint &end)
{
    this->begin = begin;

    this->end = end;

}


void Line::move(const int x, const int y, int coordNum)
{
    QPoint tempPoint(x, y);
    switch(coordNum)
    {
    //Change first coordinate
    case 1:{begin = tempPoint;qDebug("begin changed");}
        break;
    //Change second coordinate
    case 2:{end = tempPoint;}
        break;
    //Did not choose correct Coordinate Number
    default: {}
    }

}


/*************************************************************************

Polyline Methods

**************************************************************************/

void Polyline::addPoint(const QPointF &point)
{
    points.push_back(point);
}


void Polyline::move(const int x, const int y, int coordNum)
{
    QPoint tempPoint(x, y);
    switch(coordNum)
    {
    //Change first coordinate
    case 1:{points[0] = tempPoint;}
        break;
    //Change second coordinate
    case 2:{points[1] = tempPoint;}
        break;
    //Change third coordinate
    case 3:{points[2] = tempPoint;}
        break;
    //Change fourth coordinate
    case 4:{points[3] = tempPoint;}
        break;
    //Change fifth coordinate
    case 5:{points[4] = tempPoint;}
        break;
    //Change sixth coordinate
    case 6:{points[5] = tempPoint;}
        break;
    //Did not choose correct Coordinate Number
    default: {}
    }

}



/*************************************************************************

Polygon Methods

**************************************************************************/

void Polygon::addPoint(const QPointF &point)
{
    points.push_back(point);
}


double Polygon::area()
{
    double area = 0;

    for(int i = 0; i < points.size(); i++)
    {
        if(i == points.size()-1)
        {
            area += points[i].x() * points[0].y();

            area -= points[i].y() * points[0].x();

        }
        else
        {
            area += points[i].x() * points[i+1].y();

            area -= points[i].y() * points[i+1].x();

        }

    }
    return (qAbs(area) / 2);

}

double Polygon::perimeter()
{
    double perimeter = 0;

    for(int i = 0; i < points.size()-1; i++)
    {
        perimeter += (qSqrt((points[i+1].x() - points[i].x()) * (points[i+1].x() - points[i].x())

                + (points[i+1].y() - points[i].y()) * (points[i+1].y() - points[i].y())));

    }
    return perimeter;

}

void Polygon::move(const int x, const int y, int coordNum)
{
    QPoint tempPoint(x, y);
    switch(coordNum)
    {
    //Change first coordinate
    case 1:{points[0] = tempPoint;}
        break;
    //Change second coordinate
    case 2:{points[1] = tempPoint;}
        break;
    //Change third coordinate
    case 3:{points[2] = tempPoint;}
        break;
    //Change fourth coordinate
    case 4:{points[3] = tempPoint;}
        break;
    //Change fifth coordinate
    case 5:{points[4] = tempPoint;}
        break;
    //Change sixth coordinate
    case 6:{points[5] = tempPoint;}
        break;
    //Change seventh coordinate
    case 7:{points[6] = tempPoint;}
        break;
    //Change eigth coordinate
    case 8:{points[7] = tempPoint;}
        break;
    //Did not choose correct Coordinate Number
    default: {}
    }

}



/*************************************************************************

Rectangle Methods

**************************************************************************/

void Rectangle::setDimensions(int width, int height)
{
    this->width = width;

    this->height = height;

}



double Rectangle::area()
{

    return(width * height);

}

double Rectangle::perimeter()
{

    return(2 * width + 2 * height);

}

void Rectangle::move(const int x, const int y, int coordNum)
{
    QPoint tempPoint(x, y);
    position = tempPoint;
}



/*************************************************************************

Ellipse Methods

**************************************************************************/



double Ellipse::area()
{
    return(width * height * M_PI);

}

double Ellipse::perimeter()

{
    return(M_PI * 3 * (width + height) - qSqrt((3 * width + height) * (width + 3 * height)));

}

void Ellipse::move(const int x, const int y, int coordNum)
{
    QPoint tempPoint(x, y);
    position = tempPoint;

}



/*************************************************************************

Text Methods

**************************************************************************/

double Text::area()
{
    return double(width * height);
}

QFont& Text::getFont()
{
    return font;
}

Qt::AlignmentFlag Text::getAlignment() const
{
    return alignmentFlags;
}

QString Text::getText() const
{
    return text;
}

void Text::move(const int x, const int y, int coordNum)
{
    QPoint tempPoint(x, y);
    position = tempPoint;
}

double Text::perimeter()
{
    return 2.0 * (width + height);
}

void Text::setAlignment(Qt::AlignmentFlag flags)
{
    alignmentFlags = flags;
}

void Text::setDimensions(int w, int h)
{
    width = w;
    height = h;
}

void Text::setFont(QString fontFamIn, QFont::Style fontStyleIn, int pointSizeIn, QFont::Weight weightIn, Qt::GlobalColor colorIn)
{
    font.setFamily(fontFamIn);
    font.setStyle(fontStyleIn);
    font.setPointSize(pointSizeIn);
    font.setWeight(weightIn);
    penType.setColor(colorIn);
}

void Text::setPosition(int x, int y)
{
    position = { x, y };
}

void Text::setText(const QString& textIn)
{
    text = textIn;
}

