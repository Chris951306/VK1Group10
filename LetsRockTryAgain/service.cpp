#include "service.h"

void service::start(){
    db.start();
}

QSqlQuery service::returnCSquery(){
    return db.returnCSquery();
}

QSqlQuery service::returnCquery(){
    return db.returnCquery();
}

void service::addScientist(QString name, QString gender, QString yob, QString yod){
    db.addScientist(name, gender, yob, yod);
}

void service::addComputer(QString name, QString year, QString type, QString build){
    db.addComputer(name, year, type, build);
}
