#include "dbconnection.h"

dbConnection::dbConnection(){
   db = QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("134.209.58.66");
   db.setUserName("snarf");
   db.setPassword("snarfsnarf");
   db.setDatabaseName("chundercats2Dmodeling");
}

void dbConnection::connect(){
    if(db.open()){
        qDebug() << "made it";
        db.close();
    }else{
        qDebug() << "didnt make it";
    }
}
