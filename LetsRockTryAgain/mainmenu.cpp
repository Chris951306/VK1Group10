#include "mainmenu.h"
#include "ui_mainmenu.h"

void MainMenu::displayComputers(std::vector<computer> computers){
    ui->tableWidget->clearContents();
    for (unsigned int i = 0; i < computers.size(); i++){
        computer currentComputer = computers[i];

        QString name = currentComputer.getName();
        QString year = currentComputer.getYear();
        QString type = currentComputer.getType();
        QString built = currentComputer.getBuilt();

        ui->tableWidget->verticalHeader()->show();
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setColumnWidth(0, this->width()/3);
        ui->tableWidget->setColumnWidth(1, this->width()/5);
        ui->tableWidget->setColumnWidth(2, this->width()/5);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setHorizontalHeaderLabels(QString("Name;Build year;Type;Build status").split(";"));

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(year));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(type));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(built));
    }
}

void MainMenu::displayScientists(std::vector<scientist> scientists)
{
    ui->tableWidget->clearContents();
    for (unsigned int i = 0; i < scientists.size(); i++){
        scientist currentScientist = scientists[i];

        QString name = currentScientist.getName();
        QString gender = currentScientist.getGender();
        QString yob = currentScientist.getYob();
        QString yod = currentScientist.getYod();

        ui->tableWidget->verticalHeader()->show();
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setColumnWidth(0, this->width()/3);
        ui->tableWidget->setColumnWidth(1, this->width()/5);
        ui->tableWidget->setColumnWidth(2, this->width()/5);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setHorizontalHeaderLabels(QString("Name;Gender;Year of birth;Year of death").split(";"));

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(gender));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(yob));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(yod));
    }
}

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu){
    ui->setupUi(this);
    service s;
    s.start();
}

MainMenu::~MainMenu(){
    delete ui;
}

void MainMenu::on_pushAddButton_clicked(){
    if(ui->radioButton->isChecked()){
        AddCS cs;
        cs.setModal(true);
        cs.exec();
    }
    else if(ui->radioButton_2->isChecked()){
        AddC c;
        c.setModal(true);
        c.exec();
    }
}

void MainMenu::on_radioButton_toggled(bool checked){
    std::vector<scientist> scientists;
    s.getAllScientists(scientists);
    ui->tableWidget->setRowCount(scientists.size());
    ui->pushAddButton->setEnabled(true);
    ui->pushAddButton->setText("Add Scientist");
    ui->pushEditButton->setText("Edit Scientist");
    ui->searchDatabase->setEnabled(true);
    ui->searchDatabase->setPlaceholderText("Search for scientist...");

    if(checked){
        displayScientists(scientists);
    }
}

void MainMenu::on_radioButton_2_toggled(bool checked){
    std::vector<computer> computers;
    s.getAllComputers(computers);
    ui->tableWidget->setRowCount(computers.size());
    ui->pushAddButton->setEnabled(true);
    ui->pushAddButton->setText("Add Computer");
    ui->pushEditButton->setText("Edit Computer");
    ui->searchDatabase->setEnabled(true);
    ui->searchDatabase->setPlaceholderText("Search for computer...");

    if(checked){
        displayComputers(computers);
    }
}

void MainMenu::on_searchDatabase_textChanged(const QString &arg1){

    if(ui->radioButton->isChecked()){
        std::vector<scientist> scientists;
        if(arg1.trimmed() == ""){
            s.getAllScientists(scientists);
            displayScientists(scientists);
        }
        else{
            s.searchScientist(scientists, arg1);
            displayScientists(scientists);
        }
    }
    else if(ui->radioButton_2->isChecked()){
        std::vector<computer> computers;
        if(arg1.trimmed() == ""){
            s.getAllComputers(computers);
            displayComputers(computers);
        }
        else{
            s.searchComputer(computers, arg1);
            displayComputers(computers);
        }
    }
}
