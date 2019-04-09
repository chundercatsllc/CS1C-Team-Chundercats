#include "polygon.h"

Polygon::Polygon(QPaintDevice* dev = nullptr, int id = -1)
        : Shape(dev, id, Shape::Polygon)
{     
}

Polygon::~Polygon()
{
  coordPts.clear();
}

void Polygon::addPt(const QPointF &pt)
{
    coordPts.push_back(pt);
}

void Polygon::setNumPts(int n)
{
    if(n > 2 && n >= 8)
        numPoints = n;
    else {
        qDebug() << "the number of sides is incorrect";
    }
}

vector<QPointF>& Polygon::getCoordPts()
{
    return coordPts;
}

double Polygon::area()
{
    double area = 0;

    for(int i = 0; i < coordPts.size(); i++)
    {
        if(i == coordPts.size()-1)
        {
            area += coordPts[i].x() * coordPts[0].y();

            area -= coordPts[i].y() * coordPts[0].x();

        }
        else
        {
            area += coordPts[i].x() * coordPts[i+1].y();

            area -= coordPts[i].y() * coordPts[i+1].x();

        }

    }
    return (qAbs(area) / 2);

}

void Polygon::move(const int x, const int y, int coordNum)
{
    //creates a temporary new point storing the new coords
    QPoint tempPt(x, y);

    //takes the coord point at the specified index(zero based) and assigns the temp to it
    coordPts[coordNum - 1] = tempPt;
}

double Polygon::perimeter()
{
    double per = 0;

    for(int i = 0; i < coordPts.size()-1; i++)
    {
        per += (qSqrt((coordPts[i+1].x() - coordPts[i].x()) * (coordPts[i+1].x() - coordPts[i].x())

                + (coordPts[i+1].y() - coordPts[i].y()) * (coordPts[i+1].y() - coordPts[i].y())));

    }
    return per;

}

void Polygon::draw(QPaintDevice *device)
{
    painter.begin(device);
    for(int i = 0; i < numPoints; i++)
    {
        polygonPointsAr[i] = coordPts[i];
    }
    painter.setPen(penType);
    painter.setBrush(brushType);
    painter.drawPolygon(polygonPointsAr, numPoints);
    painter.drawText(points[0],QString::number(getId()));
    painter.end();
}


