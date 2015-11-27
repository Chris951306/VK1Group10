#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class scientist
{
    public:
        scientist();
        unsigned int size();
        void readInfo();
        void editInfo();
        bool legalBirth(int yob);
        bool legalDeath(int yob, int yod);
        bool swapName(string name1, string name2);
        friend ostream& operator<<(ostream& stream, const scientist &s);
        friend string retName(scientist &s);
        friend void viewInfo(vector<scientist> &s);
        friend void saveInfo(vector<scientist> &s);
        friend void loadInfo(vector<scientist> &s);
        friend void delInfo(vector<scientist> &s);

    private:
        string name;
        bool gender;
        int yob;
        int yod;
};

#endif // SCIENTIST_H
