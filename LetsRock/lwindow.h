#ifndef LWINDOW_H
#define LWINDOW_H

#include <QDialog>

namespace Ui {
class LWindow;
}

class LWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LWindow(QWidget *parent = 0);
    ~LWindow();

private:
    Ui::LWindow *ui;
};

#endif // LWINDOW_H
