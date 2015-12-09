#ifndef LINK_H
#define LINK_H
#include <iostream>

class link{
public:
    link(int a, int b);
    int returnCSID();
    int returnCID();
private:
    int csid;
    int cid;
};

#endif // LINK_H
