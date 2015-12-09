#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>

using namespace std;

class computer{
public:
    computer(unsigned int a, string b, int c, string d, bool e);
    unsigned int returnId();
    string returnName();
    int returnYear();
    string returnType();
    bool returnBuilt();
private:
    unsigned int id;
    string name;
    int year;
    string type;
    bool built;
};

#endif // COMPUTER_H
