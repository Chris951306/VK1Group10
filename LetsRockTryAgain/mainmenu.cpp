#include "mainmenu.h"
#include "ui_mainmenu.h"

void MainMenu::displayComputers(std::vector<computer> computers){
    ui->tableWidget->clearContents();
    for(unsigned int i = 0; i < computers.size(); i++){
        computer currentComputer = computers[i];

        QString id = QString::number(currentComputer.getId());
        QString name = currentComputer.getName();
        QString year = currentComputer.getYear();
        QString type = currentComputer.getType();
        QString built = currentComputer.getBuilt();

        ui->tableWidget->verticalHeader()->show();
        ui->tableWidget->setColumnCount(5);
        ui->tableWidget->setColumnHidden(0, true);
        ui->tableWidget->setColumnWidth(1, this->width()/3);
        ui->tableWidget->setColumnWidth(2, this->width()/5);
        ui->tableWidget->setColumnWidth(3, this->width()/5);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setHorizontalHeaderLabels(QString(" ;Name;Build year;Type;Build status").split(";"));

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(year));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(type));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(built));
    }
}

void MainMenu::displayScientists(std::vector<scientist> scientists){
    ui->tableWidget->clearContents();
    for(unsigned int i = 0; i < scientists.size(); i++){
        scientist currentScientist = scientists[i];

        QString id = QString::number(currentScientist.getId());
        QString name = currentScientist.getName();
        QString gender = currentScientist.getGender();
        QString yob = currentScientist.getYob();
        QString yod = currentScientist.getYod();

        ui->tableWidget->verticalHeader()->show();
        ui->tableWidget->setColumnCount(5);
        ui->tableWidget->setColumnHidden(0, true);
        ui->tableWidget->setColumnWidth(1, this->width()/3);
        ui->tableWidget->setColumnWidth(2, this->width()/5);
        ui->tableWidget->setColumnWidth(3, this->width()/5);
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->setHorizontalHeaderLabels(QString(" ;Name;Gender;Year of birth;Year of death").split(";"));

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(gender));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(yob));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(yod));
    }
}

void MainMenu::displayLinks(std::vector<link> links){
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

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu){
    ui->setupUi(this);
    s.start();
}

MainMenu::~MainMenu(){
    delete ui;
}

void MainMenu::on_pushAddButton_clicked(){
    if(ui->radioButton->isChecked()){
        AddCS cs(0);
        cs.setModal(true);
        cs.exec();
    }
    else if(ui->radioButton_2->isChecked()){
        AddC c(0);
        c.setModal(true);
        c.exec();
    }
    else if(ui->radioButton_3->isChecked()){
        addl l;
        l.setModal(true);
        l.exec();
    }
}

void MainMenu::on_radioButton_toggled(bool checked){
    std::vector<scientist> scientists;
    s.getAllScientists(scientists);
    ui->tableWidget->setRowCount(scientists.size());
    ui->pushEditButton->setEnabled(false);
    ui->pushAddButton->setEnabled(true);
    ui->pushAddButton->setText("Add scientist");
    ui->pushEditButton->setText("Edit scientist");
    ui->pushDeleteButton->setText("Delete scientist");
    ui->pushDeleteButton->setEnabled(true);
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
    ui->pushEditButton->setEnabled(false);
    ui->pushAddButton->setText("Add computer");
    ui->pushEditButton->setText("Edit computer");
    ui->pushDeleteButton->setText("Delete computer");
    ui->pushDeleteButton->setEnabled(true);
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

void MainMenu::on_radioButton_3_toggled(bool checked){
    std::vector<link> links;
    s.getAllLinks(links);
    ui->pushAddButton->setEnabled(true);
    ui->pushAddButton->setText("Add Link");
    ui->pushEditButton->setText("Edit Link");
    ui->pushDeleteButton->setText("Delete Link");
    ui->pushDeleteButton->setEnabled(true);
    ui->searchDatabase->setEnabled(false);
    ui->searchDatabase->setPlaceholderText("Cannot search for links...");

    if(checked){
        displayLinks(links);
    }
}

void MainMenu::on_pushDeleteButton_clicked(){
    if(ui->radioButton->isChecked()){
        deletecs cs;
        cs.setModal(true);
        cs.exec();
    }
    else if(ui->radioButton_2->isChecked()){
        deletec c;
        c.setModal(true);
        c.exec();
    }
    else if(ui->radioButton_3->isChecked()){
        deletel l;
        l.setModal(true);
        l.exec();
    }
}

void MainMenu::on_pushEditButton_clicked(){
    if(ui->radioButton->isChecked()){
        QModelIndex currentIndex = ui->tableWidget->currentIndex();
        int id = ui->tableWidget->item(currentIndex.row(), 0)->text().toInt();
        AddCS cs(id);
        cs.setModal(true);
        cs.exec();
    }
    else if(ui->radioButton_2->isChecked()){
        QModelIndex currentIndex = ui->tableWidget->currentIndex();
        int id = ui->tableWidget->item(currentIndex.row(), 0)->text().toInt();
        AddC c(id);
        c.setModal(true);
        c.exec();
    }
}

void MainMenu::on_tableWidget_clicked(const QModelIndex &index){
    ui->pushEditButton->setEnabled(true);
}
