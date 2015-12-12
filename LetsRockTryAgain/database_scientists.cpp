#include "database_scientists.h"

void database_scientists::start(){
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
    db.open();
}
