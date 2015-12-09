#include "database.h"

// Connects the SQL Database and opens the connection
void database::start(){
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
    db.open();
}

// Returns the amount of scientist entries
unsigned int database::returnCScount(){
    QSqlQuery query;
    query.exec("SELECT COUNT(id) FROM scientists");
    query.next();
    return query.value("COUNT(id)").toUInt();
}

// Returns the amount of compute entries
unsigned int database::returnCcount(){
    QSqlQuery query;
    query.exec("SELECT COUNT(id) FROM computers");
    query.next();
    return query.value("COUNT(id)").toUInt();
}

// Adds a scientist to SQL server
void database::addScientist(QString name, bool gender, int yob, int yod){
    QSqlQuery query;
    query.prepare("INSERT INTO scientists (name, gender, yob, yod) VALUES (:name, :gender, :yob, :yod)");
    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":yob", yob);
    query.bindValue(":yod", yod);
    query.exec();
}

// Returns a scientist based on index 'val'
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

// Stores all scientist ids in a vector
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

// Sorts by name in direction determined by parsed bool
void database::sortCSname(bool &namesort, vector<int> &cs){
    QSqlQuery query;
    if(namesort){
        query.exec("SELECT id FROM scientists ORDER BY name DESC");
    }
    else{
        query.exec("SELECT id FROM scientists ORDER BY name");
    }
    while(query.next()){
        int id = query.value("id").toUInt();
        cs.push_back(id);
    }
}

// Sorts by gender in direction determinded by parsed bool
void database::sortCSgender(bool &gendersort, vector<int> &cs){
    QSqlQuery query;
    if(gendersort){
        query.exec("SELECT id FROM scientists ORDER BY gender DESC");
    }
    else{
        query.exec("SELECT id FROM scientists ORDER BY gender");
    }
    while(query.next()){
        int id = query.value("id").toUInt();
        cs.push_back(id);
    }
}

// Sorts by year of birth in direction determined by parsed bool
void database::sortCSyob(bool &yobsort, vector<int> &cs){
    QSqlQuery query;
    if(yobsort){
        query.exec("SELECT id FROM scientists ORDER BY yob DESC");
    }
    else{
        query.exec("SELECT id FROM scientists ORDER BY yob");
    }
    while(query.next()){
        int id = query.value("id").toUInt();
        cs.push_back(id);
    }
}

// Searches for name based on a QString
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

// Searches for gender based on a bool
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

// Seaches for a year of birth
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

// Searches for a year of death
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

// Adds a computer to SQL server
void database::addComputer(QString name, int year, QString type, bool built){
    QSqlQuery query;
    query.prepare("INSERT INTO computers (name, year, type, built) VALUES (:name, :year, :type, :built)");
    query.bindValue(":name", name);
    query.bindValue(":year", year);
    query.bindValue(":type", type);
    query.bindValue(":built", built);
    query.exec();
}

// Returns a computer based on index 'val'
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

// Stores all comoyter ids in a vector
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

// Sorts by name in direction determined by parsed bool
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

// Sorts by year in direction determined by parsed bool
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

// Sorts by type in direction determined by parsed bool
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

// Sorts by build status in direction determined by parsed bool
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

// Searches for name based on a QString
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

// Searches for a year
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

// Searches for type based on a QString
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

// Searches for a built status
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

// Returns the MAX(rowid) from link
unsigned int database::maxLid(){
    QSqlQuery query;
    query.exec("SELECT MAX(rowid) FROM link");
    query.next();
    return query.value("MAX(rowid)").toUInt();
}

// Adds a link to SQL server
void database::addLink(int csid, int cid){
    QSqlQuery query;
    query.prepare("INSERT INTO link (csid, cid) VALUES (:csid, :cid)");
    query.bindValue(":csid", csid);
    query.bindValue(":cid", cid);
    query.exec();
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

// Returns a link based on inder 'val'
void database::returnLink(unsigned int val, link &l){
    QSqlQuery query;
    query.prepare("SELECT * FROM link WHERE rowid = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    int a = query.value("csid").toInt();
    int b = query.value("cid").toInt();
    link temp(a, b);
    l = temp;
}

// Stores all rowids from link in vector
void database::returnLinks(vector<int> &l){
    QSqlQuery query;
    query.exec("SELECT rowid FROM link");
    while(query.next()){
        int store = query.value("rowid").toInt();
        l.push_back(store);
    }
}

// Updates the scientist id at rowid = val
void database::updateCSlink(unsigned int val, unsigned int csid){
    QSqlQuery query;
    query.prepare("UPDATE link SET csid = :csid WHERE rowid = :id");
    query.bindValue(":csid", csid);
    query.bindValue(":id", val);
    query.exec();
}

// Updates the computer id at rowid = val
void database::updateClink(unsigned int val, unsigned int cid){
    QSqlQuery query;
    query.prepare("UPDATE link SET cid = :cid WHERE rowid = :id");
    query.bindValue(":cid", cid);
    query.bindValue(":id", val);
    query.exec();
}

// Updates scientist name at id = val
void database::updateCSname(unsigned int val, QString name){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET name = :name WHERE id = :id");
    query.bindValue(":name", name);
    query.bindValue(":id", val);
    query.exec();
}

// Returns the current gender of scientist at id = val
bool database::returnCSgender(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT gender FROM scientists WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    return query.value("gender").toBool();
}

// Updates scientist gender at id = val
void database::updateCSgender(unsigned int val, bool gender){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET gender = :gender WHERE id = :id");
    query.bindValue(":gender", gender);
    query.bindValue(":id", val);
    query.exec();
}

// Return the current year of birth of scientist at id = val
int database::returnCSyob(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT yob FROM scientists WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    return query.value("yob").toInt();
}

// Updates scientist year of birth at id = val
void database::updateCSyob(unsigned int val, int yob){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET yob = :yob WHERE id = :id");
    query.bindValue(":yob", yob);
    query.bindValue(":id", val);
    query.exec();
}

// Updates scientist year of death at id = val
void database::updateCSyod(unsigned int val, int yod){
    QSqlQuery query;
    query.prepare("UPDATE scientists SET yod = :yod WHERE id = :id");
    query.bindValue(":yod", yod);
    query.bindValue(":id", val);
    query.exec();
}

// Updates computer name at id = val
void database::updateCname(unsigned int val, QString name){
    QSqlQuery query;
    query.prepare("UPDATE computers SET name = :name WHERE id = :id");
    query.bindValue(":name", name);
    query.bindValue(":id", val);
    query.exec();
}

// Updates the computer build year at id = val
void database::updateCyear(unsigned int val, int year){
    QSqlQuery query;
    query.prepare("UPDATE computers SET year = :year WHERE id = :id");
    query.bindValue(":year", year);
    query.bindValue(":id", val);
    query.exec();
}

// Updates the computer type at id = val
void database::updateCtype(unsigned int val, QString type){
    QSqlQuery query;
    query.prepare("UPDATE computers SET type = :type WHERE id = :id");
    query.bindValue(":type", type);
    query.bindValue(":id", val);
    query.exec();
}

// Returns current build status of computer at id = val
bool database::returnCbuilt(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT built FROM computers WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    query.next();
    return query.value("built").toBool();
}

// Updates computer build status at id = val
void database::updateCbuilt(unsigned int val, bool built){
    QSqlQuery query;
    query.prepare("UPDATE computers SET built = :built WHERE id = :id");
    query.bindValue(":built", built);
    query.bindValue(":id", val);
    query.exec();
}

// Returns the MAX(id) from scientists
unsigned int database::maxCSid(){
    QSqlQuery query;
    query.exec("SELECT MAX(id) FROM scientists");
    query.next();
    return query.value("MAX(id)").toUInt();
}

// Gets the name and id of a scientist at position = step
void database::getCSid(string &csname, unsigned int &csid, unsigned int step){
    QSqlQuery query;
    query.exec("SELECT id, name FROM scientists");
    for(unsigned int i = 0; i < step; i++){
        query.next();
    }
    csname = query.value("name").toString().toStdString();
    csid = query.value("id").toUInt();
}

// Returns the COUNT(cid) from link
unsigned int database::getCIDcount(unsigned int csid){
    QSqlQuery query;
    query.prepare("SELECT COUNT(cid) FROM link WHERE csid = :id");
    query.bindValue(":id", csid);
    query.exec();
    query.next();
    return query.value("COUNT(cid)").toUInt();
}

// Gets the cid from link
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

// Gets computer name from cid
void database::getCnameFromCid(unsigned int cid, string &cname){
    QSqlQuery query;
    query.prepare("SELECT name FROM computers WHERE id = :id");
    query.bindValue(":id", cid);
    query.exec();
    query.next();
    cname = query.value("name").toString().toStdString();
}

// Returns the MAX(id) from computers
unsigned int database::maxCid(){
    QSqlQuery query;
    query.exec("SELECT MAX(id) FROM computers");
    query.next();
    return query.value("MAX(id)").toUInt();
}

// Gets the name and id of a computer at position = step
void database::getCid(string &cname, unsigned int &cid, unsigned int step){
    QSqlQuery query;
    query.exec("SELECT id, name FROM computers");
    for(unsigned int i = 0; i < step; i++){
        query.next();
    }
    cname = query.value("name").toString().toStdString();
    cid = query.value("id").toUInt();
}

// Returns the COUNT(csid) from link
unsigned int database::getCSIDcount(unsigned int cid){
    QSqlQuery query;
    query.prepare("SELECT COUNT(csid) FROM link WHERE cid = :id");
    query.bindValue(":id", cid);
    query.exec();
    query.next();
    return query.value("COUNT(csid)").toUInt();
}

// Gets the csid from link
void database::getCSidFromCid(unsigned int cid, unsigned int &csid, unsigned int step){
    QSqlQuery query;
    query.prepare("SELECT csid FROM link WHERE cid = :id");
    query.bindValue(":id", cid);
    query.exec();
    for(unsigned int i = 0; i < step; i++){
        query.next();
    }
    csid = query.value("csid").toUInt();
}

// Gets scientist name from csid
void database::getCSnameFromCSid(unsigned int csid, string &csname){
    QSqlQuery query;
    query.prepare("SELECT name FROM scientists WHERE id = :id");
    query.bindValue(":id", csid);
    query.exec();
    query.next();
    csname = query.value("name").toString().toStdString();
}
