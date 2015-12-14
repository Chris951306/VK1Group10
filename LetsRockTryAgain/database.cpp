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

void database::editScientist(scientist s){
    QSqlQuery qry;
    qry.prepare("UPDATE scientists SET Name = :name, Gender = :gender, Birthyear = :yob, Deathyear = :yod WHERE id = :id");
    qry.bindValue(":id", s.getId());
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

void database::editComputer(computer c){
    QSqlQuery qry;
    qry.prepare("UPDATE scientists SET Name = :name, Year = :year, Type = :type, Buildstatus = :build WHERE id = :id");
    qry.bindValue(":id", c.getId());
    qry.bindValue(":year", c.getYear());
    qry.bindValue(":type", c.getType());
    qry.bindValue(":name", c.getName());
    qry.bindValue(":build", c.getBuilt());
    qry.exec();
}

// Adds a link to SQL server
void database::addLink(int csid, int cid){
    QSqlQuery query;
    query.prepare("INSERT INTO link (csid, cid) VALUES (:csid, :cid)");
    query.bindValue(":csid", csid);
    query.bindValue(":cid", cid);
    query.exec();
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

void database::getAllLinks(std::vector<link> &links){
    QSqlQuery qry;
    qry.exec("SELECT * FROM link");
    while(qry.next()){
        int csid = qry.value("csid").toInt();
        int cid = qry.value("cid").toInt();
        link temp(csid, cid);
        links.push_back(temp);
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

// Returns true if link already exists
bool database::isLink(int csid, int cid){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM link WHERE csid = :csid AND cid = :cid");
    query.bindValue(":csid", csid);
    query.bindValue(":cid", cid);
    query.exec();
    query.next();
    unsigned int count = query.value("COUNT(*)").toUInt();
    if(count != 0){
        return true;
    }
    return false;
}

int database::countScientists(){
    QSqlQuery qry;
    qry.exec("SELECT COUNT(id) FROM scientists");
    qry.next();
    return qry.value("COUNT(id)").toInt();
}

int database::countComputers(){
    QSqlQuery qry;
    qry.exec("SELECT COUNT(id) FROM computers");
    qry.next();
    return qry.value("COUNT(id)").toInt();
}

void database::deleteLink(int csid, int cid){
    QSqlQuery qry;
    qDebug() << csid << " " << cid;
    qry.prepare("DELETE FROM link WHERE csid = :csid AND cid = :cid");
    qry.bindValue(":csid", csid);
    qry.bindValue(":cid", cid);
    qry.exec();
}
