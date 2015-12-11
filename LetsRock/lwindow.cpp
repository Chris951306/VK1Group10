#include "lwindow.h"
#include "ui_lwindow.h"

LWindow::LWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LWindow)
{
    ui->setupUi(this);
}

LWindow::~LWindow()
{
    delete ui;
}
