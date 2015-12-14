#include "link.h"

link::link(int a, int b){
    csid = a;
    cid = b;
}

int link::returnCSID(){
    return csid;
}

int link::returnCID(){
    return cid;
}
