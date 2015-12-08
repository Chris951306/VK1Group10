#ifndef SCIENTISTS_H
#define SCIENTISTS_H
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

class scientists{
    public:
        scientists(unsigned int id, string a, bool b, int c, int d);//  Default constructor
        unsigned int returnId();                                    //  Does what is says
        string returnName();                                        //  --------||-------
        bool returnGender();                                        //  --------||-------
        int returnYob();                                            //  --------||-------
        int returnYod();                                            //  --------||-------
        friend ostream& operator<<(ostream& stream, const scientists &s); //  Overloads << for class
    private:
        unsigned int cs_id;
        string name;
        bool gender;
        int yob;    //  Year of birth
        int yod;    //  Year of death
};

#endif // SCIENTISTS_H
