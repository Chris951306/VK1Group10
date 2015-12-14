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

int service::countScientists(){
    return db.countScientists();
}

int service::countComputers(){
    return db.countComputers();
}

void service::deleteLink(int csid, int cid){
    db.deleteLink(csid, cid);
}
