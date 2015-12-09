#ifndef DISPLAY_H
#define DISPLAY_H
#include "service.h"

class display{
public:
    void printCStop(); // Prints the header of scientists display
    void printCSbot(); // Prints the bottom of scientists display and total amount scientists stored
    void printCtop(); // Prints the header of computers display
    void printCbot(); // prints the bottom of computers display and total amount computers stored
    void addScientist(); // Adds scientist to be stored
    bool editScientist(unsigned int val); // Edit scientist
    void printScientist(unsigned int val); // Prints one scientist with the Id = val
    void printScientists(); // Prints all scientists
    bool sortScientists(bool &namesort, bool &gendersort, bool& yobsort); // Sorts scientists by name, gender, yob
    bool searchScientists(vector<int> &id); // Search for scientist in database... by name, gender, yob or yod
    int legalBirth(); // Checks if it's valid birth
    int legalDeath(int yob); // Checks if it's valid death
    bool legalGender(); // Entire function only makes sure input is either m or f, and sets the appropriate boolean value to the variable
    bool checkName(QString &name); // Checks if it's legal name
    void addComputer(); // Adds computer to be stored
    bool editComputer(unsigned int val); // Edit computer
    void printComputer(unsigned int val); // Prints one computer with the Id = val
    void printComputers(); // Prints all computers
    bool sortComputers(bool &namesort, bool &yearsort, bool &typesort, bool &builtsort); // Sorts scientists by name, year, type, built
    bool searchComputers(vector<int> &id); // Search for computer in database... by name, year, type or built
    int legalYear(); // Checks if the year is legal
    bool legalBuilt(); // Checks if the built is legal
    void addLink(int csid, int cid); // Adds a link between scientist with id = csid and computer with id = cid
    void editLink(); // Edits a link between CS and C, based on user's choices
    unsigned int selectUnit(string s); // Changes string s to a number.
    bool isLetter(string s); // Checks if s contains a letter
    void multiSearch(QString &s); // Takes QString s and adds '%' in front and behind the string so that it is possible to search for substring
    void printCStoC(); // Prints all scientists and computers which are linked to each scientist
    void printCtoCS(); // Prints all computers and scientists which are linked to each computer
};

#endif // DISPLAY_H
