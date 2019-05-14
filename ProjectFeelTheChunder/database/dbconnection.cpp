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

Shape* dbConnection::createShapeObject(QString shapeType,int id,QPaintDevice *device){
    Shape * shape = nullptr;
    if(shapeType == "Line"){
        shape = new Line(device,id);
    }else if(shapeType == "Polyline"){
        shape = new Polyline(device,id);
        if(shapeType == "Polyline"||shapeType == "Polygon"){
            for(int j=0;j<dimensions.length();j+2){
                QPoint coord(dimensions[j].toInt(), dimensions[j+1].toInt());
                shapes[i]->addPoint(coord6);
            }
        }
    }else if(shapeType == "Polygon"){
        shape = new Polygon(device,id);
    }else if(shapeType == "Rectangle"){
        shape = new Rectangle(device,id);
    }else if(shapeType == "Ellipse"){
        shape = new Ellipse(device,id);
    }else if(shapeType == "Text"){
        shape = new Text(device,id);
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
    QStringList dimensions;
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
        qDebug() << resultshapes[i];
        QStringList shapedetails = resultshapes[i].split(".");
        shapetype = shapedetails[0];
        shape_id = shapedetails[1].toInt();
        if(shapetype!="Polyline" && shapetype != "Polygon"){
            dimensions = shapedetails[3].split(",");
        }else{
            dimensions = shapedetails[18].remove(0, 1).split(",");
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
        shapes.push_back(createShapeObject(shapetype,shape_id,dev));

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
