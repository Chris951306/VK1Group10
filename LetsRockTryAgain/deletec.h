#ifndef DELETEC_H
#define DELETEC_H

#include <QDialog>
#include "service.h"

namespace Ui {
class deletec;
}

class deletec : public QDialog
{
    Q_OBJECT

public:
    explicit deletec(QWidget *parent = 0);
    ~deletec();
    void displayComputers(std::vector<computer> computers);

private slots:
    void on_pushButton_clicked();

private:
    Ui::deletec *ui;
};

#endif // DELETEC_H
