#include "computers.h"

computers::computers(unsigned int id, string a, int b, string c, bool d){
    c_id = id;
    c_name = a;
    c_year = b;
    c_type = c;
    c_built = d;
}

unsigned int computers::returnId(){
    return c_id;
}

string computers::returnName(){
    return c_name;
}

int computers::returnYear(){
    return c_year;
}

string computers::returnType(){
    return c_type;
}

bool computers::returnBuilt(){
    return c_built;
}
