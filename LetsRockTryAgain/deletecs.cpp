#include "deletecs.h"
#include "ui_deletecs.h"

deletecs::deletecs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletecs)
{
    ui->setupUi(this);

    service s;
    std::vector<scientist> scientists;
    s.getAllScientists(scientists);
    displayScientists(scientists);
}

deletecs::~deletecs()
{
    delete ui;
}

void deletecs::displayScientists(std::vector<scientist> scientists){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(scientists.size());
    ui->tableWidget->verticalHeader()->show();
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(QString("Scientist name").split(";"));

    for (unsigned int i = 0; i < scientists.size(); i++){
        scientist currentScientist = scientists[i];

        QString name = currentScientist.getName();


        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(name));
    }
}

void deletecs::on_pushButton_clicked(){
    service s;
    int maxcs = s.countScientists();
    QString csidInString = ui->lineEdit->text();
    int csid = csidInString.toInt();
    if(csid > 0 && csid <= maxcs){
        //DELETE DO LATER;
        this->hide();
    }
}
