#include "cwindow.h"
#include "ui_cwindow.h"

cwindow::cwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cwindow)
{
    ui->setupUi(this);
}

cwindow::~cwindow()
{
    delete ui;
}
