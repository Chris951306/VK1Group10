#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <iostream>

using namespace std;

class scientist{
public:
    scientist(unsigned int a, string b, bool c, int d, int e);
    unsigned int returnId();
    string returnName();
    bool returnGender();
    int returnYod();
    int returnYob();
private:
    unsigned int id;
    string name;
    bool gender;
    int yob;
    int yod;
};

#endif // SCIENTIST_H
