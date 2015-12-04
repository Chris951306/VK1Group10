#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <QtSql>
#include <string>
#include <vector>
#include <iomanip>

const int StillAlive = 3000;

using namespace std;

class database{
public:
    database();
    void onoff();
    bool status();
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
