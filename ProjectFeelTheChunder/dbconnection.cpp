#include <dbconnection.h>

dbConnection::dbConnection(){
   response = "";
   //url.setUrl("http://www.chundercats.best/chundercats.php");
   url.setUrl("http://localhost/chundercats/chundercats.php");
}

void dbConnection::onfinish(QNetworkReply *rep){
    QByteArray bts = rep->readAll();
    QString str(bts);
    response = str;
}

QString dbConnection::getResponse(){
    return response;
}

void dbConnection::fetch(QUrlQuery query){
    QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
    //connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));
    connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(onfinish(QNetworkReply*)));
    url.setQuery(query.query());
    mgr->get(QNetworkRequest(url));
    QEventLoop loop;
    connect(mgr, SIGNAL(finished(QNetworkReply*)),&loop, SLOT(quit()));
    loop.exec();
}

QString dbConnection::getShapeTypes(){
    QUrlQuery query;
    query.addQueryItem("action","shape_type");
    fetch(query);
    return response;
}

QString dbConnection::createUser(QString user_name,QString password,QString admin_code){
    QUrlQuery query;
    if(admin_code == "chunderkitten"){
        query.addQueryItem("action","create_user");
        query.addQueryItem("user_name", user_name);
        query.addQueryItem("password", password);
        query.addQueryItem("type", "admin");
        fetch(query);
    }else{
        return "Sorry, code is incorrect. Please try again.";
    }
    return response;
}

QString dbConnection::userLogin(QString user_name,QString password){
    QUrlQuery query;
    query.addQueryItem("action","login");
    query.addQueryItem("user_name",user_name);
    query.addQueryItem("password",password);
    fetch(query);
    if(response == "failed"){
        return "Invalid username or password";
    }else{
        return response;
    }
}

Qt::PenCapStyle dbConnection::getPenCapStyle(QString capStr){

    if(capStr == "SquareCap"){
        return Qt::SquareCap;
    }else if(capStr == "FlatCap"){
        return Qt::FlatCap;
    }else{
        return Qt::RoundCap;
    }
}

Qt::GlobalColor dbConnection::getColor(QString colorStr){
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

Qt::PenStyle dbConnection::getPenStyle(QString penStr)
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

Qt::PenJoinStyle dbConnection::getPenJointStyle(QString penJointStr)
{
    if(penJointStr == "MiterJoin")
        return Qt::MiterJoin;
    else if(penJointStr == "BevelJoin")
        return Qt::BevelJoin;
    else
        return Qt::RoundJoin;
}

Qt::BrushStyle dbConnection::getBrushStyle(QString brushStr)
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

Qt::AlignmentFlag dbConnection::getFlag(QString flagStr)
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

QFont::Style dbConnection::getFontStyle(QString fontStyleStr)
{
    if(fontStyleStr == "StyleNormal")
        return QFont::StyleNormal;
    else if(fontStyleStr == "StyleItalic")
        return QFont::StyleItalic;
    else
        return QFont::StyleOblique;
}

QFont::Weight dbConnection::getFontWeight(QString fontWeightStr)
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

QString dbConnection::getShapeTypeString(Shape::ShapeType shapeType){
    QString shape;
    switch(shapeType){
        case Shape::ShapeType::Line:
            shape = "Line";
        break;
        case Shape::ShapeType::Polyline:
            shape = "Polyline";
        break;
        case Shape::ShapeType::Polygon:
            shape = "Polygon";
        break;
        case Shape::ShapeType::Rectangle:
            shape = "Rectangle";
        break;
        case Shape::ShapeType::Ellipse:
            shape = "Ellipse";
        break;
        case Shape::ShapeType::Text:
            shape = "Text";
        break;
    }
    return shape;
}

Shape* dbConnection::createShapeObject(QString shapeType,int id,QPaintDevice *device,QString dimensions,QString penColor,QString penWidth,QString penStyle,QString penCapStyle,
                                       QString penJoinStyle,QString brushColor,QString brushStyle,QString textString,QString textColor,
                                       QString textAlignment,QString textPointSize,QString fontFamily,QString fontStyle,QString fontWeight){
    Shape * shape = nullptr;
    QStringList dimensionList;
    if(shapeType == "Line"){
        Line * linebacker = new Line(device,id);
        QPen linePen;
        QPoint coord1(dimensionList[0].toInt(), dimensionList[1].toInt());
        QPoint coord2(dimensionList[2].toInt(), dimensionList[3].toInt());
        linebacker->setPoints(coord1, coord2);
        linePen.setColor(getColor(penColor));
        linePen.setWidth(penWidth.toInt());
        linePen.setStyle(getPenStyle(penStyle));
        linePen.setCapStyle(getPenCapStyle(penCapStyle));
        linePen.setJoinStyle(getPenJointStyle(penJoinStyle));
        linebacker->setPen(linePen);
        linebacker->setShape(Shape::ShapeType::Line);
        shape = linebacker;
    }else if(shapeType == "Polyline"){
        Polyline *newPolly = new Polyline(device, id);
        QPen polylinePen;
        dimensionList = dimensions.remove(0, 1).split(",");
        for(int j=0;j<dimensions.length();j+=2){
            QPoint pt1(dimensionList[0].toInt(), dimensionList[1].toInt());
            newPolly->addPoint(pt1);
        }
        polylinePen.setColor(getColor(penColor));
        polylinePen.setWidth(penWidth.toInt());
        polylinePen.setStyle(getPenStyle(penStyle));
        polylinePen.setCapStyle(getPenCapStyle(penCapStyle));
        polylinePen.setJoinStyle(getPenJointStyle(penJoinStyle));
        newPolly->setPen(polylinePen);
        newPolly->setShape(Shape::ShapeType::Polyline);
        newPolly->addNumPoints(dimensionList.size()/2);
        shape = newPolly;
    }else if(shapeType == "Polygon"){
        Polygon *poliGonGin = new Polygon(device, id);
        QPen polygonPen;
        QBrush polygonBrush;
        for(int j=0;j<dimensions.length();j+=2){
            QPoint coord1(dimensionList[0].toInt(), dimensionList[1].toInt());
            poliGonGin->addVertex(coord1);
        }
        polygonPen.setColor(getColor(penColor));
        polygonPen.setWidth(penWidth.toInt());
        polygonPen.setStyle(getPenStyle(penStyle));
        polygonPen.setCapStyle(getPenCapStyle(penCapStyle));
        polygonPen.setJoinStyle(getPenJointStyle(penJoinStyle));
        polygonBrush.setColor(getBrushStyle(brushColor));
        polygonBrush.setStyle(getBrushStyle(brushStyle));
        poliGonGin->setPen(polygonPen);
        poliGonGin->setBrush(polygonBrush);
        poliGonGin->setShape(Shape::ShapeType::Polygon);
        poliGonGin->setNumVertices(dimensionList.size()/2);
    }else if(shapeType == "Rectangle"){
        Rectangle *RECTIFYYY = new Rectangle(device, id);
        QPen rectPen;
        QBrush rectBrush;
        QPoint center(dimensionList[0].toInt(), dimensionList[1].toInt());
        RECTIFYYY->setLocation(center);
        RECTIFYYY->setDimensions(dimensionList[3].toInt(), dimensionList[2].toInt());
        rectPen.setColor(getColor(penColor));
        rectPen.setWidth(penWidth.toInt());
        rectPen.setStyle(getPenStyle(penStyle));
        rectPen.setCapStyle(getPenCapStyle(penCapStyle));
        rectPen.setJoinStyle(getPenJointStyle(penJoinStyle));
        rectBrush.setColor(getColor(brushColor));
        rectBrush.setStyle(getBrushStyle(brushStyle));
        RECTIFYYY->setPen(rectPen);
        RECTIFYYY->setBrush(rectBrush);
        RECTIFYYY->setShape(Shape::ShapeType::Rectangle);
        shape = RECTIFYYY;
    }else if(shapeType == "Ellipse"){
        Ellipse *addEllipse = new Ellipse(device, id);
        QPen ellipsePen;
        QBrush ellipseBrush;
        QPoint center(dimensionList[0].toInt(), dimensionList[1].toInt());
        addEllipse->setLocation(center);
        addEllipse->setDimensions(dimensionList[2].toInt(), dimensionList[3].toInt());
        ellipsePen.setColor(getColor(penColor));
        ellipsePen.setWidth(penWidth.toInt());
        ellipsePen.setStyle(getPenStyle(penStyle));
        ellipsePen.setCapStyle(getPenCapStyle(penCapStyle));
        ellipsePen.setJoinStyle(getPenJointStyle(penJoinStyle));
        ellipseBrush.setColor(getColor(brushColor));
        ellipseBrush.setStyle(getBrushStyle(brushStyle));
        addEllipse->setPen(ellipsePen);
        addEllipse->setBrush(ellipseBrush);
        addEllipse->setShape(Shape::ShapeType::Ellipse);
        shape = addEllipse;
    }else if(shapeType == "Text"){
        Text *letsGetTexty = new Text(device, id);
        QPen textPen;
        QFont textFont;
        QPoint center(dimensionList[0].toInt(), dimensionList[1].toInt());
        letsGetTexty->setLocation(center);
        letsGetTexty->setDimensions(dimensionList[2].toInt(), dimensionList[3].toInt());
        letsGetTexty->setText(textString);
        textPen.setColor(getColor(textColor));
        letsGetTexty->setFlag(getFlag(textAlignment));
        textFont.setPointSize(textPointSize.toInt());
        textFont.setFamily(fontFamily);
        textFont.setStyle(getFontStyle(fontStyle));
        textFont.setWeight(getFontWeight(fontWeight));
        letsGetTexty->setPen(textPen);
        letsGetTexty->setFont(textFont);
        letsGetTexty->setShape(Shape::ShapeType::Text);
        shape = letsGetTexty;
    }
    return shape;
}

bool dbConnection::saveShape(QString shapetype,QString dimensions,QString penColor,QString penWidth,QString penStyle,QString penCapStyle,
                             QString penJoinStyle,QString brushColor,QString brushStyle,QString textString,QString textColor,
                             QString textAlignment,QString textPointSize,QString fontFamily,QString fontStyle,QString fontWeight){
    QUrlQuery query;
    //Shape::ShapeType shapetype = shape->getShape();
    query.addQueryItem("action","save_shape");
    query.addQueryItem("shape",shapetype);//getShapeTypeString(shapetype));
    query.addQueryItem("dimensions",dimensions);
    //if(shapetype != Shape::ShapeType::Text){
    if(shapetype != "Text"){
        query.addQueryItem("pen_color",penColor);
        query.addQueryItem("pen_width",penWidth);
        query.addQueryItem("pen_style",penStyle);
        query.addQueryItem("pen_cap_style",penCapStyle);
        query.addQueryItem("pen_join_style",penJoinStyle);
        //if(shapetype != Shape::ShapeType::Line && shapetype != Shape::ShapeType::Polyline){
        if(shapetype != "Line" && shapetype != "Polyline"){
            query.addQueryItem("brush_color",brushColor);
            query.addQueryItem("brush_style",brushStyle);
        }
    }else{
        query.addQueryItem("text_string",textString);
        query.addQueryItem("text_color",textColor);
        query.addQueryItem("text_alignment",textAlignment);
        query.addQueryItem("text_point_size",textPointSize);
        query.addQueryItem("text_font_family",fontFamily);
        query.addQueryItem("text_font_style",fontStyle);
        query.addQueryItem("text_font_weight",fontWeight);
    }
    fetch(query);
    if(response == "success"){
        return true;
    }else{
        return false;
    }

}

const AwesomeVector<Shape*>& dbConnection::getShapes(QPaintDevice* dev){
    AwesomeVector<Shape*> shapes;
    QUrlQuery query;
    query.addQueryItem("action","get_shapes");
    fetch(query);
    QStringList resultshapes = response.split("|");
    QString shapetype;
    int shape_id;
    QString dimensions;
    QString penColor;
    QString penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;
    QString brushColor;
    QString brushStyle;
    QString textString;
    QString textColor;
    QString textAlignment;
    QString textPointSize;
    QString fontFamily;
    QString fontStyle;
    QString fontWeight;

    for(int i=0;i<resultshapes.length();i++){
        QStringList shapedetails = resultshapes[i].split(".");
        shapetype = shapedetails[0];
        shape_id = shapedetails[1].toInt();
        if(shapetype!="Polyline" && shapetype != "Polygon"){
            dimensions = shapedetails[3];
        }else{
            dimensions = shapedetails[18];
        }
        penColor = shapedetails[4];
        penWidth = shapedetails[5];
        penStyle = shapedetails[6];
        penCapStyle = shapedetails[7];
        penJoinStyle = shapedetails[8];
        brushColor = shapedetails[9];
        brushStyle = shapedetails[10];
        textString = shapedetails[11];
        textColor = shapedetails[12];
        textAlignment = shapedetails[13];
        textPointSize = shapedetails[14];
        fontFamily = shapedetails[15];
        fontStyle = shapedetails[16];
        fontWeight = shapedetails[17];
        shapes.push_back(createShapeObject(shapetype,shape_id,dev,dimensions,penColor,penWidth,penStyle,penCapStyle,penJoinStyle,brushColor,
                          brushStyle,textString,textColor,textAlignment,textPointSize,fontFamily,fontStyle,fontWeight));

    }
    return shapes;
}

bool dbConnection::createTestimonial(QString name,QString testimonial){
    QUrlQuery query;
    query.addQueryItem("action","testimonial");
    query.addQueryItem("name",name);
    query.addQueryItem("testimonial",testimonial);
    fetch(query);
    if(response == "success"){
        return true;
    }else{
        return false;
    }
}

bool dbConnection::deleteShape(int id){
    QString shape_id = QString::number(id);
    QUrlQuery query;
    query.addQueryItem("action","delete_shape");
    query.addQueryItem("shape_id",shape_id);
    fetch(query);
    if(response == "success"){
        return true;
    }else{
        return false;
    }
}
