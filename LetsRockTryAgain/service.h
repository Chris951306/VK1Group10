#ifndef SERVICE_H
#define SERVICE_H
#include "database.h"
#include <iostream>

class service
{
public:
    void start();
    QSqlQuery returnCSquery();
    QSqlQuery returnCquery();
    void addScientist(QString name, QString gender, QString yob, QString yod);
    void addComputer(QString name, QString year, QString type, QString build);
private:
    database db;
};

#endif // SERVICE_H
