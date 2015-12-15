#include "scientist.h"

//Default constructer for class
scientist::scientist(int i, QString a, QString b, QString c, QString d){
    id = i;
    name = a;
    gender = b;
    yob = c;
    yod = d;
}

//Returns current id
int scientist::getId(){
    return id;
}

//Returns current name
QString scientist::getName(){
    return name;
}

//Returns current gender
QString scientist::getGender(){
    return gender;
}

// Returns current birthyear
QString scientist::getYob(){
    return yob;
}

//Returns current deathyear
QString scientist::getYod(){
    return yod;
}
