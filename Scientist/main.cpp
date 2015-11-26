#include "scientist.h"

int main()
{
    vector<scientist> s;
    for(unsigned int i = 0; i < 1; i++){
        scientist temp1;
        temp1.readInfo();
        s.push_back(temp1);
    }
    for(unsigned int i = 0; i < 1; i++){
        scientist temp2;
        temp(temp2, s);
        temp2.editInfo();
    }

    return 0;
}
