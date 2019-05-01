#include "canvas.h"

Canvas::Canvas(QWidget *parent)
      : QWidget(parent), ShapeMagazine(10)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(sizeHint());
    readShapeFile();
}

QSize Canvas::sizeHint() const
{
    return QSize(1000,500);
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(1000,500);
}


void Canvas::paintEvent(QPaintEvent * event)
{
    QPaintDevice* device = this;
    for(int i = 0; i < ShapeMagazine.sizeOf(); i++)
    {
        ShapeMagazine[i]->draw(device);//Draw
        ++i;
    }
}

void Canvas::shapeAdd(Shape* shapeIn)
{
    ShapeMagazine.push_back(shapeIn);//Add to AwesomeVector
    IDCount++;
}

void Canvas::shapeRemove(int i)
{
    ShapeMagazine.erase(i);
}

void Canvas::shapeMove(int index, int coord, int x, int y)
{
    for(int i = 0; i < ShapeMagazine.sizeOf(); i++)
        if(ShapeMagazine[i]->getID() == index){
            ShapeMagazine[i]->move(x,y,coord); break; }
}

void Canvas::writeShapeFile()
{

    /*
    QFile myFile("C:/Users/Oscar/Desktop/OOF-saddleback-cs1c/img/shape.txt");

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
    */
}


void Canvas::readShapeFile()
{

    AwesomeVector<Shape*> shapeMagazine;

    QFile myFile(":/stuff/shapes.txt");

    if(!myFile.open( QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug("Couldnt open the shape file\n");
    }

    QTextStream fileIn(&myFile);
    QString ignoreNewline;
    ignoreNewline = fileIn.readLine();//Removes empty line

    while(!fileIn.atEnd())
    {
        QString garbage; //Will read in identifier and take out ex: "ShapeType:"
        QPen    shapePen;
        QBrush  shapeBrush;


        int shapeIDNum ;
        QString shapeTypeStr = -1;
        Shape::ShapeType shapeTypeEnum;

        //Read ShapeID
        fileIn >> garbage;
        fileIn >> shapeIDNum;

        //Read shape type
        fileIn >> garbage;
        fileIn >> shapeTypeStr;

        //Find correct enum
        shapeTypeEnum = stringToShapeType(shapeTypeStr);

        //Seperate to different shape types
        switch(shapeTypeEnum)
        {
            //Line
        case Shape::ShapeType::Line:
        {
            Line *addLine = new Line(this, 0);
            QPen linePen;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint coord1(coordList[0].toInt(), coordList[1].toInt());
            QPoint coord2(coordList[2].toInt(), coordList[3].toInt());
            addLine->setPts(coord1, coord2);

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            linePen.setColor(strToQTColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            linePen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            linePen.setStyle(strToQTPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            linePen.setCapStyle(strToQTCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            linePen.setJoinStyle(strToQTPenJoinStyle(penJoinStyleStr));

            addLine->setPen(linePen);
            addLine->setId(shapeIDNum); //Set shape ID
            addLine->setShape(ShapeType::LineType);
            shapeAdd(addLine); //Adding shape

            if(addLine->pen().color() == Qt::GlobalColor::blue){qDebug("corrrrrect");}

            break;
        }//END LINETYPE
          //PolyLine
        case ShapeType::PolylineType:
        {
            Polyline *addPolyLine = new Polyline(this, 0);
            QPen polylinePen;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint coord1(coordList[0].toInt(), coordList[1].toInt());
            QPoint coord2(coordList[2].toInt(), coordList[3].toInt());

            addPolyLine->addPoint(coord1); //Set points
            addPolyLine->addPoint(coord2); //Set points

            if(coordList.size() > 4)//Check to see if more points
            {
                QPoint coord3(coordList[4].toInt(), coordList[5].toInt());
                addPolyLine->addPoint(coord3); //Set points

                if(coordList.size() > 6)//If more points
                {
                    QPoint coord4(coordList[6].toInt(), coordList[7].toInt());
                    addPolyLine->addPoint(coord4); //Set points

                    if(coordList.size() > 8)//If more points
                    {
                        QPoint coord5(coordList[8].toInt(), coordList[9].toInt());
                        addPolyLine->addPoint(coord5); //Set points

                        if(coordList.size() > 10)//If more points
                        {
                            QPoint coord6(coordList[10].toInt(), coordList[11].toInt());
                            addPolyLine->addPoint(coord6); //Set points


                        }
                    }
                }
            }//ENd Coordinates


            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            polylinePen.setColor(strToQTColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            polylinePen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            polylinePen.setStyle(strToQTPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            polylinePen.setCapStyle(strToQTCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            polylinePen.setJoinStyle(strToQTPenJoinStyle(penJoinStyleStr));

            addPolyLine->setPen(polylinePen);
            addPolyLine->setId(shapeIDNum);
            addPolyLine->setShape(ShapeType::PolylineType);
            addPolyLine->addNumPoints(coordList.size()/2);
            shapeAdd(addPolyLine); //Adding shape

            break;
        }//END Polyline type

              //Polygon
        case ShapeType::PolygonType:
        {
            Polygon *addPolygon = new Polygon(this, 0);
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

            addPolygon->addPoint(coord1); //Set points
            addPolygon->addPoint(coord2); //Set points

            if(coordList.size() > 4)//Check to see if more points
            {
                QPoint coord3(coordList[4].toInt(), coordList[5].toInt());
                addPolygon->addPoint(coord3); //Set points

                if(coordList.size() > 6)//If more points
                {
                    QPoint coord4(coordList[6].toInt(), coordList[7].toInt());
                    addPolygon->addPoint(coord4); //Set points

                    if(coordList.size() > 8)//If more points
                    {
                        QPoint coord5(coordList[8].toInt(), coordList[9].toInt());
                        addPolygon->addPoint(coord5); //Set points

                        if(coordList.size() > 10)//If more points
                        {
                            QPoint coord6(coordList[10].toInt(), coordList[11].toInt());
                            addPolygon->addPoint(coord6); //Set points

                            if(coordList.size() > 12)//If more points
                            {
                                QPoint coord7(coordList[12].toInt(), coordList[13].toInt());
                                addPolygon->addPoint(coord7); //Set points

                                if(coordList.size() > 14)//If more points
                                {
                                    QPoint coord8(coordList[14].toInt(), coordList[15].toInt());
                                    addPolygon->addPoint(coord8); //Set points


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
            polygonPen.setColor(strToQTColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            polygonPen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            polygonPen.setStyle(strToQTPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            polygonPen.setCapStyle(strToQTCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            polygonPen.setJoinStyle(strToQTPenJoinStyle(penJoinStyleStr));

            //Store Brush Color
            fileIn >> garbage;
            QString brushColorStr;
            fileIn >> brushColorStr;
            polygonBrush.setColor(strToQTColor(brushColorStr));

            //Store BrushStyle
            fileIn >> garbage;
            QString brushStyleStr;
            fileIn >> brushStyleStr;
            polygonBrush.setStyle(strToQTBushStyle(brushStyleStr));

            addPolygon->setPen(polygonPen);
            addPolygon->setBrush(polygonBrush);
            addPolygon->setId(shapeIDNum);
            addPolygon->setShape(ShapeType::PolygonType);
            addPolygon->addNumPoints(coordList.size()/2);
            shapeAdd(addPolygon); //Adding shape
            break;
        }//END Polygontype
           //Rectangle
        case ShapeType::RectangleType:
        {
            Rectangle *addRect = new Rectangle(this, 0);
            QPen rectPen;
            QBrush rectBrush;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint center(coordList[0].toInt(), coordList[1].toInt());
            addRect->setPosition(center);
            addRect->setDimensions(coordList[3].toInt(), coordList[2].toInt());

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            rectPen.setColor(strToQTColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            rectPen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            rectPen.setStyle(strToQTPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            rectPen.setCapStyle(strToQTCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            rectPen.setJoinStyle(strToQTPenJoinStyle(penJoinStyleStr));

            //Store Brush Color
            fileIn >> garbage;
            QString brushColorStr;
            fileIn >> brushColorStr;
            rectBrush.setColor(strToQTColor(brushColorStr));

            //Store BrushStyle
            fileIn >> garbage;
            QString brushStyleStr;
            fileIn >> brushStyleStr;
            rectBrush.setStyle(strToQTBushStyle(brushStyleStr));

            addRect->setPen(rectPen);
            addRect->setBrush(rectBrush);
            addRect->setId(shapeIDNum);
            addRect->setShape(ShapeType::RectangleType);
            shapeAdd(addRect); //Adding shape
            break;
        } //End RecType
            //Square
        case ShapeType::SquareType:
        {
            Rectangle *addSquare = new Rectangle(this, 0);
            QPen sqrPen;
            QBrush sqrBrush;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint center(coordList[0].toInt(), coordList[1].toInt());
            addSquare->setPosition(center);
            addSquare->setDimensions(coordList[2].toInt(), coordList[2].toInt()); //Same length and width

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            sqrPen.setColor(strToQTColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            sqrPen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            sqrPen.setStyle(strToQTPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            sqrPen.setCapStyle(strToQTCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            sqrPen.setJoinStyle(strToQTPenJoinStyle(penJoinStyleStr));

            //Store Brush Color
            fileIn >> garbage;
            QString brushColorStr;
            fileIn >> brushColorStr;
            sqrBrush.setColor(strToQTColor(brushColorStr));

            //Store BrushStyle
            fileIn >> garbage;
            QString brushStyleStr;
            fileIn >> brushStyleStr;
            sqrBrush.setStyle(strToQTBushStyle(brushStyleStr));

            addSquare->setPen(sqrPen);
            addSquare->setBrush(sqrBrush);
            addSquare->setId(shapeIDNum);
            addSquare->setShape(ShapeType::RectangleType);
            shapeAdd(addSquare); //Adding shape
            break;
        }//End Square Type
            //Ellipse
        case ShapeType::EllipseType:
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
            addEllipse->setPosition(center);
            addEllipse->setDimensions(coordList[2].toInt(), coordList[3].toInt()); //Same length and width

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            ellipsePen.setColor(strToQTColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            ellipsePen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            ellipsePen.setStyle(strToQTPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            ellipsePen.setCapStyle(strToQTCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            ellipsePen.setJoinStyle(strToQTPenJoinStyle(penJoinStyleStr));

            //Store Brush Color
            fileIn >> garbage;
            QString brushColorStr;
            fileIn >> brushColorStr;
            ellipseBrush.setColor(strToQTColor(brushColorStr));

            //Store BrushStyle
            fileIn >> garbage;
            QString brushStyleStr;
            fileIn >> brushStyleStr;
            ellipseBrush.setStyle(strToQTBushStyle(brushStyleStr));

            addEllipse->setPen(ellipsePen);
            addEllipse->setBrush(ellipseBrush);
            addEllipse->setId(shapeIDNum);
            addEllipse->setShape(ShapeType::EllipseType);
            shapeAdd(addEllipse); //Adding shape
            break;
        }//End EllipseType
            //Circle
        case ShapeType::CircleType:
        {
            Ellipse *addCircle = new Ellipse(this, 0);
            QPen circPen;
            QBrush circBrush;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint center(coordList[0].toInt(), coordList[1].toInt());
            addCircle->setPosition(center);
            addCircle->setDimensions(coordList[2].toInt(), coordList[2].toInt()); //Same length and width

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            circPen.setColor(strToQTColor(penColorStr));

            //Store Pen Width;
            fileIn >> garbage;
            int penWidth;
            fileIn >> penWidth;
            circPen.setWidth(penWidth);

            //Store Pen Style
            fileIn >> garbage;
            QString penStyleStr;
            fileIn >> penStyleStr;
            circPen.setStyle(strToQTPenStyle(penStyleStr));

            //Store Pen Cap Style
            fileIn >> garbage;
            QString penCapStyleStr;
            fileIn >> penCapStyleStr;
            circPen.setCapStyle(strToQTCapStyle(penCapStyleStr));

            //Store Pen Join Style
            fileIn >> garbage;
            QString penJoinStyleStr;
            fileIn >> penJoinStyleStr;
            circPen.setJoinStyle(strToQTPenJoinStyle(penJoinStyleStr));

            //Store Brush Color
            fileIn >> garbage;
            QString brushColorStr;
            fileIn >> brushColorStr;
            circBrush.setColor(strToQTColor(brushColorStr));

            //Store BrushStyle
            fileIn >> garbage;
            QString brushStyleStr;
            fileIn >> brushStyleStr;
            circBrush.setStyle(strToQTBushStyle(brushStyleStr));

            addCircle->setPen(circPen);
            addCircle->setBrush(circBrush);
            addCircle->setId(shapeIDNum);
            addCircle->setShape(ShapeType::EllipseType);
            shapeAdd(addCircle); //Adding shape
            break;
        }//End CircleType
            //Text
        case ShapeType::TextType:
        {
            Text *addText = new Text(this, 0);
            QPen textPen;
            QFont textFont;

            //Store shape dimensions
            QString coordStr;
            QStringList coordList;

            fileIn >> garbage;

            coordStr = fileIn.readLine();
            coordList = coordStr.split(',');
            QPoint center(coordList[0].toInt(), coordList[1].toInt());
            addText->setPosition(center);
            addText->setDimensions(coordList[2].toInt(), coordList[3].toInt()); //Same length and width

            //Store text
            fileIn >> garbage;
            QString textStr;
            textStr = fileIn.readLine();
            addText->setText(textStr);

            //Store Pen color
            fileIn >> garbage;
            QString penColorStr;
            fileIn >> penColorStr;
            textPen.setColor(strToQTColor(penColorStr));

            //Store Alignment
            fileIn >> garbage;
            QString alignStr;
            fileIn >> alignStr;
            addText->setAlignment(strToQTAlignment(alignStr));

            //Store point size
            fileIn >> garbage;
            int pointSize;
            fileIn >> pointSize;
            textFont.setPointSize(pointSize);

            //Store family
            fileIn >> garbage;
            QString textFamilyStr;
            textFamilyStr = fileIn.readLine();
            textFont.setFamily(textFamilyStr);

            //Store Font style
            fileIn >> garbage;
            QString textFontStyleStr;
            fileIn >> textFontStyleStr;
            textFont.setStyle(strToQTTextStyle(textFontStyleStr));

            //Store Font weight
            fileIn >> garbage;
            QString textFontWeightStr;
            fileIn >> textFontWeightStr;
            textFont.setWeight(strToQTTextWeight(textFontWeightStr));

            addText->setPen(textPen);
            addText->setFont(textFont);
            addText->setId(shapeIDNum);
            addText->setShape(ShapeType::TextType);
            shapeAdd(addText); //Adding shape

            break;
        }//End TextType
        default: {qDebug("error reading file");}
        }//End Switch shapeType
        ignoreNewline = fileIn.readLine();//Removes empty line
    }//EndWhile !atEnd
    myFile.close();

*/
}

Shape::ShapeType Canvas::stringToShapeType(QString shapeTypeStr)
{
    Shape::ShapeType shapeTypeEnum;

    if(shapeTypeStr.compare("Line") == 0)//Equals 0 when equal
    {
        shapeTypeEnum = Shape::ShapeType::Line;
    }
    else if(shapeTypeStr.compare("Polyline") == 0)//Equals 0 when equal
    {
        shapeTypeEnum = Shape::ShapeType::Polyline;
    }
    else if(shapeTypeStr.compare("Polygon") == 0)//Equals 0 when equal
    {
        shapeTypeEnum = Shape::ShapeType::Polygon;
    }
    else if(shapeTypeStr.compare("Rectangle") == 0)//Equals 0 when equal
    {
        shapeTypeEnum = Shape::ShapeType::Rectangle;
    }/*
    else if(shapeTypeStr.compare("Square") == 0)//Equals 0 when equal
    {
        shapeTypeEnum = Shape::ShapeType::Square;
    }*/
    else if(shapeTypeStr.compare("Ellipse") == 0)//Equals 0 when equal
    {
        shapeTypeEnum = Shape::ShapeType::Ellipse;
    }/*
    else if(shapeTypeStr.compare("Circle") == 0)//Equals 0 when equal
    {
        shapeTypeEnum = Shape::ShapeType::Circle;
    }*/
    else if(shapeTypeStr.compare("Text") == 0)//Equals 0 when equal
    {
        shapeTypeEnum = Shape::ShapeType::Text;
    }
    else
    {
        shapeTypeEnum = Shape::ShapeType::null;
    }


    return shapeTypeEnum;
}

Qt::GlobalColor Canvas::strToQTColor(QString strColorIn)
{
    if(strColorIn == "blue")
        return Qt::blue;
    else if(strColorIn == "red")
        return Qt::red;
    else if(strColorIn == "green")
        return Qt::green;
    else if(strColorIn == "yellow")
        return Qt::yellow;
    else if(strColorIn == "black")
        return Qt::black;
    else if(strColorIn == "white")
        return Qt::white;
    else if(strColorIn == "cyan")
        return Qt::cyan;
    else if(strColorIn == "magenta")
        return Qt::magenta;
    else
        return Qt::gray;
}

Qt::PenCapStyle Canvas::strToQTCapStyle(QString penCapStyleStrIn)
{
    if(penCapStyleStrIn == "FlatCap")
        return Qt::FlatCap;
    else if(penCapStyleStrIn == "SquareCap")
        return Qt::SquareCap;
    else
        return Qt::RoundCap;
}

Qt::PenStyle Canvas::strToQTPenStyle(QString penStyleStrIn)
{
    if(penStyleStrIn == "NoPen")
        return Qt::NoPen;
    else if(penStyleStrIn == "SolidLine")
        return Qt::SolidLine;
    else if(penStyleStrIn == "DashLine")
        return Qt::DashLine;
    else if(penStyleStrIn == "DotLine")
        return Qt::DotLine;
    else if(penStyleStrIn == "DashDotLine")
        return Qt::DashDotLine;
    else
        return Qt::DashDotDotLine;
}

Qt::PenJoinStyle Canvas::strToQTPenJoinStyle(QString penJoinStyleStrIn)
{
    if(penJoinStyleStrIn == "MiterJoin")
        return Qt::MiterJoin;
    else if(penJoinStyleStrIn == "BevelJoin")
        return Qt::BevelJoin;
    else
        return Qt::RoundJoin;
}

Qt::BrushStyle Canvas::strToQTBushStyle(QString brushStyleStr)
{
    if(brushStyleStr == "SolidPattern")
        return Qt::SolidPattern;
    else if(brushStyleStr == "HorPattern")
        return Qt::HorPattern;
    else if(brushStyleStr == "VerPattern")
        return Qt::VerPattern;
    else
        return Qt::NoBrush;
}

Qt::AlignmentFlag Canvas::strToQTAlignment(QString alignStrIn)
{
    if(alignStrIn == "AlignLeft")
        return Qt::AlignLeft;
    else if(alignStrIn == "AlignRight")
        return Qt::AlignRight;
    else if(alignStrIn == "AlignTop")
        return Qt::AlignTop;
    else if(alignStrIn == "AlignBottom")
        return Qt::AlignBottom;
    else
        return Qt::AlignCenter;
}

QFont::Style Canvas::strToQTTextStyle(QString textFontStyleStrIn)
{
    if(textFontStyleStrIn == "StyleNormal")
        return QFont::StyleNormal;
    else if(textFontStyleStrIn == "StyleItalic")
        return QFont::StyleItalic;
    else
        return QFont::StyleOblique;
}

QFont::Weight Canvas::strToQTTextWeight(QString textFontWeightStrIn)
{
    if(textFontWeightStrIn == "Thin")
        return QFont::Thin;
    else if(textFontWeightStrIn == "Light")
        return QFont::Light;
    else if(textFontWeightStrIn == "Normal")
        return QFont::Normal;
    else
        return QFont::Bold;
}

/***************************************
 * QT to String
 *************************************/

QString Canvas::QTColorToStr(QColor strColorIn)
{
    if(strColorIn == Qt::blue)
        return "blue";
    else if(strColorIn == Qt::red)
        return "red";
    else if(strColorIn == Qt::green)
        return "green";
    else if(strColorIn == Qt::yellow)
        return "yellow";
    else if(strColorIn == Qt::black)
        return "black";
    else if(strColorIn == Qt::white)
        return "white";
    else if(strColorIn == Qt::cyan)
        return "cyan";
    else if(strColorIn == Qt::magenta)
        return "magenta";
    else
        return "gray";
}


QString Canvas::QTCapStyleToStr(Qt::PenCapStyle penCapStyleStrIn)
{
    if(penCapStyleStrIn == Qt::FlatCap)
        return "FlatCap";
    else if(penCapStyleStrIn == Qt::SquareCap)
        return "SquareCap";
    else
        return "RoundCap";
}

QString   Canvas::QTPenStyleToStr(Qt::PenStyle penStyleStrIn)
{
    if(penStyleStrIn == Qt::NoPen)
        return "NoPen";
    else if(penStyleStrIn == Qt::SolidLine)
        return "SolidLine";
    else if(penStyleStrIn == Qt::DashLine)
        return "DashLine";
    else if(penStyleStrIn == Qt::DotLine)
        return "DotLine";
    else if(penStyleStrIn == Qt::DashDotLine)
        return "DashDotLine";
    else
        return "DashDotDotLine";
}

QString Canvas::QTPenJoinStyleToStr(Qt::PenJoinStyle penJoinStyleStrIn)
{
    if(penJoinStyleStrIn == Qt::MiterJoin)
        return "MiterJoin";
    else if(penJoinStyleStrIn == Qt::BevelJoin)
        return "BevelJoin";
    else
        return "RoundJoin";
}

QString Canvas::QTBushStyleToStr(Qt::BrushStyle brushStyleStr)
{
    if(brushStyleStr == Qt::SolidPattern)
        return "SolidPattern";
    else if(brushStyleStr == Qt::HorPattern)
        return "HorPattern";
    else if(brushStyleStr == Qt::VerPattern)
        return "VerPattern";
    else
        return "NoBrush";
}

QString Canvas::QTAlignmentToStr(Qt::AlignmentFlag  alignStrIn)
{
    if(alignStrIn == Qt::AlignLeft )
        return "AlignLeft";
    else if(alignStrIn == Qt::AlignRight)
        return "AlignRight";
    else if(alignStrIn == Qt::AlignTop)
        return "AlignTop";
    else if(alignStrIn == Qt::AlignBottom)
        return "AlignBottom";
    else
        return "AlignCenter";
}

 QString Canvas::QTTextStyleToStr(QFont::Style textFontStyleStrIn)
{
    if(textFontStyleStrIn == QFont::StyleNormal)
        return "StyleNormal";
    else if(textFontStyleStrIn == QFont::StyleItalic)
        return "StyleItalic";
    else
        return "StyleOblique";
}

QString Canvas::QTTextWeightToStr(int textFontWeightStrIn)
{

    if(textFontWeightStrIn == 0)
        return "Thin";
    else if(textFontWeightStrIn == 25)
        return "Light";
    else if(textFontWeightStrIn == 50)
        return "Normal";
    else
        return "Bold";
}
