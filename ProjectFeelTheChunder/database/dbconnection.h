#ifndef DBCONNECTION_H
#define DBCONNECTION_H

//#include <QtSql>
//#include <QSqlQuery>
#include <QtCore/QCoreApplication>
#include <QtDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QMessageBox>
#include <AwesomeVector.h>
#include <shape.h>
#include <QObject>
#include <QEventLoop>
#include <QUrlQuery>

class dbConnection : public QObject{
    Q_OBJECT
public:
    dbConnection();
    QString getShapeTypes();
    QString createUser(QString,QString,QString admin_code = "blank");
    QString userLogin(QString,QString);
    const AwesomeVector<Shape*>& getShapes();
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
   Shape* createShapeObject(QString,int,QPaintDevice*);
   QString response;
   QUrl url;
   //QSqlDatabase db;
};

#endif // DBCONNECTION_H
