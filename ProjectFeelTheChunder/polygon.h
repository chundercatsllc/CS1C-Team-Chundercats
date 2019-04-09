#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include <vector>
#include <QPointF>
#include <QPaintDevice>
#include <QtMath>
#include <QDebug>

using namespace std;

class Polygon : public Shape
{
public:
    Polygon(QPainterDevice*, int);
    ~Polygon() override;

    void addPt(const QPointF&);
    void setNumPts(int);
    vector<QPointF>& getCoordPts();

    virtual void move(const int, const int, int) override;
    virtual void draw(QPaintDevice *) override;
    double perimeter();
    double area();
private:
    vector<QPointF> coordPts;   //coordinate points to store the vertices of the polygon
    int numPoints;              //the number of coordinate points
    QPointF polygonPointsAr[8]; //coordinate points as array stored as QPointFs

};

#endif // POLYGON_H
