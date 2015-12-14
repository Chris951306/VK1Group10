#include "deletec.h"
#include "ui_deletec.h"

deletec::deletec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletec)
{
    ui->setupUi(this);

    service s;
    std::vector<computer> computers;
    s.getAllComputers(computers);
    displayComputers(computers);
}

deletec::~deletec()
{
    delete ui;
}

void deletec::displayComputers(std::vector<computer> computers){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(computers.size());
    ui->tableWidget->verticalHeader()->show();
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(QString("Computer name").split(";"));

    for (unsigned int i = 0; i < computers.size(); i++){
        computer currentComputer = computers[i];

        QString name = currentComputer.getName();

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(name));
    }
}

void deletec::on_pushButton_clicked(){
    service s;
    int maxc = s.countComputers();
    QString cidInString = ui->lineEdit->text();
    int cid = cidInString.toInt();
    if(cid > 0 && cid <= maxc){
        //DELETE DO LATER;
        this->hide();
    }
}
