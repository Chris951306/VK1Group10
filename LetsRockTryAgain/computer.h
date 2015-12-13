#ifndef COMPUTER_H
#define COMPUTER_H
#include <QString>

class computer{
public:
    computer(int i, QString a, QString b, QString c, QString d);
    int getId();
    QString getName();
    QString getYear();
    QString getType();
    QString getBuilt();
private:
    int id;
    QString name, year, type, built;
};

#endif // COMPUTER_H
