#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <QtSql>
#include <string>
#include <vector>
#include <iomanip>

const int STILLALIVE = 3000;
const int MINYEAR = -1000;
const int MAXYEAR = 2015;

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
