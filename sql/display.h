#ifndef DISPLAY_H
#define DISPLAY_H
#include "service.h"

class display{
public:
    void printCStop();
        //Prints out the top part of scientist print format
    void printCSbot();
        //Prints out the bottom part of scientist print format
    void printCtop();
        //Prints out the top part of computer print format
    void printCbot();
        //Prints out the bottom part of computer print format
    void printScientists();
        //Prints out all scientists stored in sql database
    void printScientist(unsigned int val);
        //Prints out a single scientist based on the id, which is parsed into function
    bool sortScientist(bool &namesort, bool &gendersort, bool &yobsort);
        //Sorts all scientist based on the users input
    void printComputers();
        //Prints out all computers stored in sql database
    void printComputer(unsigned int val);
        //Prints out a single computer based on the id, which is parsed into function
    bool sortComputers(bool &namesort, bool &yearsort, bool &typesort, bool &builtsort);
        //Sorts all computers based on the users input
    void printCStoC();
        //Prints out all the scientists and which computers they have contributed to
    void printCtoCS();
        //Prints out all the computers and which scientists have contributed to them
};

#endif // DISPLAY_H
