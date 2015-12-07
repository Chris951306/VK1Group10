#ifndef DISPLAY_H
#define DISPLAY_H
#include "service.h"

class display{
public:
    void printCStop();
    void printCSbot();
    void printCtop();
    void printCbot();
    void printScientists();
    void printScientist(unsigned int val);
    bool sortScientist(bool &namesort, bool &gendersort, bool &yobsort);
    void printComputers();
    void printComputer(unsigned int val);
    bool sortComputers(bool &namesort, bool &yearsort, bool &typesort, bool &builtsort);
    void printCStoC();
    void printCtoCS();
};

#endif // DISPLAY_H
