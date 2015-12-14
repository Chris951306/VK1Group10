#ifndef ADDC_H
#define ADDC_H
#include <QDate>
#include "service.h"

#include <QDialog>

namespace Ui {
class AddC;
}

class AddC : public QDialog
{
    Q_OBJECT

public:
    explicit AddC(int n, QWidget *parent = 0);
    ~AddC();
    void setMaxYear();
    bool checkName(QString &name);

private slots:
    void on_button_c_add_clicked();

private:
    Ui::AddC *ui;
    service s;
    int id;
};

#endif // ADDC_H
