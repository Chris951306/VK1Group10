#include "deletel.h"
#include "ui_deletel.h"

deletel::deletel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletel)
{
    ui->setupUi(this);

    service s;
    std::vector<link> links;
    s.getAllLinks(links);
    displayLinks(links);
}

deletel::~deletel()
{
    delete ui;
}

void deletel::displayLinks(std::vector<link> links){
    service s;
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(links.size());
    ui->tableWidget->verticalHeader()->show();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0, this->width()/2);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(QString("Scientist linked to ->;Computer").split(";"));

    vector<scientist> scientists;
    s.getAllScientists(scientists);
    vector<computer> computers;
    s.getAllComputers(computers);

    for (unsigned int i = 0; i < links.size(); i++){
        link currentLink = links[i];
        int csid = currentLink.returnCSID();
        int cid = currentLink.returnCID();
        scientist currentScientist = scientists[csid-1];
        computer currentComputer = computers[cid-1];
        QString csName = currentScientist.getName();
        QString cName = currentComputer.getName();

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(csName));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(cName));
    }
}


void deletel::on_pushButton_clicked(){
    service s;
    int maxl = s.countLinks();
    QString lInString = ui->lineEdit->text();
    int lid = lInString.toInt();
    if(lid > 0 && lid <= maxl){
        s.deleteLink(lid);
        this->hide();
    }
}
