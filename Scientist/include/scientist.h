#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <vector>
#include <string>

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
        friend ostream& operator<<(ostream& stream, const scientist &s);
        friend string retName(scientist &s);
        friend void viewInfo(vector<scientist> &s);
        friend bool operator<(scientist &s1, scientist &s2);
    private:
        string name;
        bool gender;
        int yob;
        int yod;
};

#endif // SCIENTIST_H
