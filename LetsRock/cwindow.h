#ifndef CWINDOW_H
#define CWINDOW_H

#include <QDialog>

namespace Ui {
class cwindow;
}

class cwindow : public QDialog
{
    Q_OBJECT

public:
    explicit cwindow(QWidget *parent = 0);
    ~cwindow();

private slots:
    void on_AddCButton_clicked();

private:
    Ui::cwindow *ui;
};

#endif // CWINDOW_H
