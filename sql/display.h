#ifndef DISPLAY_H
#define DISPLAY_H
#include "service.h"

class display{
public:
    void printCStop();
    void printCSbot();
    void printCtop();
    void printCbot();
    void addScientist();
    bool editScientist(unsigned int val);
    void printScientists();
    void printScientist(unsigned int val);
    bool sortScientists(bool &namesort, bool &gendersort, bool& yobsort);
    bool searchScientists(vector<int> &id);
    int legalBirth();
    int legalDeath(int yob);
    bool legalGender();
    bool checkName(QString &name);
    void addComputer();
    bool editComputer(unsigned int val);
    void printComputer(unsigned int val);
    void printComputers();
    bool sortComputers(bool &namesort, bool &yearsort, bool &typesort, bool &builtsort);
    bool searchComputers(vector<int> &id);
    int legalYear();
    bool legalBuilt();
    void addLink(int csid, int cid);
    unsigned int selectUnit(string s);
    bool isLetter(string s);
    void multiSearch(QString &s);
    void printCStoC();
    void printCtoCS();
};

#endif // DISPLAY_H
