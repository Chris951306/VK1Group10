#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class computers
{
public:
    computers(unsigned int id, string a, int b, string c, bool d);
    unsigned int returnId();
    string returnName();
    int returnYear();
    string returnType();
    bool returnBuilt();
private:
    unsigned int c_id;
    string c_name;
    int c_year;
    string c_type;
    bool c_built;
};

#endif // COMPUTERS_H
