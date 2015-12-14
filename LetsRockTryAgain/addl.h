#ifndef ADDL_H
#define ADDL_H

#include <QDialog>
#include "service.h"

namespace Ui {
class addl;
}

class addl : public QDialog
{
    Q_OBJECT

public:
    explicit addl(QWidget *parent = 0);
    ~addl();
    void displayComputers(std::vector<computer> computers);
    void displayScientists(std::vector<scientist> scientists);
private slots:
    void on_pushButton_clicked();

private:
    Ui::addl *ui;
};

#endif // ADDL_H
