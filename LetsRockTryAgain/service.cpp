#include "service.h"

void service::start(){
    db.start();
}

QSqlQuery service::returnCSquery(){
    return db.returnCSquery();
}

QSqlQuery service::returnCquery(){
    return db.returnCquery();
}
