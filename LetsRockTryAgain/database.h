#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <QtSql>

class database{
public:
    void start();
    QSqlQuery returnCSquery();
    QSqlQuery returnCquery();
    void addScientist(QString name, QString gender, QString yob, QString yod);
    void addComputer(QString name, QString year, QString type, QString build);
private:
    QSqlDatabase db;

};

#endif // DATABASE_H
