#include "database.h"

void database::start(){
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
    db.open();
}

unsigned int database::returnCScount(){
    QSqlQuery query;
    query.exec("SELECT COUNT(id) FROM scientists");
    query.next();
    return query.value("COUNT(id)").toUInt();
}

unsigned int database::returnCcount(){
    QSqlQuery query;
    query.exec("SELECT COUNT(id) FROM computers");
    query.next();
    return query.value("COUNT(id)").toUInt();
}

void database::addScientist(QString name, bool gender, int yob, int yod){
    QSqlQuery query;
    query.prepare("INSERT INTO scientists (name, gender, yob, yod) VALUES (:name, :gender, :yob, :yod)");
    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":yob", yob);
    query.bindValue(":yod", yod);
    query.exec();
}

void database::returnScientist(unsigned int val, scientist &cs){
    QSqlQuery query;
    query.prepare("SELECT * FROM scientists WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    unsigned int id = query.value("id").toUInt();
    string name = query.value("name").toString().toStdString();
    bool gender = query.value("gender").toBool();
    int yob = query.value("yob").toInt();
    int yod = query.value("yod").toInt();
    scientist temp(id, name, gender, yob, yod);
    cs = temp;
}

void database::returnScientists(vector<scientist> &cs){
    QSqlQuery query;
    query.exec("SELECT * FROM scientists");
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        bool gender = query.value("gender").toBool();
        int yob = query.value("yob").toInt();
        int yod = query.value("yod").toInt();
        scientist temp(id, name, gender, yob, yod);
        cs.push_back(temp);
    }
}

void database::sortCSname(bool &namesort, vector<int> &cs){
    QSqlQuery query;
    if(namesort)
        query.exec("SELECT id FROM scientists ORDER BY name DESC");
    else
        query.exec("SELECT id FROM scientists ORDER BY name");
    while(query.next()){
        int id = query.value("id").toUInt();
        cs.push_back(id);
    }
}

void database::sortCSgender(bool &gendersort, vector<int> &cs){
    QSqlQuery query;
    if(gendersort)
        query.exec("SELECT id FROM scientists ORDER BY gender DESC");
    else
        query.exec("SELECT id FROM scientists ORDER BY gender");
    while(query.next()){
        int id = query.value("id").toUInt();
        cs.push_back(id);
    }
}

void database::sortCSyob(bool &yobsort, vector<int> &cs){
    QSqlQuery query;
    if(yobsort)
        query.exec("SELECT id FROM scientists ORDER BY yob DESC");
    else
        query.exec("SELECT id FROM scientists ORDER BY yob");
    while(query.next()){
        int id = query.value("id").toUInt();
        cs.push_back(id);
    }
}

void database::searchCSname(QString name, vector<int> &id){
    QSqlQuery query;
    query.prepare("SELECT id FROM scientists WHERE name LIKE :name");
    query.bindValue(":name", name);
    query.exec();
    while(query.next()){
        int store = query.value("id").toInt();
        id.push_back(store);
    }
}

void database::searchCSgender(bool gender, vector<int> &id){
    QSqlQuery query;
    query.prepare("SELECT id FROM scientists WHERE gender = :gender");
    query.bindValue(":gender", gender);
    query.exec();
    while(query.next()){
        int store = query.value("id").toInt();
        id.push_back(store);
    }
}

void database::searchCSyob(int yob, vector<int> &id){
    QSqlQuery query;
    query.prepare("SELECT id FROM scientists WHERE yob = :yob");
    query.bindValue(":yob", yob);
    query.exec();
    while(query.next()){
        int store = query.value("id").toInt();
        id.push_back(store);
    }
}

void database::searchCSyod(int yod, vector<int> &id){
    QSqlQuery query;
    query.prepare("SELECT id FROM scientists WHERE yod = :yod");
    query.bindValue(":yod", yod);
    query.exec();
    while(query.next()){
        int store = query.value("id").toInt();
        id.push_back(store);
    }
}

void database::addComputer(QString name, int year, QString type, bool built){
    QSqlQuery query;
    query.prepare("INSERT INTO computers (name, year, type, built) VALUES (:name, :year, :type, :built)");
    query.bindValue(":name", name);
    query.bindValue(":year", year);
    query.bindValue(":type", type);
    query.bindValue(":built", built);
    query.exec();
}

void database::returnComputer(unsigned int val, computer &c){
    QSqlQuery query;
    query.prepare("SELECT * FROM computers WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    unsigned int id = query.value("id").toUInt();
    string name = query.value("name").toString().toStdString();
    int year = query.value("year").toInt();
    string type = query.value("type").toString().toStdString();
    bool built = query.value("built").toBool();
    computer temp(id, name, year, type, built);
    c = temp;
}

void database::returnComputers(vector<computer> &c){
    QSqlQuery query;
    query.exec("SELECT * FROM computers");
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int year = query.value("year").toInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
        computer temp(id, name, year, type, built);
        c.push_back(temp);
    }
}

void database::sortCname(bool &namesort, vector<int> &c){
    QSqlQuery query;
    if(namesort){
        query.exec("SELECT id FROM computers ORDER BY name DESC");
    }
    else{
        query.exec("SELECT id FROM computers ORDER BY name");
    }
    while(query.next()){
        int id = query.value("id").toUInt();
        c.push_back(id);
    }
}

void database::sortCyear(bool &yearsort, vector<int> &c){
    QSqlQuery query;
    if(yearsort){
        query.exec("SELECT id FROM computers ORDER BY year DESC");
    }
    else{
        query.exec("SELECT id FROM computers ORDER BY year");
    }
    while(query.next()){
        int id = query.value("id").toUInt();
        c.push_back(id);
    }
}

void database::sortCtype(bool &typesort, vector<int> &c){
    QSqlQuery query;
    if(typesort){
        query.exec("SELECT id FROM computers ORDER BY type DESC");
    }
    else{
        query.exec("SELECT id FROM computers ORDER BY type");
    }
    while(query.next()){
        int id = query.value("id").toUInt();
        c.push_back(id);
    }
}

void database::sortCbuilt(bool &builtsort, vector<int> &c){
    QSqlQuery query;
    if(builtsort){
        query.exec("SELECT id FROM computers ORDER BY built DESC");
    }
    else{
        query.exec("SELECT id FROM computers ORDER BY built");
    }
    while(query.next()){
        int id = query.value("id").toUInt();
        c.push_back(id);
    }
}

void database::searchCname(QString name, vector<int> &id){
    QSqlQuery query;
    query.prepare("SELECT id FROM computers WHERE name LIKE :name");
    query.bindValue(":name", name);
    query.exec();
    while(query.next()){
        int store = query.value("id").toInt();
        id.push_back(store);
    }
}

void database::searchCyear(int year, vector<int> &id){
    QSqlQuery query;
    query.prepare("SELECT id FROM computers WHERE year = :year");
    query.bindValue(":year", year);
    query.exec();
    while(query.next()){
        int store = query.value("id").toInt();
        id.push_back(store);
    }
}

void database::searchCtype(QString type, vector<int> &id){
    QSqlQuery query;
    query.prepare("SELECT id FROM computers WHERE type LIKE :type");
    query.bindValue(":type", type);
    query.exec();
    while(query.next()){
        int store = query.value("id").toInt();
        id.push_back(store);
    }
}

void database::searchCbuilt(bool built, vector<int> &id){
    QSqlQuery query;
    query.prepare("SELECT id FROM computers WHERE built = :built");
    query.bindValue(":built", built);
    query.exec();
    while(query.next()){
        int store = query.value("id").toInt();
        id.push_back(store);
    }
}

void database::addLink(int csid, int cid){
    QSqlQuery query;
    query.prepare("INSERT INTO link (csid, cid) VALUES (:csid, :cid)");
    query.bindValue(":csid", csid);
    query.bindValue(":cid", cid);
    query.exec();
}

bool database::isLink(int csid, int cid){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM link WHERE csid = :csid AND cid = :cid");
    query.bindValue(":csid", csid);
    query.bindValue(":cid", cid);
    query.exec();
    query.next();
    unsigned int count = query.value("COUNT(*)").toUInt();
    if(count != 0)
        return true;
    return false;
}

void database::updateCSname(unsigned int val, QString name){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET name = :name WHERE id = :id");
    query.bindValue(":name", name);
    query.bindValue(":id", val);
    query.exec();
}

bool database::returnCSgender(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT gender FROM scientists WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    return query.value("gender").toBool();
}

void database::updateCSgender(unsigned int val, bool gender){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET gender = :gender WHERE id = :id");
    query.bindValue(":gender", gender);
    query.bindValue(":id", val);
    query.exec();
}

int database::returnCSyob(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT yob FROM scientists WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    return query.value("yob").toInt();
}

void database::updateCSyob(unsigned int val, int yob){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET yob = :yob WHERE id = :id");
    query.bindValue(":yob", yob);
    query.bindValue(":id", val);
    query.exec();
}

void database::updateCSyod(unsigned int val, int yod){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET yod = :yod WHERE id = :id");
    query.bindValue(":yod", yod);
    query.bindValue(":id", val);
    query.exec();
}

void database::updateCname(unsigned int val, QString name){
    QSqlQuery query;
    query.prepare("UPDATE computers SET name = :name WHERE id = :id");
    query.bindValue(":name", name);
    query.bindValue(":id", val);
    query.exec();
}

void database::updateCyear(unsigned int val, int year){
    QSqlQuery query;
    query.prepare("UPDATE computers SET year = :year WHERE id = :id");
    query.bindValue(":year", year);
    query.bindValue(":id", val);
    query.exec();
}

void database::updateCtype(unsigned int val, QString type){
    QSqlQuery query;
    query.prepare("UPDATE computers SET type = :type WHERE id = :id");
    query.bindValue(":type", type);
    query.bindValue(":id", val);
    query.exec();
}

bool database::returnCbuilt(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT built FROM computers WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    return query.value("built").toBool();
}

void database::updateCbuilt(unsigned int val, bool built){
    QSqlQuery query;
    query.prepare("UPDATE computers SET built = :built WHERE id = :id");
    query.bindValue(":built", built);
    query.bindValue(":id", val);
    query.exec();
}

unsigned int database::maxCSid(){
    QSqlQuery query;
    query.exec("SELECT MAX(id) FROM scientists");
    query.next();
    return query.value("MAX(id)").toUInt();
}

void database::getCSid(string &csname, unsigned int &csid, unsigned int step){
    QSqlQuery query;
    query.exec("SELECT id, name FROM scientists");
    for(unsigned int i = 0; i < step; i++){
        query.next();
    }
    csname = query.value("name").toString().toStdString();
    csid = query.value("id").toUInt();
}

unsigned int database::getCIDcount(unsigned int csid){
    QSqlQuery query;
    query.prepare("SELECT COUNT(cid) FROM link WHERE csid = :id");
    query.bindValue(":id", csid);
    query.exec();
    query.next();
    return query.value("COUNT(cid)").toUInt();
}

void database::getCidFromCSid(unsigned int csid, unsigned int &cid, unsigned int step){
    QSqlQuery query;
    query.prepare("SELECT cid FROM link WHERE csid = :id");
    query.bindValue(":id", csid);
    query.exec();
    for(unsigned int i = 0; i < step; i++){
        query.next();
    }
    cid = query.value("cid").toUInt();
}

void database::getCnameFromCid(unsigned int cid, string &cname){
    QSqlQuery query;
    query.prepare("SELECT name FROM computers WHERE id = :id");
    query.bindValue(":id", cid);
    query.exec();
    query.next();
    cname = query.value("name").toString().toStdString();
}

unsigned int database::maxCid(){
    QSqlQuery query;
    query.exec("SELECT MAX(id) FROM computers");
    query.next();
    return query.value("MAX(id)").toUInt();
}
