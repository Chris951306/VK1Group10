#include "cwindow.h"
#include "ui_cwindow.h"
#include "addc.h"

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

void cwindow::on_AddCButton_clicked()
{
    AddC add;
    add.setModal(true);
    add.exec();
}
