#include "service.h"

unsigned int service::returnCScount(){
    database db;
    return db.returnCScount();
}

unsigned int service::returnCcount(){
    database db;
    return db.returnCcount();
}

void service::addScientist(QString name, bool gender, int yob, int yod){
    database db;
    db.addScientist(name, gender, yob, yod);
}

void service::returnScientist(unsigned int val, scientist &cs){
    database db;
    db.returnScientist(val, cs);
}

void service::returnScientists(vector<scientist> &cs){
    database db;
    db.returnScientists(cs);
}

void service::sortCSname(bool &namesort, vector<int> &cs){
    database db;
    db.sortCSname(namesort, cs);
}

void service::sortCSgender(bool &gendersort, vector<int> &cs){
    database db;
    db.sortCSgender(gendersort, cs);
}

void service::sortCSyob(bool &yobsort, vector<int> &cs){
    database db;
    db.sortCSyob(yobsort, cs);
}

void service::searchCSname(QString name, vector<int> &id){
    database db;
    db.searchCSname(name, id);
}

void service::searchCSgender(bool gender, vector<int> &id){
    database db;
    db.searchCSgender(gender, id);
}

void service::searchCSyob(int yob, vector<int> &id){
    database db;
    db.searchCSyob(yob, id);
}

void service::searchCSyod(int yod, vector<int> &id){
    database db;
    db.searchCSyod(yod, id);
}

void service::addComputer(QString name, int year, QString type, bool built){
    database db;
    db.addComputer(name, year, type, built);
}

void service::returnComputer(unsigned int val, computer &c){
    database db;
    db.returnComputer(val, c);
}

void service::returnComputers(vector<computer> &c){
    database db;
    db.returnComputers(c);
}

void service::sortCname(bool &namesort, vector<int> &c){
    database db;
    db.sortCname(namesort, c);
}

void service::sortCyear(bool &yearsort, vector<int> &c){
    database db;
    db.sortCyear(yearsort, c);
}

void service::sortCtype(bool &typesort, vector<int> &c){
    database db;
    db.sortCtype(typesort, c);
}

void service::sortCbuilt(bool &builtsort, vector<int> &c){
    database db;
    db.sortCbuilt(builtsort, c);
}

void service::searchCname(QString name, vector<int> &id){
    database db;
    db.searchCname(name, id);
}

void service::searchCyear(int year, vector<int> &id){
    database db;
    db.searchCyear(year, id);
}

void service::searchCtype(QString type, vector<int> &id){
    database db;
    db.searchCtype(type, id);
}

void service::searchCbuilt(bool built, vector<int> &id){
    database db;
    db.searchCbuilt(built, id);
}

void service::addLink(int csid, int cid){
    database db;
    db.addLink(csid, cid);
}

bool service::isLink(int csid, int cid){
    database db;
    return db.isLink(csid, cid);
}

void service::updateCSname(unsigned int val, QString name){
    database db;
    db.updateCSname(val, name);
}

bool service::returnCSgender(unsigned int val){
    database db;
    return db.returnCSgender(val);
}

void service::updateCSgender(unsigned int val, bool gender){
    database db;
    db.updateCSgender(val, gender);
}

void service::updateCSyob(unsigned int val, int yob){
    database db;
    db.updateCSyob(val, yob);
}

int service::returnCSyob(unsigned int val){
    database db;
    return db.returnCSyob(val);
}

void service::updateCSyod(unsigned int val, int yod){
    database db;
    db.updateCSyod(val, yod);
}

void service::updateCname(unsigned int val, QString name){
    database db;
    db.updateCname(val, name);
}

void service::updateCyear(unsigned int val, int year){
    database db;
    db.updateCyear(val, year);
}

void service::updateCtype(unsigned int val, QString type){
    database db;
    db.updateCtype(val, type);
}

bool service::returnCbuilt(unsigned int val){
    database db;
    return db.returnCbuilt(val);
}

void service::updateCbuilt(unsigned int val, bool built){
    database db;
    db.updateCbuilt(val, built);
}

unsigned int service::maxCSid(){
    database db;
    return db.maxCSid();
}

void service::getCSid(string &csname, unsigned int &csid, unsigned int step){
    database db;
    db.getCSid(csname, csid, step);
}

unsigned int service::getCIDcount(unsigned int csid){
    database db;
    return db.getCIDcount(csid);
}

void service::getCidFromCSid(unsigned int csid, unsigned int &cid, unsigned int step){
    database db;
    db.getCidFromCSid(csid, cid, step);
}

void service::getCnameFromCid(unsigned int cid, string &cname){
    database db;
    db.getCnameFromCid(cid, cname);
}

unsigned int service::maxCid(){
    database db;
    return db.maxCid();
}
