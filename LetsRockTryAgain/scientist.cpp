#include "scientist.h"

scientist::scientist(int i, QString a, QString b, QString c, QString d){
    id = i;
    name = a;
    gender = b;
    yob = c;
    yod = d;
}

int scientist::getId(){
    return id;
}

QString scientist::getName(){
    return name;
}

QString scientist::getGender(){
    return gender;
}

QString scientist::getYob(){
    return yob;
}

QString scientist::getYod(){
    return yod;
}
