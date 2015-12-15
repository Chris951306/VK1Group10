#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMessageBox>


void MainMenu::displayComputers(std::vector<computer> computers){
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setRowCount(computers.size());
    ui->tableWidget->verticalHeader()->show();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnHidden(0, true);
    ui->tableWidget->setColumnWidth(1, this->width()/3);
    ui->tableWidget->setColumnHidden(2, false);
    ui->tableWidget->setColumnWidth(2, this->width()/5);
    ui->tableWidget->setColumnWidth(3, this->width()/5);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(QString(" ;Name;Build year;Type;Build status").split(";"));

    for(unsigned int i = 0; i < computers.size(); i++){
        computer currentComputer = computers[i];

        QString id = QString::number(currentComputer.getId());
        QString name = currentComputer.getName();
        QString year = currentComputer.getYear();
        QString type = currentComputer.getType();
        QString built = currentComputer.getBuilt();

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(year));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(type));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(built));
    }
    ui->tableWidget->setSortingEnabled(true);
}

void MainMenu::displayScientists(std::vector<scientist> scientists){
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setRowCount(scientists.size());
    ui->tableWidget->verticalHeader()->show();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnHidden(0, true);
    ui->tableWidget->setColumnWidth(1, this->width()/3);
    ui->tableWidget->setColumnHidden(2, false);
    ui->tableWidget->setColumnWidth(2, this->width()/5);
    ui->tableWidget->setColumnWidth(3, this->width()/5);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(QString(" ;Name;Gender;Year of birth;Year of death").split(";"));

    for(unsigned int i = 0; i < scientists.size(); i++){
        scientist currentScientist = scientists[i];

        QString id = QString::number(currentScientist.getId());
        QString name = currentScientist.getName();
        QString gender = currentScientist.getGender();
        QString yob = currentScientist.getYob();
        QString yod = currentScientist.getYod();

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(id));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(gender));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(yob));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(yod));
    }
    ui->tableWidget->setSortingEnabled(true);
}

void MainMenu::displayLinks(std::vector<link> links){
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setRowCount(links.size());
    ui->tableWidget->verticalHeader()->show();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setColumnHidden(0, true);
    ui->tableWidget->setColumnWidth(1, this->width()/2);
    ui->tableWidget->setColumnHidden(2, true);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels(QString(" ;Scientist linked to ->; ;Computer").split(";"));

    for(unsigned int i = 0; i < links.size(); i++){
        link currentLink = links[i];
        int csid = currentLink.returnCSID();
        int cid = currentLink.returnCID();
        QString csID = QString::number(csid);
        QString csName = s.getCSName(csid);
        QString cID = QString::number(cid);
        QString cName = s.getCName(cid);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(csID));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(csName));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(cID));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(cName));
    }
    ui->tableWidget->setSortingEnabled(true);
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
        cs.setWindowTitle("Add scientist");
        cs.exec();
    }
    else if(ui->radioButton_2->isChecked()){
        AddC c(0);
        c.setModal(true);
        c.setWindowTitle("Add computer");
        c.exec();
    }
    else if(ui->radioButton_3->isChecked()){
        addl l(0, 0);
        l.setModal(true);
        l.setWindowTitle("Add link");
        l.exec();
    }
}

void MainMenu::on_radioButton_toggled(bool checked){
    if(checked){
        ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
        ui->tableWidget->clearContents();
        std::vector<scientist> scientists;
        s.getAllScientists(scientists);
        ui->pushEditButton->setEnabled(false);
        ui->pushAddButton->setEnabled(true);
        ui->pushAddButton->setText("Add scientist");
        ui->pushEditButton->setText("Edit scientist");
        ui->pushDeleteButton->setText("Delete scientist");
        ui->pushDeleteButton->setEnabled(false);
        ui->searchDatabase->setEnabled(true);
        ui->searchDatabase->setPlaceholderText("Search for scientist...");
        displayScientists(scientists);
    }
}

void MainMenu::on_radioButton_2_toggled(bool checked){
    if(checked){
        ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
        ui->tableWidget->clearContents();
        std::vector<computer> computers;
        s.getAllComputers(computers);
        ui->pushAddButton->setEnabled(true);
        ui->pushEditButton->setEnabled(false);
        ui->pushAddButton->setText("Add computer");
        ui->pushEditButton->setText("Edit computer");
        ui->pushDeleteButton->setText("Delete computer");
        ui->pushDeleteButton->setEnabled(false);
        ui->searchDatabase->setEnabled(true);
        ui->searchDatabase->setPlaceholderText("Search for computer...");
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
    if(checked){
        ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
        ui->tableWidget->clearContents();
        std::vector<link> links;
        s.getAllLinks(links);
        ui->pushAddButton->setEnabled(true);
        ui->pushAddButton->setText("Add Link");
        ui->pushEditButton->setText("Edit Link");
        ui->pushDeleteButton->setText("Delete Link");
        ui->pushDeleteButton->setEnabled(false);
        ui->searchDatabase->setEnabled(false);
        ui->searchDatabase->setText("");
        ui->searchDatabase->setPlaceholderText("Cannot search for links...");
        displayLinks(links);
    }
}

void MainMenu::on_pushDeleteButton_clicked(){
    if(ui->radioButton->isChecked()){
        QModelIndex currentIndex = ui->tableWidget->currentIndex();
        int id = ui->tableWidget->item(currentIndex.row(), 0)->text().toInt();
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
        if (answer != QMessageBox::No){
            s.deleteScientist(id);
        }
    }
    else if(ui->radioButton_2->isChecked()){
        QModelIndex currentIndex = ui->tableWidget->currentIndex();
        int id = ui->tableWidget->item(currentIndex.row(), 0)->text().toInt();
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
        if (answer != QMessageBox::No){
            s.deleteComputer(id);
        }
    }
    else if(ui->radioButton_3->isChecked()){
        QModelIndex currentIndex = ui->tableWidget->currentIndex();
        int csid = ui->tableWidget->item(currentIndex.row(), 0)->text().toInt();
        int cid = ui->tableWidget->item(currentIndex.row(), 2)->text().toInt();
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
        if (answer != QMessageBox::No){
            s.deleteLink(csid, cid);
        }
    }
}

void MainMenu::on_pushEditButton_clicked(){
    if(ui->radioButton->isChecked()){
        QModelIndex currentIndex = ui->tableWidget->currentIndex();
        int id = ui->tableWidget->item(currentIndex.row(), 0)->text().toInt();
        AddCS cs(id);
        cs.setModal(true);
        cs.setWindowTitle("Edit scientist");
        cs.exec();
    }
    else if(ui->radioButton_2->isChecked()){
        QModelIndex currentIndex = ui->tableWidget->currentIndex();
        int id = ui->tableWidget->item(currentIndex.row(), 0)->text().toInt();
        AddC c(id);
        c.setModal(true);
        c.setWindowTitle("Edit computer");
        c.exec();
    }
    else if(ui->radioButton_3->isChecked()){
        QModelIndex currentIndex = ui->tableWidget->currentIndex();
        int csid = ui->tableWidget->item(currentIndex.row(), 0)->text().toInt();
        int cid = ui->tableWidget->item(currentIndex.row(), 2)->text().toInt();
        addl l(csid, cid);
        l.setModal(true);
        l.setWindowTitle("Edit link");
        l.exec();
    }

}

void MainMenu::on_tableWidget_clicked(const QModelIndex &index){
    ui->pushEditButton->setEnabled(true);
    ui->pushDeleteButton->setEnabled(true);
}

void MainMenu::on_button_snoop_clicked(){
    snoop dogg;
    dogg.setModal(true);
    dogg.exec();
}

void MainMenu::on_refreshButton_clicked(){
    if(ui->radioButton->isChecked()){
        std::vector<scientist> scientists;
        s.getAllScientists(scientists);
        displayScientists(scientists);
    }
    else if(ui->radioButton_2->isChecked()){
        std::vector<computer> computers;
        s.getAllComputers(computers);
        displayComputers(computers);
    }
    else if(ui->radioButton_3->isChecked()){
        std::vector<link> links;
        s.getAllLinks(links);
        displayLinks(links);
    }
}
