#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu){
    ui->setupUi(this);
    service s;
    s.start();

}

MainMenu::~MainMenu(){
    delete ui;
}

void MainMenu::on_pushAddButton_clicked(){
    Add a;
    a.setModal(true);
    a.exec();
}

void MainMenu::on_radioButton_toggled(bool checked){
    service s;
    if(checked){
        QSqlQueryModel * modal=new QSqlQueryModel();
        modal->setQuery(s.returnCSquery());
        ui->tableView->setModel(modal);
        qDebug() << (modal->rowCount());

    }
}

void MainMenu::on_radioButton_2_toggled(bool checked){
    service s;
    if(checked){
        QSqlQueryModel * modal=new QSqlQueryModel();
        modal->setQuery(s.returnCquery());
        ui->tableView->setModel(modal);
        qDebug() << (modal->rowCount());

    }
}
