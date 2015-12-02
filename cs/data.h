#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MinYear = -1000;
const int MaxYear = 2015;
const int StillAlive = 3000; //value that makes the program know that a person is still alive

class data{
    public:
        data(string a, bool b, int c, int d);
        string returnName();
        bool returnGender();
        int returnYob();
        int returnYod();
        friend ostream& operator<<(ostream& stream, const data &s);
    private:
        string name;
        bool gender;
        int yob;
        int yod;
};

#endif // DATA_H
