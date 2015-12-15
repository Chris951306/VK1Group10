#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <QString>

class scientist{
public:
    scientist(int i, QString a, QString b, QString c, QString d); //Default constructer for class
    int getId();          //Returns current id
    QString getName();    //Returns current name
    QString getGender();  //Returns current gender
    QString getYob();     //Returns current birthyear
    QString getYod();     //Returns current deathyear
private:
    int id; //Scientist-id
    QString name, gender, yob, yod;  //Scientist-name, -gender, -birthyear, -deathyear
};

#endif // SCIENTIST_H
