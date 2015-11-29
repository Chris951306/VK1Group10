#ifndef SCIENTIST
#define SCIENTIST

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class scientist
{
    public:
        scientist();
        unsigned int size();
        void readInfo();
        void editInfo();
        bool legalBirth(unsigned int yob);
        bool legalDeath(unsigned int yob, unsigned int yod);
        friend ostream& operator<<(ostream& stream, const scientist &s);
        friend string retName(scientist &s);
        friend void viewInfo(vector<scientist> &s);
        friend void saveInfo(vector<scientist> &s);
        friend void loadInfo(vector<scientist> &s);
        friend void delInfo(vector<scientist> &s);

    private:
        string name;
        bool gender;
        unsigned int yob;
        unsigned int yod;
};

#endif // SCIENTIST

