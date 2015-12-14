#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include "computer.h"
#include <iostream>
#include <QtSql>
#include <vector>

class database{
public:
    void start();
    void addScientist(scientist s);
    void addComputer(computer c);
    void getAllScientists(std::vector<scientist>& scientists);
    void getAllComputers(std::vector<computer>& computers);
    void searchScientist(std::vector<scientist>& scientists, QString string);
    void searchComputer(std::vector<computer>& computers, QString string);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
