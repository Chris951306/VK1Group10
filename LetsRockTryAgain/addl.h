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
    explicit addl(int n, int m, QWidget *parent = 0);
    ~addl();
    void displayComputers(std::vector<computer> computers);
    void displayScientists(std::vector<scientist> scientists);
private slots:
    void on_pushButton_clicked();

    void on_tableWidget_2_clicked(const QModelIndex &index);

    void on_tableWidget_1_clicked(const QModelIndex &index);

private:
    Ui::addl *ui;
    service s;
    bool cs_clicked;
    bool c_clicked;
    int csid;
    int cid;
};

#endif // ADDL_H
