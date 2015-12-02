#ifndef SERVICE_H
#define SERVICE_H
#include "data.h"
#include "service.h"

class service
{
public:
    istream& readName(string &s);
    istream& readLine(ifstream &load, string &a);
    void printData(vector<data> &cs);
    void addData(vector<data> &cs);
    void editData(vector<data> &cs);
    int legalBirth();
    int legalDeath(int yob);
    bool legalGender();
    unsigned int selectData(string &s);
    bool isLetter(string &s);
    void saveData(vector<data> &cs);
    void loadData(vector<data> &cs);
    void deleteData(vector<data> &cs);
};

#endif // SERVICE_H
