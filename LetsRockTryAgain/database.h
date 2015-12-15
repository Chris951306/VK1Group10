#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include "computer.h"
#include "link.h"
#include <iostream>
#include <QtSql>
#include <vector>

class database{
public:
    void start();
    void addScientist(scientist s);
    void editScientist(scientist s);
    void addComputer(computer c);
    void editComputer(computer c);
    void addLink(int csid, int cid);
    void getAllScientists(std::vector<scientist>& scientists);
    void getAllComputers(std::vector<computer>& computers);
    void getAllLinks(std::vector<link>& links);
    void searchScientist(std::vector<scientist>& scientists, QString string);
    void searchComputer(std::vector<computer>& computers, QString string);
    bool isLink(int csid, int cid);
    void deleteScientist(int id);
    void deleteComputer(int id);
    void deleteLink(int csid, int cid);
    QString getCSName(int csid);
    QString getCName(int cid);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
