#include "scientist.h"

scientist::scientist(unsigned int a, string b, bool c, int d, int e){
    id = a;
    name = b;
    gender = c;
    yob = d;
    yod = e;
}

unsigned int scientist::returnId(){
    return id;
}

string scientist::returnName(){
    return name;
}

bool scientist::returnGender(){
    return gender;
}

int scientist::returnYob(){
    return yob;
}

int scientist::returnYod(){
    return yod;
}
