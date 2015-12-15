#ifndef MAINMENU_H
#define MAINMENU_H
#include "service.h"
#include "addcs.h"
#include "addc.h"
#include "addl.h"
#include "snoop.h"
#include <QMainWindow>
#include <QModelIndex>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);  //Default constructor for main menu class
    ~MainMenu();  //Default constructor
    void displayScientists(std::vector<scientist> scientists);  //Add all scientist in table widget
    void displayComputers(std::vector<computer> computers);     //Add all computers in table widget
    void displayLinks(std::vector<link> links);  //Add links between scientist and computers in table

private slots:

    void on_radioButton_toggled(bool checked);  //Set right values to  all buttons and creates the vector scientists
    void on_radioButton_2_toggled(bool checked); //Set right values to  all buttons and creates the vector computers
    void on_radioButton_3_toggled(bool checked);  //Set right values to all buttons and creates the vector links
    void on_pushAddButton_clicked(); //Opens an add window
    void on_pushEditButton_clicked();  //Opens an edit window with the values of selected item
    void on_pushDeleteButton_clicked(); //Deletes the selected item
    void on_searchDatabase_textChanged(const QString &arg1);  //Takes in QString from signal and sends it into search database function
    void on_tableWidget_clicked(const QModelIndex &index); //If an item is selected in widget table then enables these buttons
    void on_button_snoop_clicked(); //D O GG - Snoops the program
    void on_refreshButton_clicked(); //Refreshes the widget table

private:
    Ui::MainMenu *ui;
    service s;
};

#endif // MAINMENU_H
