#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtSql>
#include <QSqlQuery>
#include <QtCore/QCoreApplication>
#include <QtDebug>
#include <AwesomeVector.h>
#include <shape.h>

class dbConnection{

public:
    dbConnection();
    QString * getShapeTypes();
    bool createUser(QString,QString,QString admin_code = "blank");
    QString userLogin(QString,QString);
    const AwesomeVector<Shape*>& getShapes();
private:
   bool openConnection();
   void closeConnection();
   Shape* createShapeObject(QString,int);
   QSqlDatabase db;
};

#endif // DBCONNECTION_H
