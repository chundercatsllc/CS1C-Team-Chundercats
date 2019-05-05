#include "dbconnection.h"

dbConnection::dbConnection(){
   db = QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("178.128.15.169");
   db.setUserName("snarf");
   db.setPassword("snarfsnarf");
   db.setDatabaseName("chundercats2Dmodeling");
}

bool dbConnection::openConnection(){
    if(db.open()){
        return true;
    }
    return false;
}

void dbConnection::closeConnection(){
    db.close();
}

QString * dbConnection::getShapeTypes(){
    QString * shapes = nullptr;
    if(openConnection()){
        QSqlQuery query("SELECT shape FROM Shape_Type;");
        query.exec();
        shapes = new QString[query.size()];
        qDebug() << query.size();
        int shape = query.record().indexOf("shape");
        int i = 0;
        while (query.next()) {
             shapes[i] = query.value(shape).toString();
             i++;
        }
        closeConnection();
    }
    return shapes;
}

bool dbConnection::createUser(QString user_name,QString password,QString admin_code){ //query needs fix, mysql syntax is limiting
    if(openConnection()){
        QSqlQuery query;
        query.prepare("CALL create_user(:username,:password,:type);");
        query.bindValue(":username", user_name);
        query.bindValue(":password", password);
        if(admin_code == "chunderkitten"){
            query.bindValue(":type", "admin");
        }else{
            query.bindValue(":type","user");
        }
        query.exec();
        if(query.numRowsAffected() > 0){
            return true;
        }
    }
    return false;
}

QString dbConnection::userLogin(QString user_name,QString password){
    if(openConnection()){
        QSqlQuery query;
        query.prepare("CALL user_login(:user_name,:password);");
        query.bindValue(":user_name",user_name);
        query.bindValue(":password",password);
        query.exec();
        int type_index = query.record().indexOf("user_type");
        closeConnection();
        while(query.next()){
            if(query.value(type_index).toString() == "failed"){
                return "Invalid username or password";
            }else{
                return query.value(type_index).toString();
            }
        }
    }
    return "Connection Failed";
}
