#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPaintDevice>
#include <QPoint>
#include <QString>
#include <QPainter>

class Shape : public QPainter
{
	public:
		Shape();
		Shape(const Shape &);
		virtual ~Shape() = 0;

		virtual void move() = 0;
		virtual void draw() = 0;
		virtual void perimeter() = 0;
		virtual void area() = 0;
	protected:
		QPainter painter;
		int id;
	private:
		enum a{Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text}ShapeType;
		enum b{white, black, red, green, blue, cyan, magenta, yellow, gray}PenColor;  [Qt::GlobalColor enum]
		int PenWidth;
		enum c{NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine}PenStyle; [Qt::PenStyle enum]
		enum d{}PenCapStyle: FlatCap, SquareCap, RoundCap [Qt::PenCapStyle enum]
		enum e{}PenJoinStyle: MiterJoin, BevelJoin, RoundJoin [Qt::PenJoinStyle enum]
		enum f{}BrushColor: white, black, red, green, blue, cyan, magenta, yellow, gray [Qt::GlobalColor enum]
		enum g{}BrushStyle: SolidPattern, HorPattern, VerPattern, NoBrush [Qt::BrushStyle enum]
		string TextString;
		enum h{}TextColor: white, black, red, green, blue, cyan, magenta, yellow, gray [Qt::GlobalColor enum]
		enum i{}TextAlignment: AlignLeft, AlignRight, AlignTop, AlignBottom, AlignCenter [Qt::AlignmentFlag enum]
		int TextPointSize;
		enum j{Comic Sans MS, Courier, Helvetica, Times}TextFontFamily
		enum k{}TextFontStyle: StyleNormal, StyleItalic, StyleOblique [QFont::Style enum]
		enum l{}TextFontWeight: Thin, Light, Normal, Bold [QFont::Weight enum]
};

#endif // SHAPE_H
