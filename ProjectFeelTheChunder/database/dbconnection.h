#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QtSql>
#include <QSqlQuery>
#include <QtCore/QCoreApplication>
#include <QtDebug>

class dbConnection{

public:
    dbConnection();

private:
   void connect();
   static QSqlDatabase db;
};

#endif // DBCONNECTION_H
