#ifndef ADDCS_H
#define ADDCS_H
#include "service.h"
#include <QDialog>
#include <QDate>

namespace Ui {
class AddCS;
}

class AddCS : public QDialog
{
    Q_OBJECT

public:
    explicit AddCS(QWidget *parent = 0);
    ~AddCS();
    void setMaxYear();
    bool checkName(QString &name);

private slots:
    void on_input_cs_alive_toggled(bool checked);

    void on_button_cs_add_clicked();

private:
    Ui::AddCS *ui;
};

#endif // ADDCS_H
