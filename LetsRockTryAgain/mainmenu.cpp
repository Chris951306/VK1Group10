#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "add.h"

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu){
    ui->setupUi(this);


}

MainMenu::~MainMenu(){
    delete ui;
}

void MainMenu::on_pushAddButton_clicked(){
    Add a;
    a.setModal(true);
    a.exec();
}
