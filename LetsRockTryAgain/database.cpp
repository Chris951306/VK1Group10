#include "database.h"

void database::start(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
    db.open();
}

void database::addScientist(scientist s){
    QSqlQuery qry;
    qry.prepare("INSERT INTO scientists (Name, Gender, Birthyear, Deathyear) VALUES (:name, :gender, :yob, :yod)");
    qry.bindValue(":name", s.getName());
    qry.bindValue(":gender", s.getGender());
    qry.bindValue(":yob", s.getYob());
    qry.bindValue(":yod", s.getYod());
    qry.exec();
}

void database::addComputer(computer c){
    QSqlQuery qry;
    qry.prepare("INSERT INTO computers (Name, Year, Type, Buildstatus) VALUES (:name, :year, :type, :build)");
    qry.bindValue(":name", c.getName());
    qry.bindValue(":year", c.getYear());
    qry.bindValue(":type", c.getType());
    qry.bindValue(":build", c.getBuilt());
    qry.exec();
}

void database::getAllScientists(std::vector<scientist>& scientists){
    QSqlQuery qry;
    qry.exec("SELECT * FROM scientists");
    while(qry.next()){
        int id = qry.value("id").toInt();
        QString name = qry.value("Name").toString();
        QString gender = qry.value("Gender").toString();
        QString yob = qry.value("Birthyear").toString();
        QString yod = qry.value("Deathyear").toString();
        scientist temp(id, name, gender, yob, yod);
        scientists.push_back(temp);
    }
}

void database::getAllComputers(std::vector<computer>& computers){
    QSqlQuery qry;
    qry.exec("SELECT * FROM computers");
    while(qry.next()){
        int id = qry.value("id").toInt();
        QString name = qry.value("Name").toString();
        QString year = qry.value("Year").toString();
        QString type = qry.value("Type").toString();
        QString built = qry.value("Buildstatus").toString();
        computer temp(id, name, year, type, built);
        computers.push_back(temp);
    }
}

void database::searchScientist(std::vector<scientist>& scientists, QString string){
    QSqlQuery qry;
    QString query;
    query = "SELECT * FROM scientists WHERE Name LIKE '%" + string + "%' or ";
    query += "Gender LIKE '" + string + "' or ";
    query += "Birthyear LIKE '%" + string + "%' or ";
    query += "Deathyear LIKE '%" + string + "%'";
    qry.exec(query);
    while(qry.next()){
        int id = qry.value("id").toInt();
        QString name = qry.value("Name").toString();
        QString gender = qry.value("Gender").toString();
        QString yob = qry.value("Birthyear").toString();
        QString yod = qry.value("Deathyear").toString();
        scientist temp(id, name, gender, yob, yod);
        scientists.push_back(temp);
    }
}

void database::searchComputer(std::vector<computer>& computers, QString string){
    QSqlQuery qry;
    QString query;
    query = "SELECT * FROM computers WHERE Name LIKE '%" + string + "%' or ";
    query += "Year LIKE '%" + string + "%' or ";
    query += "Type LIKE '%" + string + "%' or ";
    query += "Buildstatus LIKE '" + string + "'";
    qry.exec(query);
    while(qry.next()){
        int id = qry.value("id").toInt();
        QString name = qry.value("Name").toString();
        QString year = qry.value("Year").toString();
        QString type = qry.value("Type").toString();
        QString built = qry.value("Buildstatus").toString();
        computer temp(id, name, year, type, built);
        computers.push_back(temp);
    }
}
