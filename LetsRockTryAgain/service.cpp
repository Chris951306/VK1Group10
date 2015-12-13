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
