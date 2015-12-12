#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <QtSql>

class database{
public:
    void start();
    QSqlQuery returnCSquery();
    QSqlQuery returnCquery();
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
