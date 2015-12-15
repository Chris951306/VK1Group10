#ifndef ADDL_H
#define ADDL_H

#include <QDialog>
#include "service.h"

namespace Ui {
class addl;
}

class addl : public QDialog{
    Q_OBJECT

public:
    explicit addl(int n, int m, QWidget *parent = 0); //Default constructor for class. Takes two integers for current csid and cid values
    ~addl(); //Default destructor for class
    void displayComputers(std::vector<computer> computers); //Adds all computers to right side table
    void displayScientists(std::vector<scientist> scientists); //Adds all scientists to left side table

private slots:
    void on_pushButton_clicked(); //Signal for add/edit button to be clicked
    void on_tableWidget_2_clicked(const QModelIndex &index); //Signal for left side table selected, sets bool cs_cliked to true
    void on_tableWidget_1_clicked(const QModelIndex &index); //Signal for right side table selected, sets bool c_cliked to true

private:
    Ui::addl *ui;
    service s; //Service-class file
    bool cs_clicked; //Check if left side table has a selected item
    bool c_clicked; //Check if right side table has a selected item
    int csid; //Value used to edit link
    int cid; //Value used to edit link
};

#endif // ADDL_H
