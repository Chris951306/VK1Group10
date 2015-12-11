#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    void ShowAgain();
    ~MainMenu();

private slots:
    void on_pushCSbutton_clicked();

    void on_pushCButton_clicked();

    void on_pushLButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
