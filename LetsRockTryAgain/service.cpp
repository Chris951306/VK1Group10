#include "service.h"

void service::start(){
    db.start();
}

void service::addScientist(scientist s){
    db.addScientist(s);
}

void service::editScientist(scientist s){
    db.editScientist(s);
}

void service::addComputer(computer c){
    db.addComputer(c);
}

void service::editComputer(computer c){
    db.editComputer(c);
}

void service::addLink(int csid, int cid){
    db.addLink(csid, cid);
}

void service::editLink(int newCSID, int newCID, int csid, int cid){
    db.editLink(newCSID, newCID, csid, cid);
}

void service::getAllScientists(std::vector<scientist>& scientists){
    db.getAllScientists(scientists);
}

void service::getAllComputers(std::vector<computer>& computers){
    db.getAllComputers(computers);
}

void service::getAllLinks(std::vector<link> &links){
    db.getAllLinks(links);
}

void service::searchScientist(std::vector<scientist>& scientists, QString string){
    db.searchScientist(scientists, string);
}

void service::searchComputer(std::vector<computer>& computers, QString string){
    db.searchComputer(computers, string);
}

bool service::isLink(int csid, int cid){
    return db.isLink(csid, cid);
}

void service::deleteScientist(int id){
    db.deleteScientist(id);
}

void service::deleteComputer(int id){
    db.deleteComputer(id);
}

void service::deleteLink(int csid, int cid){
    db.deleteLink(csid, cid);
}

QString service::getCSName(int csid){
    return db.getCSName(csid);
}

QString service::getCName(int cid){
    return db.getCName(cid);
}
