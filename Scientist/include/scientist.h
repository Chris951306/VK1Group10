#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>

using namespace std;

class scientist
{
    public:
        scientist();
        void getInfo();
    private:
        string name;
        bool gender;
        int dob;
        int dod;
};

#endif // SCIENTIST_H
