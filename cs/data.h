#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MinYear = -1000;      //
const int MaxYear = 2015;       //  Const definitions used to determine min/max-values and if scientist is still alive
const int StillAlive = 3000;    //

class data{
    public:
        data(string a, bool b, int c, int d);                       //  Default constructor
        string returnName();                                        //  Does what is says
        bool returnGender();                                        //  --------||-------
        int returnYob();                                            //  --------||-------
        int returnYod();                                            //  --------||-------
        friend ostream& operator<<(ostream& stream, const data &s); //  Overloads << for class
    private:
        string name;
        bool gender;
        int yob;    //  Year of birth
        int yod;    //  Year of death
};

#endif // DATA_H
