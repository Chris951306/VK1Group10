#ifndef MAINMENU_H
#define MAINMENU_H
#include "service.h"
#include "addcs.h"
#include "addc.h"
#include <QMainWindow>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow{
    Q_OBJECT


public:
    void connClose();
    bool connOpen();
    void displayComputers(std::vector<computer> computers);
    void displayScientists(std::vector<scientist> scientists);
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_pushAddButton_clicked();

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_searchDatabase_textChanged(const QString &arg1);

private:
    Ui::MainMenu *ui;
    service s;
};

#endif // MAINMENU_H
