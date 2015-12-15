#include "service.h"

//Call function that opens the database
void service::start(){
    db.start();
}

//Calls function addScientist from database
void service::addScientist(scientist s){
    db.addScientist(s);
}

//Calls function editScientist from database
void service::editScientist(scientist s){
    db.editScientist(s);
}

//Calls function addComputer from database
void service::addComputer(computer c){
    db.addComputer(c);
}

//Calls function editComputer from database
void service::editComputer(computer c){
    db.editComputer(c);
}

//Calls function addLink from database
void service::addLink(int csid, int cid){
    db.addLink(csid, cid);
}

//Calls function editLink from database
void service::editLink(int newCSID, int newCID, int csid, int cid){
    db.editLink(newCSID, newCID, csid, cid);
}

//Calls function getAllScientists from database
void service::getAllScientists(std::vector<scientist>& scientists){
    db.getAllScientists(scientists);
}

//Calls function getAllComputers from database
void service::getAllComputers(std::vector<computer>& computers){
    db.getAllComputers(computers);
}

//Calls function getAllLinks from database
void service::getAllLinks(std::vector<link> &links){
    db.getAllLinks(links);
}

//Calls function searchScientist from database
void service::searchScientist(std::vector<scientist>& scientists, QString string){
    db.searchScientist(scientists, string);
}

//Calls function searchComputer from database
void service::searchComputer(std::vector<computer>& computers, QString string){
    db.searchComputer(computers, string);
}

//Calls function isLink from database
bool service::isLink(int csid, int cid){
    return db.isLink(csid, cid);
}

//Calls function deleteScientist from database
void service::deleteScientist(int id){
    db.deleteScientist(id);
}

//Calls function deleteComputer from database
void service::deleteComputer(int id){
    db.deleteComputer(id);
}

//Calls function deleteLink from database
void service::deleteLink(int csid, int cid){
    db.deleteLink(csid, cid);
}

//Calls function getCSName from database
QString service::getCSName(int csid){
    return db.getCSName(csid);
}

//Calls function getCName from database
QString service::getCName(int cid){
    return db.getCName(cid);
}
