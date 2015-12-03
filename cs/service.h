#ifndef SERVICE_H
#define SERVICE_H
#include "scientists.h"
#include "computers.h"
#include "service.h"

class service
{
public:
    istream& readName(string &s);                   //  Enables getline(cin, stringname) to be used within class
    istream& readLine(ifstream &load, string &a);   //  Enables the program to read from a document within class
    void printScientists(vector<scientists> &cs);   //  Print all instances of a data-class file stored in vector
    void addScientist(vector<scientists> &cs);      //  Adds a scientist to the database
    void addComputer(vector<computers> &cc);        //  Adds a computer to the database
    void editScientist(vector<scientists> &cs);     //  Edits a scientist currently stored in the database
    int legalBirth();                               //  Determines whether a birth-year is legal or not, returns the birth-year
    int legalDeath(int yob);                        //  Determines whether a death-year is legal or not, returns the death-year
    bool legalGender();                             //  Determines whether the input for gender is legal or not
    int legalYear();                                //  Determines whether the build year is legal or not, returns the build year
    bool legalBuilt();                              //  Determines whether the computer was built or not
    unsigned int selectUnit(string &s);             //  Converts a string input for a scientist number to an unsigned integer
    bool isLetter(string &s);                       //  Returns true if there is a letter in the input for scientist number
    void saveData(vector<scientists> &cs);          //  Saves the current vector to the file scientists.txt
    void loadData(vector<scientists> &cs);          //  Loads the file scientists.txt and stores the data in the vector
    void deleteScientist(vector<scientists> &cs);   //  Deletes a scientist from the database
};

#endif // SERVICE_H
