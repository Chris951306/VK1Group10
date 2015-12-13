#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <QString>

class scientist{
public:
    scientist(int i, QString a, QString b, QString c, QString d);
    int getId();
    QString getName();
    QString getGender();
    QString getYob();
    QString getYod();
private:
    int id;
    QString name, gender, yob, yod;
};

#endif // SCIENTIST_H
