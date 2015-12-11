#include "cswindow.h"
#include "ui_cswindow.h"
#include "mainmenu.h"
#include "cwindow.h"

CSWindow::CSWindow(QWidget *parent):QDialog(parent), ui(new Ui::CSWindow){
    ui->setupUi(this);
}

CSWindow::~CSWindow(){
    delete ui;
}

void CSWindow::on_pushMenuButton_clicked(){
    this->hide();

}
