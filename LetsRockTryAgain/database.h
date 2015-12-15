#ifndef DATABASE_H
#define DATABASE_H
#include "scientist.h"
#include "computer.h"
#include "link.h"
#include <iostream>
#include <QtSql>
#include <vector>

class database{
public:
    void start(); //Open the database
    void addScientist(scientist s); // Add scientists to database
    void editScientist(scientist s); //Edit scientists s in database
    void addComputer(computer c); //Add computer to database
    void editComputer(computer c); //Edit computer c in database
    void addLink(int csid, int cid); // Adds a link to database
    void editLink(int newCSID, int newCID, int csid, int cid); // Edit link in database with the values csid and cid and edit it to newCSID and newCID
    void getAllScientists(std::vector<scientist>& scientists); //Get all scientists  from database and fills the vector scientists of these values
    void getAllComputers(std::vector<computer>& computers); //Get all computers  from database and fills the vector computers of these values
    void getAllLinks(std::vector<link>& links); //Get all links  from database and fills the vector links of these values
    void searchScientist(std::vector<scientist>& scientists, QString string); //Searches in database for all scientists that have name, yob or yod in it. If you write male you only get male. Same for female
    void searchComputer(std::vector<computer>& computers, QString string); //Searches in database for all computers that have name, type or year in it. If you write built you only get built. Same for not built
    bool isLink(int csid, int cid); // Returns true if link already exists
    void deleteScientist(int id); //Deletes scientits with value id and also all links that he is in
    void deleteComputer(int id); //Deletes computer with value id and also all links that the computer is in
    void deleteLink(int csid, int cid); //Delete link with these values
    QString getCSName(int csid); // Returns the name of scientist with the id = csid
    QString getCName(int cid); // Returns the name of computer with the id = cid
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
