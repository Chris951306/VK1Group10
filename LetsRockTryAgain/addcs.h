#ifndef ADDCS_H
#define ADDCS_H
#include "service.h"
#include <QDialog>
#include <QDate>

namespace Ui {
class AddCS;
}

class AddCS : public QDialog{
    Q_OBJECT

public:
    explicit AddCS(int n, QWidget *parent = 0); //Default constructor for class. Takes an optional id for edit
    ~AddCS(); //Default destructor for class
    void setMaxYear(); //Sets the maximum year for birth- and death-input equal to current year
    bool checkName(QString &name); //Checks the name-input for errors and formats it accorded to set standard

private slots:
    void on_input_cs_alive_toggled(bool checked); //Signal to check if 'still alive' checkbox is toggled
    void on_button_cs_add_clicked(); //Signal for add/edit button to be clicked

private:
    Ui::AddCS *ui;
    service s; //Service-class file
    int id; //Optional id used in edit
};

#endif // ADDCS_H
