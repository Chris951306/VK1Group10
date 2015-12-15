#include "addl.h"
#include "ui_addl.h"

addl::addl(int n, int m, QWidget *parent) : QDialog(parent), ui(new Ui::addl){
    ui->setupUi(this);
    cs_clicked = false;
    c_clicked = false;
    std::vector<scientist> scientists;
    std::vector<computer> computers;
    s.getAllScientists(scientists);
    s.getAllComputers(computers);
    csid = n;
    cid = m;
    if(csid != 0 && cid != 0){
        ui->pushButton->setText("Edit link");
    }
    else{
        ui->pushButton->setText("Add link");
    }
    displayScientists(scientists);
    displayComputers(computers);
}

addl::~addl(){
    delete ui;
}

void addl::displayComputers(std::vector<computer> computers){
    ui->tableWidget_1->clearContents();
    ui->tableWidget_1->setRowCount(computers.size());
    ui->tableWidget_1->verticalHeader()->show();
    ui->tableWidget_1->setColumnCount(2);
    ui->tableWidget_1->setColumnHidden(0, true);
    ui->tableWidget_1->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_1->setHorizontalHeaderLabels(QString(" ;Computer name").split(";"));

    for (unsigned int i = 0; i < computers.size(); i++){
        computer currentComputer = computers[i];

        QString id = QString::number(currentComputer.getId());
        QString name = currentComputer.getName();

        ui->tableWidget_1->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableWidget_1->setItem(i, 1, new QTableWidgetItem(name));
    }
}

void addl::displayScientists(std::vector<scientist> scientists){
    ui->tableWidget_2->clearContents();
    ui->tableWidget_2->setRowCount(scientists.size());
    ui->tableWidget_2->verticalHeader()->show();
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->setColumnHidden(0, true);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setHorizontalHeaderLabels(QString(" ;Scientist name").split(";"));

    for (unsigned int i = 0; i < scientists.size(); i++){
        scientist currentScientist = scientists[i];

        QString id = QString::number(currentScientist.getId());
        QString name = currentScientist.getName();

        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(name));
    }
}

void addl::on_pushButton_clicked(){
    QModelIndex currentIndexC = ui->tableWidget_1->currentIndex();
    int newCID = ui->tableWidget_1->item(currentIndexC.row(), 0)->text().toInt();
    QModelIndex currentIndexCS = ui->tableWidget_2->currentIndex();
    int newCSID = ui->tableWidget_2->item(currentIndexCS.row(), 0)->text().toInt();
    bool exist = s.isLink(newCSID, newCID);
    if(exist){
        ui->error->setText("<span style ='color: red'>This link already exist!</span>");
    }
    else{
        if(csid != 0 && cid != 0){
            s.editLink(newCSID, newCID, csid, cid);
            ui->error->hide();
            this->hide();
        }
        else{
            s.addLink(newCSID,newCID);
            ui->error->hide();
            this->hide();
        }
    }
}

void addl::on_tableWidget_2_clicked(const QModelIndex &index){
    cs_clicked = true;
    if(cs_clicked && c_clicked){
        ui->pushButton->setEnabled(true);
    }
}

void addl::on_tableWidget_1_clicked(const QModelIndex &index){
    c_clicked = true;
    if(cs_clicked && c_clicked){
        ui->pushButton->setEnabled(true);
    }
}
