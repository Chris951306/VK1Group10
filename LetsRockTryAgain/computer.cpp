#include "computer.h"

//Default constructor for class
computer::computer(int i, QString a, QString b, QString c, QString d){
    id = i;
    name = a;
    year = b;
    type = c;
    built = d;
}

//Returns the current id
int computer::getId(){
    return id;
}

//Returns the current name
QString computer::getName(){
    return name;
}

//Returns the current year
QString computer::getYear(){
    return year;
}

//Returns the current type
QString computer::getType(){
    return type;
}

//Returns the current built status
QString computer::getBuilt(){
    return built;
}
