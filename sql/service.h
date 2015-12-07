#ifndef SERVICE_H
#define SERVICE_H
#include "database.h"

class service{
public:
    void addScientist();
    bool editScientist(unsigned int val);
    int legalBirth();
    int legalDeath(int yob);
    bool legalGender();
    void addComputer();
    bool editComputer(unsigned int val);
    int legalYear();
    bool legalBuilt();
    unsigned int selectUnit(string s);
    bool isLetter(string s);
    bool checkName(QString &name);
    void multiSearch(QString &s);
    bool searchScientist(vector<int> &id);
    bool searchComputer(vector<int> &id);
};

#endif // SERVICE_H
