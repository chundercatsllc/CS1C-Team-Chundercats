#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPaintDevice>
#include <QString>
#include <QPoint>
#include <QPainter>
#include "../containers/AwesomeVector.h"

// : public QPainter
class Shape : public QPainter{
	public:
        QPainter painter;
        QPen     pen;
        QBrush   brush;

        enum class ShapeType{null,Line,Polyline,Polygon,Rectangle,Ellipse,Text};

        Shape(QPaintDevice *device = nullptr, int ID = -1, ShapeType shapey = ShapeType::null);
		virtual ~Shape(){}
		
        const Shape& operator=(const Shape& other);
		void setShape(ShapeType);
		void setBrush(Qt::GlobalColor, Qt::BrushStyle);
		void setPen(Qt::GlobalColor);
		void setPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);

        void setBrush(QBrush brsh){brush = brsh;}
        void setPen(QPen pn)      {pen   = pn;}
        void setID(int ID)        {id    = ID;}
		
        ShapeType     getShape() const {return shape;}
        const QBrush &getBrush() const {return brush;}
        const QPen   &getPen()   const {return pen;}
        int           getID()    const {return id;}
		
		void setDefaultStyle();
		
        virtual void move(const int tX, const int tY, int ptIndex) = 0;
        virtual void draw(QPaintDevice *device) = 0;
		virtual double perimeter() = 0;
		virtual double area() = 0;
	protected:
        QPainter &getQPainter();

	private:
		int id;
		ShapeType shape;
};

class Line : public Shape{

public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Line){}
    ~Line override {}

    void setpoints(const QPoint& x, const QPoint& y){line_begin = x; line_end = y;}

    virtual void move(const int x, const int y, int vert) override;
    virtual void draw(QPaintDevice* device) override;
    virtual double perimeter() override {return 0;}
    virtual double area() override {return 0;}
private:
    QPoint line_begin;
    QPoint line_end;
};

const int DEFAULT_NUM_PTS = 8;
class Polyline : public Shape
{
    public:
         Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, Shape::ShapeType::Polyline) {}
        ~Polyline()  override {}

        void addPoint(const QPointF& pt);

        void addNumPoints(int num) {numPts = num;}

        virtual void draw(QPaintDevice *device) override;

        void move(const int x, const int y, int coordNum) override;

        double perimeter() override {return 0;}

        double area() override {return 0;}

        vector<QPointF>& getPoints() {return pts;}

        int getNumPoints() {return numPts;}
    private:
        AwesomeVector<QPointF> pts;
        int numPts;
        QPointF pointsAr[DEFAULT_NUM_PTS];

};

#endif // SHAPE_H
