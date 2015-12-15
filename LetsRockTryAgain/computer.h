#ifndef COMPUTER_H
#define COMPUTER_H
#include <QString>

class computer{
public:
    computer(int i, QString a, QString b, QString c, QString d);  //Default constructor for class
    int getId();        //Returns the current id
    QString getName();  //Returns the current name
    QString getYear();  //Returns the current year
    QString getType();  //Returns the current type
    QString getBuilt(); //Returns the current built status

private:
    int id;   //Computer-id
    QString name, year, type, built; //Computer-name, -year, -type, - build status
};

#endif // COMPUTER_H
