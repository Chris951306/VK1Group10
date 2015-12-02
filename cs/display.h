#ifndef DISPLAY_H
#define DISPLAY_H
#include "data.h"
#include "service.h"
#include "display.h"

class display
{
public:
    display();
    void viewData(vector<data> &cs);    //  Prints out every instance of the data-class file through the printData-function in service-class
};                                      //  Also holds options for various sorting methods

#endif // DISPLAY_H
