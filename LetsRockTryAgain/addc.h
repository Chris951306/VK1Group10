#ifndef ADDC_H
#define ADDC_H
#include <QDate>
#include "service.h"

#include <QDialog>

namespace Ui {
class AddC;
}

class AddC : public QDialog{
    Q_OBJECT

public:
    explicit AddC(int n, QWidget *parent = 0); //Default constructor for class. Takes an optional id for edit
    ~AddC(); //Default destructor for class
    void setMaxYear(); //Sets the maximum year for build year equal to current year
    bool checkName(QString &name); //Checks the name-input for errors and formats it accorded to set standard

private slots:
    void on_button_c_add_clicked(); //Signal for add/edit button to be clicked

private:
    Ui::AddC *ui;
    service s; //Service-class file
    int id; //Optional id used in edit
};

#endif // ADDC_H
