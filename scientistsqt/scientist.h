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
        scientist(); //default constructor
        unsigned int size(); //returns size
        void readInfo(); //reads the info from user (name, gender, birth year and year of death) about the scientists.
        void editInfo(); //makes it possible to make changes about scientists
        bool legalBirth(int yob); //checks if value yob (year of birth) is legal.
        bool legalDeath(int yob, int yod); //checks if value yod (year of death) is legal.
        friend ostream& operator<<(ostream& stream, const scientist &s); //displays the scientist with the operator <<
        friend string retName(scientist &s); //returns the name user searches for in database
        friend void viewInfo(vector<scientist> &s); //display all scientists that are in vector s
        friend void saveInfo(vector<scientist> &s); //saves scientists info in a file
        friend void loadInfo(vector<scientist> &s); //loads info in vector
        friend void delInfo(vector<scientist> &s); //deletes info

    private:
        string name; //scientist name
        bool gender;
        int yob; // year of birth
        int yod; // year of death
};

#endif // SCIENTIST

