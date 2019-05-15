#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtCore/QCoreApplication>
#include <QtDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QMessageBox>
#include <./containers/AwesomeVector.h>
#include "shape.h"
#include <QObject>
#include <QEventLoop>
#include <QUrlQuery>
#include <QPaintEvent>
#include <QFont>

class dbConnection : public QObject{
    Q_OBJECT
public:
    dbConnection();
    QString getShapeTypes();
    QString createUser(QString,QString,QString admin_code = "blank");
    QString userLogin(QString,QString);
    const AwesomeVector<Shape*>& getShapes(QPaintDevice* dev);
    void fetch(QUrlQuery);
    QString getResponse();
    bool saveShape(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString textString="",QString textColor="",
                   QString textAlignment="",QString textPointSize="",QString fontFamily="",QString fontStyle="",QString fontWeight="");
    QString getShapeTypeString(Shape::ShapeType);
    bool createTestimonial(QString,QString);
    bool deleteShape(int);

private slots:
    void onfinish(QNetworkReply*);

private:
   Qt::GlobalColor getColor(QString);
   Qt::PenCapStyle getPenCapStyle(QString);
   Qt::PenStyle getPenStyle(QString);
   Qt::PenJoinStyle getPenJointStyle(QString);
   Qt::BrushStyle getBrushStyle(QString);
   Qt::AlignmentFlag getFlag(QString);
   QFont::Style getFontStyle(QString);
   QFont::Weight getFontWeight(QString);
   Shape* createShapeObject(QString,int,QPaintDevice*,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,
                            QString,QString,QString,QString,QString);
   QString response;
   QUrl url;
};

#endif // DBCONNECTION_H
