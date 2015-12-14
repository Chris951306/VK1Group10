#include "service.h"

void service::start(){
    db.start();
}

void service::addScientist(scientist s){
    db.addScientist(s);
}

void service::addComputer(computer c){
    db.addComputer(c);
}

void service::getAllScientists(std::vector<scientist>& scientists){
    db.getAllScientists(scientists);
}

void service::getAllComputers(std::vector<computer>& computers){
    db.getAllComputers(computers);
}

void service::searchScientist(std::vector<scientist> &scientists, QString string){
    db.searchScientist(scientists, string);
}

void service::searchComputer(std::vector<computer> &computers, QString string){
    db.searchComputer(computers, string);
}
