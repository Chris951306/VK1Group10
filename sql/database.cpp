#include "database.h"

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
}

void database::onoff(){
    if(db.isOpen())
        db.close();
    else
        db.open();
}

bool database::status(){
    if(db.isOpen())
        return true;
    return false;
}
