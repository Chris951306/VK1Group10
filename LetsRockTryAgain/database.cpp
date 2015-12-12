#include "database.h"

void database::start(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
    db.open();
}

QSqlQuery database::returnCSquery(){
    QSqlQuery* qry=new QSqlQuery(db);
    qry->prepare("SELECT * FROM scientists");
    qry->exec();
    return *qry;
}

QSqlQuery database::returnCquery(){
    QSqlQuery* qry=new QSqlQuery(db);
    qry->prepare("SELECT * FROM computers");
    qry->exec();
    return *qry;
}
