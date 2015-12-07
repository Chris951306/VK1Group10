#ifndef DISPLAY_H
#define DISPLAY_H
#include "service.h"

class display{
public:
    void printScientists();
    void printScientist(unsigned int val);
    bool sortScientist();
    void printComputers();
    void printComputer(unsigned int val);
    bool sortComputers();
    void printCStoC();
    void printCtoCS();
};

#endif // DISPLAY_H
