#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <vector>

using namespace std;

class scientist
{
    public:
        scientist();
        unsigned int size();
        void readInfo();
        void editInfo();
        friend ostream& operator<<(ostream& stream, const scientist &s);
        friend void temp(scientist &s1, vector<scientist> &s2);
    private:
        string name;
        bool gender;
        int dob;
        int dod;
};

#endif // SCIENTIST_H
