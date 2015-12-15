#include "addl.h"
#include "ui_addl.h"

addl::addl(QWidget *parent) : QDialog(parent), ui(new Ui::addl){
    ui->setupUi(this);
    std::vector<scientist> scientists;
    std::vector<computer> computers;
    s.getAllScientists(scientists);
    s.getAllComputers(computers);
    displayScientists(scientists);
    displayComputers(computers);
}

addl::~addl()
{
    delete ui;
}


void addl::displayComputers(std::vector<computer> computers){
    ui->tableWidget_1->clearContents();
    ui->tableWidget_1->setRowCount(computers.size());
    ui->tableWidget_1->verticalHeader()->show();
    ui->tableWidget_1->setColumnCount(1);
    ui->tableWidget_1->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_1->setHorizontalHeaderLabels(QString("Computer name").split(";"));

    for (unsigned int i = 0; i < computers.size(); i++){
        computer currentComputer = computers[i];

        QString name = currentComputer.getName();

        ui->tableWidget_1->setItem(i, 0, new QTableWidgetItem(name));
    }
}

void addl::displayScientists(std::vector<scientist> scientists){
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(scientists.size());
    ui->tableWidget_2->verticalHeader()->show();
    ui->tableWidget_2->setColumnCount(1);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setHorizontalHeaderLabels(QString("Scientist name").split(";"));

    for (unsigned int i = 0; i < scientists.size(); i++){
        scientist currentScientist = scientists[i];

        QString name = currentScientist.getName();

        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(name));
    }
}

void addl::on_pushButton_clicked(){
    bool exist = false;
    int csid = ui->linecsid->text().toInt();
    int cid = ui->linecid->text().toInt();
    int maxcs = s.countScientists();
    int maxc = s.countComputers();

    if(csid > 0 && csid <= maxcs && cid > 0 && cid <= maxc){
        exist = s.isLink(csid, cid);
        if(!exist){
            s.addLink(csid,cid);
            this->hide();
        }
    }
}
