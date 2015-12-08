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
    /*^Constants used to define if the scientist is still alive,
    and the minimum/maximum valid year a scientist can be born*/

using namespace std;

class database{
public:
    database();
        //^Default constructor which creates a QSqlDatabase based on the private variable
    void onoff();
        //^Function to open or close the current database
    bool status();
        //^Returns whether the database is open or not - was mainly used in the beginning
private:
    QSqlDatabase db;
        //^QSqlDatabase for default constructor
};

#endif // DATABASE_H
