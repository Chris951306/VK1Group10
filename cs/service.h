#ifndef SERVICE_H
#define SERVICE_H
#include "data.h"
#include "service.h"

class service
{
public:
    istream& readName(string &s);                   //  Enables getline(cin, stringname) to be used within class
    istream& readLine(ifstream &load, string &a);   //  Enables the program to read from a document within class
    void printData(vector<data> &cs);               //  Print all instances of a data-class file stored in vector
    void addData(vector<data> &cs);                 //  Adds a scientist to the database
    void editData(vector<data> &cs);                //  Edits a scientist currently stored in the database
    int legalBirth();                               //  Determines whether a birth-year is legal or not, returns the birth-year
    int legalDeath(int yob);                        //  Determines whether a death-year is legal or not, returns the death-year
    bool legalGender();                             //  Determines whether the input for gender is legal or not
    unsigned int selectData(string &s);             //  Converts a string input for a scientist number to an unsigned integer
    bool isLetter(string &s);                       //  Returns true if there is a letter in the input for scientist number
    void saveData(vector<data> &cs);                //  Saves the current vector to the file scientists.txt
    void loadData(vector<data> &cs);                //  Loads the file scientists.txt and stores the data in the vector
    void deleteData(vector<data> &cs);              //  Deletes a scientist from the database
};

#endif // SERVICE_H
