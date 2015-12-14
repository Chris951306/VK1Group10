#ifndef DELETECS_H
#define DELETECS_H

#include <QDialog>
#include "service.h"

namespace Ui {
class deletecs;
}

class deletecs : public QDialog
{
    Q_OBJECT

public:
    explicit deletecs(QWidget *parent = 0);
    ~deletecs();
    void displayScientists(std::vector<scientist> scientists);

private slots:
    void on_pushButton_clicked();

private:
    Ui::deletecs *ui;
};

#endif // DELETECS_H
