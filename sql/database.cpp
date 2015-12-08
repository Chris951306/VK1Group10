#include "database.h"

database::database(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
}

void database::onoff(){
    if(db.isOpen())// Checks if the database is open or not
        db.close();// If open, then close
    else
        db.open();// If not open, open
}

bool database::status(){
    if(db.isOpen())// Checks if the database is open or not
        return true;
    return false;
}
