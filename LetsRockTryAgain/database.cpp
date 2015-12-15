#include "database.h"

//Opens the database
void database::start(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
    db.open();
}

// Add scientist to database
void database::addScientist(scientist s){
    QSqlQuery qry;
    qry.prepare("INSERT INTO scientists (Name, Gender, Birthyear, Deathyear) VALUES (:name, :gender, :yob, :yod)");
    qry.bindValue(":name", s.getName());
    qry.bindValue(":gender", s.getGender());
    qry.bindValue(":yob", s.getYob());
    qry.bindValue(":yod", s.getYod());
    qry.exec();
}

//Edit scientist s in database
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

//Add computer to database
void database::addComputer(computer c){
    QSqlQuery qry;
    qry.prepare("INSERT INTO computers (Name, Year, Type, Buildstatus) VALUES (:name, :year, :type, :build)");
    qry.bindValue(":name", c.getName());
    qry.bindValue(":year", c.getYear());
    qry.bindValue(":type", c.getType());
    qry.bindValue(":build", c.getBuilt());
    qry.exec();
}

//Edit computer c in database
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

// Adds a link to database
void database::addLink(int csid, int cid){
    QSqlQuery qry;
    qry.prepare("INSERT INTO link (csid, cid) VALUES (:csid, :cid)");
    qry.bindValue(":csid", csid);
    qry.bindValue(":cid", cid);
    qry.exec();
}

// Edit link in database with the values csid and cid and edit it to newCSID and newCID
void database::editLink(int newCSID, int newCID, int csid, int cid){
    QSqlQuery qry;
    qry.prepare("UPDATE link SET csid = :newCSID, cid = :newCID WHERE csid = :csid AND cid = :cid");
    qry.bindValue(":newCSID", newCSID);
    qry.bindValue(":newCID", newCID);
    qry.bindValue(":csid", csid);
    qry.bindValue(":cid", cid);
    qry.exec();
}

//Get all scientists  from database and fills the vector scientists of these values
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

//Get all computers  from database and fills the vector computers of these values
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

//Get all links  from database and fills the vector links of these values
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

//Searches in database for all scientists that have name, yob or yod in it. If you write male you only get male. Same for female
void database::searchScientist(std::vector<scientist>& scientists, QString string){
    QSqlQuery qry;
    QString query;
    query = "SELECT * FROM scientists WHERE Name LIKE '%" + string + "%' or ";
    query += "Gender LIKE '" + string + "%' or ";
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

//Searches in database for all computers that have name, type or year in it. If you write built you only get built. Same for not built
void database::searchComputer(std::vector<computer>& computers, QString string){
    QSqlQuery qry;
    QString query;
    query = "SELECT * FROM computers WHERE Name LIKE '%" + string + "%' or ";
    query += "Year LIKE '%" + string + "%' or ";
    query += "Type LIKE '%" + string + "%' or ";
    query += "Buildstatus LIKE '" + string + "%'";
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
    QSqlQuery qry;
    qry.prepare("SELECT COUNT(*) FROM link WHERE csid = :csid AND cid = :cid");
    qry.bindValue(":csid", csid);
    qry.bindValue(":cid", cid);
    qry.exec();
    qry.next();
    unsigned int count = qry.value("COUNT(*)").toUInt();
    qDebug() << csid << cid << count;
    if(count != 0){
        return true;
    }
    return false;
}

//Deletes scientits with value id and also all links that he is in
void database::deleteScientist(int id){
    QSqlQuery qry;
    qry.prepare("DELETE FROM scientists WHERE id = :id");
    qry.bindValue(":id", id);
    qry.exec();
    qry.prepare("DELETE FROM link WHERE csid = :id");
    qry.bindValue(":id", id);
    qry.exec();
}

//Deletes computer with value id and also all links that the computer is in
void database::deleteComputer(int id){
    QSqlQuery qry;
    qry.prepare("DELETE FROM computers WHERE id = :id");
    qry.bindValue(":id", id);
    qry.exec();
    qry.prepare("DELETE FROM link WHERE cid = :id");
    qry.bindValue(":id", id);
    qry.exec();
}

//Delete link with these values
void database::deleteLink(int csid, int cid){
    QSqlQuery qry;
    qry.prepare("DELETE FROM link WHERE csid = :csid AND cid = :cid");
    qry.bindValue(":csid", csid);
    qry.bindValue(":cid", cid);
    qry.exec();
}

// Returns the name of scientist with the id = csid
QString database::getCSName(int csid){
    QSqlQuery qry;
    qry.prepare("SELECT Name FROM scientists WHERE id = :id");
    qry.bindValue(":id", csid);
    qry.exec();
    qry.next();
    return qry.value("Name").toString();
}

// Returns the name of computer with the id = cid
QString database::getCName(int cid){
    QSqlQuery qry;
    qry.prepare("SELECT Name FROM computers WHERE id = :id");
    qry.bindValue(":id", cid);
    qry.exec();
    qry.next();
    return qry.value("Name").toString();
}
