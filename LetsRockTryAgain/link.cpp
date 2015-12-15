#include "link.h"

//Default constructor for class
link::link(int a, int b){
    csid = a;
    cid = b;
}

//Returns current scientist id
int link::returnCSID(){
    return csid;
}

//Returns current computer id
int link::returnCID(){
    return cid;
}
