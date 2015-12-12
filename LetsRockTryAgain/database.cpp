#include "database.h"

void database::start(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
    db.open();
}

QSqlQuery database::returnCSquery(){
    QSqlQuery* qry=new QSqlQuery(db);
    qry->prepare("SELECT Name, Gender, Birthyear, Deathyear FROM scientists");
    qry->exec();
    return *qry;
}

QSqlQuery database::returnCquery(){
    QSqlQuery* qry=new QSqlQuery(db);
    qry->prepare("SELECT * FROM computers");
    qry->exec();
    return *qry;
}
void database::addScientist(QString name, QString gender, QString yob, QString yod){
    QSqlQuery qry;
    qry.prepare("INSERT INTO scientists (Name, Gender, Birthyear, Deathyear) VALUES (:name, :gender, :yob, :yod)");
    qry.bindValue(":name", name);
    qry.bindValue(":gender", gender);
    qry.bindValue(":yob", yob);
    qry.bindValue(":yod", yod);
    qry.exec();
}

void database::addComputer(QString name, QString year, QString type, QString build){
    QSqlQuery qry;
    qry.prepare("INSERT INTO computers (Name, Year, Type, Buildstatus) VALUES (:name, :year, :type, :build)");
    qry.bindValue(":name", name);
    qry.bindValue(":year", year);
    qry.bindValue(":type", type);
    qry.bindValue(":build", build);
    qry.exec();
}
