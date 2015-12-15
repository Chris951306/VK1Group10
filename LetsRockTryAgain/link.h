#ifndef LINK_H
#define LINK_H
#include <iostream>

using namespace std;

class link{
public:
    link(int a, int b); //Default constructor for class
    int returnCSID();   //Returns current scientist id
    int returnCID();    //Returns current computer id

private:
    int csid;  //scientist-id
    int cid;   //computer-id
};

#endif // LINK_H
