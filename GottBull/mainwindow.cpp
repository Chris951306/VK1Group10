#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    QPixmap logo("C:/Users/ÞórmundurSmári/VN1Group10/GottBull/logo.png");
    ui->labelPic->setPixmap(logo);
}

MainWindow::~MainWindow(){
    delete ui;
}
