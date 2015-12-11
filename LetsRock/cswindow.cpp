#include "cswindow.h"
#include "ui_cswindow.h"
#include "mainmenu.h"
#include "cwindow.h"
#include "addcs.h"

CSWindow::CSWindow(QWidget *parent):QDialog(parent), ui(new Ui::CSWindow){
    ui->setupUi(this);
}

CSWindow::~CSWindow(){
    delete ui;
}


void CSWindow::on_CSMenuButton_clicked(){
    this->hide();
}

void CSWindow::on_AddCSButton_clicked(){
    AddCS add;
    add.setModal(true);
    add.exec();
}
