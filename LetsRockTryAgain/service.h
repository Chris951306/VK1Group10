#ifndef SERVICE_H
#define SERVICE_H
#include "database.h"

class service{
public:
    void start(); //Call function that opens the database
    void addScientist(scientist s);  //Calls function addScientist from database
    void editScientist(scientist s); //Calls function editScientist from database
    void addComputer(computer c); //Calls function addComputer from database
    void editComputer(computer c); //Calls function editComputer from database
    void addLink(int csid, int cid); //Calls function addLink from database
    void editLink(int newCSID, int newCID, int csid, int cid); //Calls function editLink from database
    void getAllScientists(std::vector<scientist>& scientists); //Calls function getAllScientists from database
    void getAllComputers(std::vector<computer>& computers); //Calls function getAllComputers from database
    void getAllLinks(std::vector<link>& links); //Calls function getAllLinks from database
    void searchScientist(std::vector<scientist>& scientists, QString string); //Calls function searchScientist from database
    void searchComputer(std::vector<computer>& computers, QString string); //Calls function searchComputer from database
    bool isLink(int csid, int cid); //Calls function isLink from database
    void deleteScientist(int id); //Calls function deleteScientist from database
    void deleteComputer(int id); //Calls function deleteComputer from database
    void deleteLink(int csid, int cid); //Calls function deleteLink from database
    QString getCSName(int csid); //Calls function getCSName from database
    QString getCName(int cid); //Calls function getCName from database
private:
    database db;  //Sql database is set as private so it can be accessed by all the functions
};

#endif // SERVICE_H
