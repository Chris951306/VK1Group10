#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include "computer.h"
#include "link.h"
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
    void start(); // Connects the SQL Database and opens the connection
    unsigned int returnCScount(); // Returns the amount of scientist entries
    unsigned int returnCcount(); // Returns the amount of compute entries
    void addScientist(QString name, bool gender, int yob, int yod); // Adds a scientist to SQL server
    void returnScientist(unsigned int val, scientist &cs); // Returns a scientist based on index 'val'
    void returnScientists(vector<scientist> &cs); // Stores all scientist ids in a vector
    void sortCSname(bool &namesort, vector<int> &cs); // Sorts by name in direction determined by parsed bool
    void sortCSgender(bool &gendersort, vector<int> &cs); // Sorts by gender in direction determinded by parsed bool
    void sortCSyob(bool &yobsort, vector<int> &cs); // Sorts by year of birth in direction determined by parsed bool
    void searchCSname(QString name, vector<int> &id); // Searches for name based on a QString
    void searchCSgender(bool gender, vector<int> &id); // Searches for gender based on a bool
    void searchCSyob(int yob, vector<int> &id); // Seaches for a year of birth
    void searchCSyod(int yod, vector<int> &id); // Searches for a year of death
    void addComputer(QString name, int year, QString type, bool built); // Adds a computer to SQL server
    void returnComputer(unsigned int val, computer &c); // Returns a computer based on index 'val'
    void returnComputers(vector<computer> &c); // Stores all comoyter ids in a vector
    void sortCname(bool &namesort, vector<int> &c); // Sorts by name in direction determined by parsed bool
    void sortCyear(bool &yearsort, vector<int> &c); // Sorts by year in direction determined by parsed bool
    void sortCtype(bool &typesort, vector<int> &c); // Sorts by type in direction determined by parsed bool
    void sortCbuilt(bool &builtsort, vector<int> &c); // Sorts by build status in direction determined by parsed bool
    void searchCname(QString name, vector<int> &id); // Searches for name based on a QString
    void searchCyear(int year, vector<int> &id); // Searches for a year
    void searchCtype(QString type, vector<int> &id); // Searches for type based on a QString
    void searchCbuilt(bool built, vector<int> &id); // Searches for a built status
    unsigned int maxLid(); // Returns the MAX(rowid) from link
    void addLink(int csid, int cid); // Adds a link to SQL server
    bool isLink(int csid, int cid); // Returns true if link already exists
    void returnLink(unsigned int val, link &l); // Returns a link based on inder 'val'
    void returnLinks(vector<int> &l); // Stores all rowids from link in vector
    void updateCSlink(unsigned int val, unsigned int csid); // Updates the scientist id at rowid = val
    void updateClink(unsigned int val, unsigned int cid); // Updates the computer id at rowid = val
    void updateCSname(unsigned int val, QString name); // Updates scientist name at id = val
    bool returnCSgender(unsigned int val); // Returns the current gender of scientist at id = val
    void updateCSgender(unsigned int val, bool gender); // Updates scientist gender at id = val
    int returnCSyob(unsigned int val); // Return the current year of birth of scientist at id = val
    void updateCSyob(unsigned int val, int yob); // Updates scientist year of birth at id = val
    void updateCSyod(unsigned int val, int yod); // Updates scientist year of death at id = val
    void updateCname(unsigned int val, QString name); // Updates computer name at id = val
    void updateCyear(unsigned int val, int year); // Updates the computer build year at id = val
    void updateCtype(unsigned int val, QString type); // Updates the computer type at id = val
    bool returnCbuilt(unsigned int val); // Returns current build status of computer at id = val
    void updateCbuilt(unsigned int val, bool built); // Updates computer build status at id = val
    unsigned int maxCSid(); // Returns the MAX(id) from scientists
    void getCSid(string &csname, unsigned int &csid, unsigned int step); // Gets the name and id of a scientist at position = step
    unsigned int getCIDcount(unsigned int csid); // Returns the COUNT(cid) from link
    void getCidFromCSid(unsigned int csid, unsigned int &cid, unsigned int step); // Gets the cid from link
    void getCnameFromCid(unsigned int cid, string &cname); // Gets computer name from cid
    unsigned int maxCid(); // Returns the MAX(id) from computers
    void getCid(string &cname, unsigned int &cid, unsigned int step); // Gets the name and id of a computer at position = step
    unsigned int getCSIDcount(unsigned int cid); // Returns the COUNT(csid) from link
    void getCSidFromCid(unsigned int cid, unsigned int &csid, unsigned int step); // Gets the csid from link
    void getCSnameFromCSid(unsigned int csid, string &csname); // Gets scientist name from csid
};

#endif // DATABASE_H
