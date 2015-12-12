#ifndef SERVICE_H
#define SERVICE_H
#include "database_scientists.h"
#include <iostream>

class service
{
public:
    void start();
private:
    database_scientists db;
};

#endif // SERVICE_H
