#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "cswindow.h"
#include "cwindow.h"
#include "lwindow.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

void MainMenu::ShowAgain(){
    this->show();
}

MainMenu::~MainMenu(){
    delete ui;
}

void MainMenu::on_pushCSbutton_clicked(){
    this->hide();
    CSWindow cs;
    cs.setModal(true);
    cs.exec();
}

void MainMenu::on_pushCButton_clicked()
{
    this->hide();
    cwindow c;
    c.setModal(true);
    c.exec();
}

void MainMenu::on_pushLButton_clicked()
{
    this->hide();
    LWindow l;
    l.setModal(true);
    l.exec();
}
