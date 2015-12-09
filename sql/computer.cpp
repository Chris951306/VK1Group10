#include "computer.h"

computer::computer(unsigned int a, string b, int c, string d, bool e){
    id = a;
    name = b;
    year = c;
    type = d;
    built = e;
}

unsigned int computer::returnId(){
    return id;
}

string computer::returnName(){
    return name;
}

int computer::returnYear(){
    return year;
}

string computer::returnType(){
    return type;
}

bool computer::returnBuilt(){
    return built;
}
