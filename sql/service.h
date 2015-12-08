#ifndef SERVICE_H
#define SERVICE_H
#include "database.h"

class service{
public:
    void addScientist();
        //^Adds a scientist based on the user's inputs to the sql database
    bool editScientist(unsigned int val);
        //^Edits a scientist based on the user's inputs in the sql database
    int legalBirth();
        //^Determines whether the scientist's year of birth is legal or not
    int legalDeath(int yob);
        //^Determines whether the scientist's year of death is legal, not legal or if scientist is alive
    bool legalGender();
        //^Determines whether the scientist's gender is valid - only accepts 'm' or 'f' as input
    void addComputer();
        //^Adds a computer based on the user's inputs to the sql database
    bool editComputer(unsigned int val);
        //^Edits a computer based on the user's inputs in the sql database
    int legalYear();
        //^Determines whether the computer's build year is legal or not
    bool legalBuilt();
        //^Determines whether the computer was built or not
    unsigned int selectUnit(string s);
        //^Converts a string containing a number into an unsigned int to use when selecting scientists or computers to edit
    bool isLetter(string s);
        //^Determines whether the string contains a letter or not
    bool checkName(QString &name);
        //^Checks and fixes a QString to fit within the appropriate spacing- and capitalization-rules of the database
    void multiSearch(QString &s);
        //^Adds a '%' to the beginning and the end of the QString used to search - allows to search with QString as substring
    bool searchScientist(vector<int> &id);
        //^Allows user to search for a scientist based on the 4 input values - stores the valid id's in the vector
    bool searchComputer(vector<int> &id);
        //^Allows user to search for a computer based on the 4 input values - stores the valid id's in the vector
    void addLink(int csid, int cid);
        //^Adds a link between a scientist and a computer to the sql database
};

#endif // SERVICE_H
