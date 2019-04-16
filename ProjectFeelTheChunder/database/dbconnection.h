#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtSql>
#include <QSqlQuery>
#include <QtCore/QCoreApplication>
#include <QtDebug>

class dbConnection{

public:
    dbConnection();
    QString * getShapeTypes();
    bool createUser(QString,QString,QString admin_code = "blank");
    QString userLogin(QString,QString);
private:
   bool openConnection();
   void closeConnection();
   QSqlDatabase db;
};

#endif // DBCONNECTION_H
