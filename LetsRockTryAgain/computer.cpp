#include "computer.h"

computer::computer(int i, QString a, QString b, QString c, QString d){
    id = i;
    name = a;
    year = b;
    type = c;
    built = d;
}

int computer::getId(){
    return id;
}

QString computer::getName(){
    return name;
}

QString computer::getYear(){
    return year;
}

QString computer::getType(){
    return type;
}

QString computer::getBuilt(){
    return built;
}
