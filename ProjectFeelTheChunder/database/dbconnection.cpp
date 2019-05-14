#include <dbconnection.h>

dbConnection::dbConnection(){
   response = "";
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

Shape* dbConnection::createShapeObject(QString shapeType,int id){
    Shape * shape = nullptr;
    if(shapeType == "Line"){
        shape = new Line();
    }else if(shapeType == "Polyline"){
        shape = new Polyline();
    }else if(shapeType == "Polygon"){
        shape = new Polygon();
    }else if(shapeType == "Rectangle"){
        shape = new Rectangle();
    }else if(shapeType == "Ellipse"){
        shape = new Ellipse();
    }else if(shapeType == "Text"){
        shape = new Text();
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
    qDebug()<<response;
    if(response == "success"){
        return true;
    }else{
        return false;
    }

}

const AwesomeVector<Shape*>& dbConnection::getShapes(){
    AwesomeVector<Shape*> shapes;

    return shapes;
}
