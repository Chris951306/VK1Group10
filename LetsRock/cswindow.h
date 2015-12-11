#ifndef CSWINDOW_H
#define CSWINDOW_H

#include <QDialog>

namespace Ui {
class CSWindow;
}

class CSWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CSWindow(QWidget *parent = 0);
    ~CSWindow();

private slots:
    void on_pushMenuButton_clicked();

private:
    Ui::CSWindow *ui;
};

#endif // CSWINDOW_H
