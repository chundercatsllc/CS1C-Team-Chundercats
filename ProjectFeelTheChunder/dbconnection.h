#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtSql>
#include <QSqlQuery>
#include <QtCore/QCoreApplication>
#include <QtDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QMessageBox>
#include "containers/AwesomeVector.h"
#include <shape.h>
#include <QObject>
#include <QEventLoop>
#include <QUrlQuery>

class dbConnection : public QObject{
    Q_OBJECT
public:
   // dbConnection();
    QString getShapeTypes();
    QString createUser(QString,QString,QString admin_code = "blank");
    QString userLogin(QString,QString);
    const AwesomeVector<Shape*>& getShapes();
    void fetch(QUrlQuery);
    QString getResponse();

private slots:
    void onfinish(QNetworkReply*);

private:
   bool openConnection();
   void closeConnection();
   Shape* createShapeObject(QString,int);
   QString response;
   QSqlDatabase db;
};

#endif // DBCONNECTION_H
