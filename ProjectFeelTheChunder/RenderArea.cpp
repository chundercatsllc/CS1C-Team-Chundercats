#include "RenderArea.h"

RenderArea::RenderArea(QWidget *parent)
      : QWidget(parent), ShapeMagazine(10)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(sizeHint());
    readShapeFile();
}

void RenderArea::paintEvent(QPaintEvent * event)
{
    QPaintDevice* device = this;
    for(int i = 0; i < ShapeMagazine.sizeOf(); i++)
        ShapeMagazine[i]->draw(device);
}

const AwesomeVector<Shape*> & RenderArea::getShapes()
{
    return ShapeMagazine;
}

Shape::ShapeType RenderArea::getShapeType(int index)
{
    return ShapeMagazine[index]->getShape();
}

void RenderArea::addShape(Shape* shapeIn)
{
    ShapeMagazine.push_back(shapeIn);
    numShapes++;
    //shapeIn->draw(this);
    this->update();
}

void RenderArea::chopShape(int i)
{
    ShapeMagazine.erase(i);
    this->update();
}

void RenderArea::moveShape(int index, int coord, int x, int y)
{
    for(int i = 0; i < ShapeMagazine.sizeOf(); i++)
        if(ShapeMagazine[i]->getID() == index){
            ShapeMagazine[i]->move(x,y,coord); break; }
    this->update();
}

int RenderArea::getSize()
{
    return ShapeMagazine.sizeOf();
}

QSize RenderArea::sizeHint() const
{
    return QSize(1000,500);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(1000,500);
}

/*
void RenderArea::writeShapeFile()
{


    QFile myFile(":/stuff/shapes.txt");

    if(!myFile.open( QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("could not open file\n");
    }

    QTextStream fout(&myFile);
    theVectorator i = ShapeMagazine.begin();
    while(i < ShapeMagazine.end()) //Write List
    {
       fout << endl; //Add space between shapes
       fout << "ShapeId: " << (*i)->getId() << endl;
       fout << "ShapeType: " << shapeTypeStr[int((*i)->getShape())] << endl;
        switch ((*i)->getShape())
        {
        case ShapeType::LineType:
        {
            fout << "ShapeDimensions: " << dynamic_cast<Line*>(*i)->getBeginPoint().x() << ", "
                                        <<  dynamic_cast<Line*>(*i)->getBeginPoint().y() << ", "
                                        <<  dynamic_cast<Line*>(*i)->getEndPoint().x() << ", "
                                        <<  dynamic_cast<Line*>(*i)->getEndPoint().y() << endl;
            fout << "PenColor: " << QTColorToStr(dynamic_cast<Line*>(*i)->getPen().color()) << endl;
            fout << "PenWidth: " << dynamic_cast<Line*>(*i)->getPen().width() << endl;
            fout << "PenStyle: " << QTPenStyleToStr(dynamic_cast<Line*>(*i)->getPen().style()) << endl;
            fout << "PanCapStyle: " << QTCapStyleToStr(dynamic_cast<Line*>(*i)->getPen().capStyle()) << endl;
            fout << "PenJoinStyle: " << QTPenJoinStyleToStr(dynamic_cast<Line*>(*i)->getPen().joinStyle()) << endl;
            break;
        }
        case ShapeType::PolylineType:
        {
            fout << "ShapeDimensions: ";
            for(int count = 0; count < dynamic_cast<Polyline*>(*i)->getNumPoints(); count++)
            {
                fout << dynamic_cast<Polyline*>(*i)->getPoints()[count].x() << ", ";
                fout  << dynamic_cast<Polyline*>(*i)->getPoints()[count].y();

                if(count != dynamic_cast<Polyline*>(*i)->getNumPoints() - 1)
                {
                       fout << ", ";
                }
            }
            fout << endl;

            fout << "PenColor: " << QTColorToStr(dynamic_cast<Polyline*>(*i)->getPen().color()) << endl;
            fout << "PenWidth: " << dynamic_cast<Polyline*>(*i)->getPen().width() << endl;
            fout << "PenStyle: " << QTPenStyleToStr(dynamic_cast<Polyline*>(*i)->getPen().style()) << endl;
            fout << "PanCapStyle: " << QTCapStyleToStr(dynamic_cast<Polyline*>(*i)->getPen().capStyle()) << endl;
            fout << "PenJoinStyle: " << QTPenJoinStyleToStr(dynamic_cast<Polyline*>(*i)->getPen().joinStyle()) << endl;
            break;
        }
        case ShapeType::PolygonType:
        {
            fout << "ShapeDimensions: ";
            for(int count = 0; count < dynamic_cast<Polygon*>(*i)->getNumPoints(); count++)
            {
                fout << dynamic_cast<Polygon*>(*i)->getPoints()[count].x() << ", ";
                fout  << dynamic_cast<Polygon*>(*i)->getPoints()[count].y();

                if(count != dynamic_cast<Polygon*>(*i)->getNumPoints() - 1)
                {
                       fout << ", ";
                }
            }
            fout << endl;

            fout << "PenColor: " << QTColorToStr(dynamic_cast<Polygon*>(*i)->getPen().color()) << endl;
            fout << "PenWidth: " << dynamic_cast<Polygon*>(*i)->getPen().width() << endl;
            fout << "PenStyle: " << QTPenStyleToStr(dynamic_cast<Polygon*>(*i)->getPen().style()) << endl;
            fout << "PanCapStyle: " << QTCapStyleToStr(dynamic_cast<Polygon*>(*i)->getPen().capStyle()) << endl;
            fout << "PenJoinStyle: " << QTPenJoinStyleToStr(dynamic_cast<Polygon*>(*i)->getPen().joinStyle()) << endl;
            fout << "BrushColor: " <<  QTColorToStr(dynamic_cast<Polygon*>(*i)->getBrush().color()) << endl;
            fout << "BrushStyle: " <<  QTBushStyleToStr(dynamic_cast<Polygon*>(*i)->getBrush().style()) << endl;

            break;
        }
        case ShapeType::RectangleType:
        {
            fout << "ShapeDimensions: " << dynamic_cast<Rectangle*>(*i)->getPosition().x()
                                        << ", "
                                        << dynamic_cast<Rectangle*>(*i)->getPosition().y()
                                        << ", "
                                        << dynamic_cast<Rectangle*>(*i)->getHeight()
                                        << ", "
                                        << dynamic_cast<Rectangle*>(*i)->getWidth() << endl;

            fout << "PenColor: " << QTColorToStr(dynamic_cast<Rectangle*>(*i)->getPen().color()) << endl;
            fout << "PenWidth: " << dynamic_cast<Rectangle*>(*i)->getPen().width() << endl;
            fout << "PenStyle: " << QTPenStyleToStr(dynamic_cast<Rectangle*>(*i)->getPen().style()) << endl;
            fout << "PanCapStyle: " << QTCapStyleToStr(dynamic_cast<Rectangle*>(*i)->getPen().capStyle()) << endl;
            fout << "PenJoinStyle: " << QTPenJoinStyleToStr(dynamic_cast<Rectangle*>(*i)->getPen().joinStyle()) << endl;
            fout << "BrushColor: " <<  QTColorToStr(dynamic_cast<Rectangle*>(*i)->getBrush().color()) << endl;
            fout << "BrushStyle: " <<  QTBushStyleToStr(dynamic_cast<Rectangle*>(*i)->getBrush().style()) << endl;
            break;
        }
        case ShapeType::EllipseType:
        {
            fout << "ShapeDimensions: " << dynamic_cast<Ellipse*>(*i)->getPosition().x()
                                        << ", "
                                        << dynamic_cast<Ellipse*>(*i)->getPosition().y()
                                        << ", "
                                        << dynamic_cast<Ellipse*>(*i)->getWidth()
                                        << ", "
                                        << dynamic_cast<Ellipse*>(*i)->getHeight() << endl;

            fout << "PenColor: " << QTColorToStr(dynamic_cast<Ellipse*>(*i)->getPen().color()) << endl;
            fout << "PenWidth: " << dynamic_cast<Ellipse*>(*i)->getPen().width() << endl;
            fout << "PenStyle: " << QTPenStyleToStr(dynamic_cast<Ellipse*>(*i)->getPen().style()) << endl;
            fout << "PanCapStyle: " << QTCapStyleToStr(dynamic_cast<Ellipse*>(*i)->getPen().capStyle()) << endl;
            fout << "PenJoinStyle: " << QTPenJoinStyleToStr(dynamic_cast<Ellipse*>(*i)->getPen().joinStyle()) << endl;
            fout << "BrushColor: " <<  QTColorToStr(dynamic_cast<Ellipse*>(*i)->getBrush().color()) << endl;
            fout << "BrushStyle: " <<  QTBushStyleToStr(dynamic_cast<Ellipse*>(*i)->getBrush().style()) << endl;
            break;
        }
        case ShapeType::TextType:
        {
            fout << "ShapeDimensions: " << dynamic_cast<Text*>(*i)->getPosition().x()
                                        << ", "
                                        << dynamic_cast<Text*>(*i)->getPosition().y()
                                        << ", "
                                        << dynamic_cast<Text*>(*i)->getWidth()
                                        << ", "
                                        << dynamic_cast<Text*>(*i)->getHeight() << endl;
            fout << "TextString: " << dynamic_cast<Text*>(*i)->getText() << endl;
            fout << "TextColor: " << QTColorToStr(dynamic_cast<Text*>(*i)->getPen().color()) << endl;
            fout << "TextAlignment: " << QTAlignmentToStr(dynamic_cast<Text*>(*i)->getAlignment()) << endl;
            fout << "TextPointSize: " << dynamic_cast<Text*>(*i)->getFont().pointSize() << endl;
            fout << "TextFontFamily: " << dynamic_cast<Text*>(*i)->getFont().family() << endl;
            fout << "TextFontStyle: " << QTTextStyleToStr(dynamic_cast<Text*>(*i)->getFont().style()) << endl;
            fout << "TextFontWeight: " << QTTextWeightToStr(dynamic_cast<Text*>(*i)->getFont().weight()) << endl;
            break;
        }
        default: qDebug("Error write");
        }
        ++i;
    }

    myFile.flush();
    myFile.close();

}*/


void RenderArea::readShapeFile()
{

    AwesomeVector<Shape*> shapeMagazine;

    QFile myFile(":/stuff/shapes.txt");

    if(!myFile.open( QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Couldnt open the shape file\n");
    }

    QTextStream fileIn(&myFile);
    QStringList listfull;
    QString listfill;
    QString     emptiness;
    int         id  = -1;
    emptiness = fileIn.readLine();
    emptiness = "no longer";

    while(!fileIn.atEnd())
    {
        QString garbage;
        QPen    shapePen;
        QBrush  shapeBrush;

        QString shapeTypeStr;
        Shape::ShapeType shapeType;

        fileIn >> garbage;
        fileIn >> id;

        fileIn >> garbage;
        fileIn >> shapeTypeStr;
        qDebug() << "start " << shapeTypeStr;

        shapeType = getShapeType(shapeTypeStr);

        switch(shapeType)
        {
        case Shape::ShapeType::Line:
        {
            Line * linebacker = new Line(this, id);
            QPen linePen;

            QString     coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint coord1(coordList[0].toInt(), coordList[1].toInt());
            QPoint coord2(coordList[2].toInt(), coordList[3].toInt());
            linebacker->setPoints(coord1, coord2);

            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            linePen.setColor(getColor(penColorStr));

            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            linePen.setWidth(penWidth);

            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            linePen.setStyle(getPenStyle(penStyleStr));

            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            linePen.setCapStyle(getPenCapStyle(penCapStyleStr));

            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            linePen.setJoinStyle(getPenJointStyle(penJoinStyleStr));

            linebacker->setPen(linePen);
            linebacker->setID(id);
            linebacker->setShape(Shape::ShapeType::Line);
            addShape(linebacker);
        }
        break;
        case Shape::ShapeType::Polyline:
        {
            Polyline *newPolly = new Polyline(this, 0);
            QPen polylinePen;

            QString     coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr  = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint pt1(coordList[0].toInt(), coordList[1].toInt());
            QPoint pt2(coordList[2].toInt(), coordList[3].toInt());

            newPolly->addPoint(pt1);
            newPolly->addPoint(pt2);

            if(coordList.size() > 4)
            {
                QPoint coord3(coordList[4].toInt(), coordList[5].toInt());
                newPolly->addPoint(coord3); //Set points

                if(coordList.size() > 6)//If more points
                {
                    QPoint coord4(coordList[6].toInt(), coordList[7].toInt());
                    newPolly->addPoint(coord4); //Set points

                    if(coordList.size() > 8)//If more points
                    {
                        QPoint coord5(coordList[8].toInt(), coordList[9].toInt());
                        newPolly->addPoint(coord5); //Set points

                        if(coordList.size() > 10)//If more points
                        {
                            QPoint coord6(coordList[10].toInt(), coordList[11].toInt());
                            newPolly->addPoint(coord6); //Set points


                        }
                    }
                }
            }


            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            polylinePen.setColor(getColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            polylinePen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            polylinePen.setStyle(getPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            polylinePen.setCapStyle(getPenCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            polylinePen.setJoinStyle(getPenJointStyle(penJoinStyleStr));

            newPolly->setPen(polylinePen);
            newPolly->setID(id);
            newPolly->setShape(Shape::ShapeType::Polyline);
            newPolly->addNumPoints(coordList.size()/2);
            addShape(newPolly); //Adding shape

            break;
        }//END Polyline type

              //Polygon
        case Shape::ShapeType::Polygon:
        {
            Polygon *poliGonGin = new Polygon(this, 0);
            QPen polygonPen;
            QBrush polygonBrush;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint coord1(coordList[0].toInt(), coordList[1].toInt());
            QPoint coord2(coordList[2].toInt(), coordList[3].toInt());

            //Qui-gon-gin (star wars episode I)
            poliGonGin->addVertex(coord1); //Set points
            poliGonGin->addVertex(coord2); //Set points

            if(coordList.size() > 4)//Check to see if more points
            {
                QPoint coord3(coordList[4].toInt(), coordList[5].toInt());
                poliGonGin->addVertex(coord3); //Set points

                if(coordList.size() > 6)//If more points
                {
                    QPoint coord4(coordList[6].toInt(), coordList[7].toInt());
                    poliGonGin->addVertex(coord4); //Set points

                    if(coordList.size() > 8)//If more points
                    {
                        QPoint coord5(coordList[8].toInt(), coordList[9].toInt());
                        poliGonGin->addVertex(coord5); //Set points

                        if(coordList.size() > 10)//If more points
                        {
                            QPoint coord6(coordList[10].toInt(), coordList[11].toInt());
                            poliGonGin->addVertex(coord6); //Set points

                            if(coordList.size() > 12)//If more points
                            {
                                QPoint coord7(coordList[12].toInt(), coordList[13].toInt());
                                poliGonGin->addVertex(coord7); //Set points

                                if(coordList.size() > 14)//If more points
                                {
                                    QPoint coord8(coordList[14].toInt(), coordList[15].toInt());
                                    poliGonGin->addVertex(coord8); //Set points


                                }
                            }
                        }
                    }
                }
            }//End coordinates

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            polygonPen.setColor(getColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            polygonPen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            polygonPen.setStyle(getPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            polygonPen.setCapStyle(getPenCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            polygonPen.setJoinStyle(getPenJointStyle(penJoinStyleStr));

            //Store Brush Color
            fileIn >> garbage;
            QString brushColorStr;
            fileIn >> brushColorStr;
            polygonBrush.setColor(getBrushStyle(brushColorStr));

            //Store BrushStyle
            fileIn >> garbage;
            QString brushStyleStr;
            fileIn >> brushStyleStr;
            polygonBrush.setStyle(getBrushStyle(brushStyleStr));

            poliGonGin->setPen(polygonPen);
            poliGonGin->setBrush(polygonBrush);
            poliGonGin->setID(id);
            poliGonGin->setShape(Shape::ShapeType::Polygon);
            poliGonGin->setNumVertices(coordList.size()/2);
            addShape(poliGonGin); //Adding shape
        }
        break;
        case Shape::ShapeType::Rectangle:
        {
            Rectangle *RECTIFYYY = new Rectangle(this, 0);
            QPen   rectPen;
            QBrush rectBrush;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint center(coordList[0].toInt(), coordList[1].toInt());
            RECTIFYYY->setLocation(center);
            RECTIFYYY->setDimensions(coordList[3].toInt(), coordList[2].toInt());

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            rectPen.setColor(getColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            rectPen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            rectPen.setStyle(getPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            rectPen.setCapStyle(getPenCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            rectPen.setJoinStyle(getPenJointStyle(penJoinStyleStr));

            //Store Brush Color
            fileIn >> garbage;
            QString brushColorStr;
            fileIn >> brushColorStr;
            rectBrush.setColor(getColor(brushColorStr));

            //Store BrushStyle
            fileIn >> garbage;
            QString brushStyleStr;
            fileIn >> brushStyleStr;
            rectBrush.setStyle(getBrushStyle(brushStyleStr));

            RECTIFYYY->setPen(rectPen);
            RECTIFYYY->setBrush(rectBrush);
            RECTIFYYY->setID(id);
            RECTIFYYY->setShape(Shape::ShapeType::Rectangle);
            addShape(RECTIFYYY);
        }
        break;
        case Shape::ShapeType::Ellipse:
        {
            Ellipse *addEllipse = new Ellipse(this, 0);
            QPen ellipsePen;
            QBrush ellipseBrush;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint center(coordList[0].toInt(), coordList[1].toInt());
            addEllipse->setLocation(center);
            addEllipse->setDimensions(coordList[2].toInt(), coordList[3].toInt()); //Same length and width

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            ellipsePen.setColor(getColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            ellipsePen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            ellipsePen.setStyle(getPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            ellipsePen.setCapStyle(getPenCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            ellipsePen.setJoinStyle(getPenJointStyle(penJoinStyleStr));

            //Store Brush Color
            fileIn >> garbage;
            QString brushColorStr;
            fileIn >> brushColorStr;
            ellipseBrush.setColor(getColor(brushColorStr));

            //Store BrushStyle
            fileIn >> garbage;
            QString brushStyleStr;
            fileIn >> brushStyleStr;
            ellipseBrush.setStyle(getBrushStyle(brushStyleStr));

            addEllipse->setPen(ellipsePen);
            addEllipse->setBrush(ellipseBrush);
            addEllipse->setID(id);
            addEllipse->setShape(Shape::ShapeType::Ellipse);
            addShape(addEllipse);
        }
        break;
        case Shape::ShapeType::Text:
        {
            Text *letsGetTexty = new Text(this, 0);
            QPen textPen;
            QFont textFont;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint center(coordList[0].toInt(), coordList[1].toInt());
            letsGetTexty->setLocation(center);
            letsGetTexty->setDimensions(coordList[2].toInt(), coordList[3].toInt()); //Same length and width

            //Store text
            fileIn >> garbage;
            QString textStr;
            textStr = fileIn.readLine();
            letsGetTexty->setText(textStr);

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            Qt::GlobalColor c = (getColor(penColorStr));

            //Store Alignment
            fileIn >> garbage;
            QString alignStr;
            fileIn >> alignStr;
            Qt::AlignmentFlag f = (getFlag(alignStr));

            //Store point size
            fileIn >> garbage;
            int pointSize;
            fileIn >> pointSize;

            //Store family
            fileIn >> garbage;
            QString textFamilyStr;
            textFamilyStr = fileIn.readLine();

            //Store Font style
            fileIn >> garbage;
            QString textFontStyleStr;
            fileIn >> textFontStyleStr;
            QFont::Style s = (getFontStyle(textFontStyleStr));

            //Store Font weight
            fileIn >> garbage;
            QString textFontWeightStr;
            fileIn >> textFontWeightStr;
            QFont::Weight w = (getFontWeight(textFontWeightStr));

            letsGetTexty->setPen(textPen);
            letsGetTexty->setFont(textFamilyStr,s,pointSize,w,c);
            letsGetTexty->setFlag(f);
            letsGetTexty->setID(id);
            letsGetTexty->setShape(Shape::ShapeType::Text);
            addShape(letsGetTexty); //Adding shape
        }
            break;
        default: qDebug("Couldn't read the input file");
        }

        emptiness = fileIn.readLine();
    }
    myFile.close();
}

int RenderArea::getNumShapes()
{
    return numShapes;
}

Shape::ShapeType RenderArea::getShapeType(QString shapeStr)
{
    if(shapeStr == "Line")
        return Shape::ShapeType::Line;
    else if(shapeStr == "Polyline")
        return Shape::ShapeType::Polyline;
    else if(shapeStr == "Polygon")
        return Shape::ShapeType::Polygon;
    else if(shapeStr == "Rectangle")
        return Shape::ShapeType::Rectangle;
    else if(shapeStr == "Ellipse")
        return Shape::ShapeType::Ellipse;
    else if(shapeStr == "Text")
        return Shape::ShapeType::Text;
    else
        return Shape::ShapeType::null;

}

Qt::GlobalColor RenderArea::getColor(QString colorStr)
{    
    if(colorStr == "blue")
        return Qt::blue;
    else if(colorStr == "red")
        return Qt::red;
    else if(colorStr == "green")
        return Qt::green;
    else if(colorStr == "yellow")
        return Qt::yellow;
    else if(colorStr == "black")
        return Qt::black;
    else if(colorStr == "white")
        return Qt::white;
    else if(colorStr == "cyan")
        return Qt::cyan;
    else if(colorStr == "magenta")
        return Qt::magenta;
    else
        return Qt::gray;
}

Qt::PenCapStyle RenderArea::getPenCapStyle(QString capStr)
{

    if(capStr == "SquareCap")
        return Qt::SquareCap;
    else if(capStr == "FlatCap")
        return Qt::FlatCap;
    else
        return Qt::RoundCap;
}

Qt::PenStyle RenderArea::getPenStyle(QString penStr)
{
    if(penStr == "NoPen")
        return Qt::NoPen;
    else if(penStr == "SolidLine")
        return Qt::SolidLine;
    else if(penStr == "DashLine")
        return Qt::DashLine;
    else if(penStr == "DotLine")
        return Qt::DotLine;
    else if(penStr == "DashDotLine")
        return Qt::DashDotLine;
    else
        return Qt::DashDotDotLine;
}

Qt::PenJoinStyle RenderArea::getPenJointStyle(QString penJointStr)
{
    if(penJointStr == "MiterJoin")
        return Qt::MiterJoin;
    else if(penJointStr == "BevelJoin")
        return Qt::BevelJoin;
    else
        return Qt::RoundJoin;
}

Qt::BrushStyle RenderArea::getBrushStyle(QString brushStr)
{
    if(brushStr == "SolidPattern")
        return Qt::SolidPattern;
    else if(brushStr == "HorPattern")
        return Qt::HorPattern;
    else if(brushStr == "VerPattern")
        return Qt::VerPattern;
    else
        return Qt::NoBrush;
}

Qt::AlignmentFlag RenderArea::getFlag(QString flagStr)
{
    if(flagStr == "AlignLeft")
        return Qt::AlignLeft;
    else if(flagStr == "AlignRight")
        return Qt::AlignRight;
    else if(flagStr == "AlignTop")
        return Qt::AlignTop;
    else if(flagStr == "AlignBottom")
        return Qt::AlignBottom;
    else
        return Qt::AlignCenter;
}

QFont::Style RenderArea::getFontStyle(QString fontStyleStr)
{
    if(fontStyleStr == "StyleNormal")
        return QFont::StyleNormal;
    else if(fontStyleStr == "StyleItalic")
        return QFont::StyleItalic;
    else
        return QFont::StyleOblique;
}

QFont::Weight RenderArea::getFontWeight(QString fontWeightStr)
{
    if(fontWeightStr == "Thin")
        return QFont::Thin;
    else if(fontWeightStr == "Light")
        return QFont::Light;
    else if(fontWeightStr == "Normal")
        return QFont::Normal;
    else
        return QFont::Bold;
}

QString RenderArea::getStringColor(QColor color)
{
    if(color == Qt::blue)
        return "blue";
    else if(color == Qt::red)
        return "red";
    else if(color == Qt::green)
        return "green";
    else if(color == Qt::yellow)
        return "yellow";
    else if(color == Qt::black)
        return "black";
    else if(color == Qt::white)
        return "white";
    else if(color == Qt::cyan)
        return "cyan";
    else if(color == Qt::magenta)
        return "magenta";
    else
        return "gray";
}


QString RenderArea::getStringPenCap(Qt::PenCapStyle penStyle)
{
    if(penStyle == Qt::FlatCap)
        return "FlatCap";
    else if(penStyle == Qt::SquareCap)
        return "SquareCap";
    else
        return "RoundCap";
}

QString   RenderArea::getStringPenStyle(Qt::PenStyle penStyle)
{
    if(penStyle == Qt::NoPen)
        return "NoPen";
    else if(penStyle == Qt::SolidLine)
        return "SolidLine";
    else if(penStyle == Qt::DashLine)
        return "DashLine";
    else if(penStyle == Qt::DotLine)
        return "DotLine";
    else if(penStyle == Qt::DashDotLine)
        return "DashDotLine";
    else
        return "DashDotDotLine";
}

QString RenderArea::getStringPenJointStyle(Qt::PenJoinStyle penJointStyle)
{
    if(penJointStyle == Qt::MiterJoin)
        return "MiterJoin";
    else if(penJointStyle == Qt::BevelJoin)
        return "BevelJoin";
    else
        return "RoundJoin";
}

QString RenderArea::getStringBrush(Qt::BrushStyle brush)
{
    if(brush == Qt::SolidPattern)
        return "SolidPattern";
    else if(brush == Qt::HorPattern)
        return "HorPattern";
    else if(brush == Qt::VerPattern)
        return "VerPattern";
    else
        return "NoBrush";
}

QString RenderArea::getStringFlag(Qt::AlignmentFlag  flag)
{
    if(flag == Qt::AlignLeft )
        return "AlignLeft";
    else if(flag == Qt::AlignRight)
        return "AlignRight";
    else if(flag == Qt::AlignTop)
        return "AlignTop";
    else if(flag == Qt::AlignBottom)
        return "AlignBottom";
    else
        return "AlignCenter";
}

 QString RenderArea::getStringFontStyle(QFont::Style fontStyle)
{
    if(fontStyle == QFont::StyleNormal)
        return "StyleNormal";
    else if(fontStyle == QFont::StyleItalic)
        return "StyleItalic";
    else
        return "StyleOblique";
}

QString RenderArea::getStringFontWeight(int fontWeight)
{
    if(fontWeight == 0)
        return "Thin";
    else if(fontWeight == 25)
        return "Light";
    else if(fontWeight == 50)
        return "Normal";
    else
        return "Bold";
}
