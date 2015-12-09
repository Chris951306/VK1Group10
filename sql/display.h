#ifndef DISPLAY_H
#define DISPLAY_H
#include "service.h"

class display{
public:
    void printCStop(); // Prints the header of scientists display
    void printCSbot(); // prints the bottom of scientists display and total amount scientists stored
    void printCtop(); // Prints the header of computers display
    void printCbot(); // prints the bottom of computers display and total amount computers stored
    void addScientist(); // adds scientist to be stored
    bool editScientist(unsigned int val); // edit scientist
    void printScientists(); // prints all scientists
    void printScientist(unsigned int val); // Prints one scientist with the Id = val
    bool sortScientists(bool &namesort, bool &gendersort, bool& yobsort); // Sorts scientists by name, gender, yob
    bool searchScientists(vector<int> &id); // search for scientist in database... by name, gender, yob or yod
    int legalBirth(); // Checks if it's valid birth
    int legalDeath(int yob); // Checks if it's valid death
    bool legalGender(); // Checks if it's valid gender
    bool checkName(QString &name); // Checks if it's legal name
    void addComputer(); // adds computer to be stored
    bool editComputer(unsigned int val); // edit computer
    void printComputer(unsigned int val); // Prints one computer with the Id = val
    void printComputers(); // prints all computers
    bool sortComputers(bool &namesort, bool &yearsort, bool &typesort, bool &builtsort); // Sorts scientists by name, year, type, built
    bool searchComputers(vector<int> &id); // search for computer in database... by name, year, type or built
    int legalYear(); // Checks if the year is legal
    bool legalBuilt(); // Checks if the built is legal
    void addLink(int csid, int cid); // Adds a link between scientist with id = csid and computer with id = cid
    unsigned int selectUnit(string s); // Changes string s to a number.
    bool isLetter(string s); // Checks if s is a letter
    void multiSearch(QString &s); // Takes QString s and adds '%' in front and behind the string so that it is possible to search for substring
    void printCStoC(); // Prints all scientists and computers which are linked to each scientist
    void printCtoCS(); // Prints all computers and scientists which are linked to each computer
};

#endif // DISPLAY_H
