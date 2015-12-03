#ifndef DISPLAY_H
#define DISPLAY_H
#include "scientists.h"
#include "service.h"
#include "display.h"

class display
{
public:
    void viewScientists(vector<scientists> &cs);                        //  Prints out every instance of the different class files
    void viewCombination(vector<scientists> &cs, vector<computers> &c); //  through the printData-function in service-class
};                                                                      //  Also holds options for various sorting methods

#endif // DISPLAY_H
