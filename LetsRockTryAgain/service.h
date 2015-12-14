#ifndef SERVICE_H
#define SERVICE_H
#include "database.h"

class service{
public:
    void start();
    void addScientist(scientist s);
    void addComputer(computer c);
    void getAllScientists(std::vector<scientist>& scientists);
    void getAllComputers(std::vector<computer>& computers);
private:
    database db;
};

#endif // SERVICE_H
