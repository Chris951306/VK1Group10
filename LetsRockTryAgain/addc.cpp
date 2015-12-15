#include "addc.h"
#include "ui_addc.h"

AddC::AddC(int n, QWidget *parent) : QDialog(parent), ui(new Ui::AddC){
    ui->setupUi(this);
    setMaxYear();
    id = n;
    if(id != 0){
        ui->button_c_add->setText("Edit computer");
        std::vector<computer> computers;
        s.getAllComputers(computers);
        for(unsigned int i = 0; i < computers.size(); i++){
            if(n == computers[i].getId()){
                ui->input_c_name->setText(computers[i].getName());
                ui->input_c_year->setValue(computers[i].getYear().toInt());
                ui->input_c_type->setCurrentText(computers[i].getType());
                ui->input_c_build->setCurrentText(computers[i].getBuilt());
                }
            }
        }
    else{
        ui->button_c_add->setText("Add computer");
    }
}

AddC::~AddC(){
    delete ui;
}

void AddC::setMaxYear(){
    QDate today = QDate::currentDate();
    int year = today.year();
    ui->input_c_year->setMaximum(year);
}

bool AddC::checkName(QString &name){
    if(name.isEmpty()){// If the input string is empy, user is told to input at least(!) something
        ui->error_c_name->setText("<span style ='color: red'>Input a name!</span>");
        return false;
    }
    for(int i = 0; i < name.size(); i++){
        if((name[i].isLower() && i == 0) || (name[i].isLower() && name[i-1] == ' ')){// If first charachter is lower or first character after a space is lower, change the letter to capital
            name[i] = name[i].toUpper();
        }
        else if((name[i] == ' ' && name[i+1] == ' ') || (name[i] == ' ' && i == 0)){// If there are two spaces after each other or the string begins with one or more spaces, remove a space
            name.remove(i, 1);
            i--;
        }
        else if(!name[i].isLetterOrNumber() && name[i] != '\'' && name[i] != ',' && name[i] != '.' && name[i] != '-' && name[i] != ' '){// If the current character is not a letter nor a number or any of the legal symbols, make user input a new, valid, string
            ui->error_c_name->setText("<span style ='color: red'>Name contains invalid symbols!</span>");
            return false;
        }
    }
    ui->error_c_name->setText("");
    return true;
}
void AddC::on_button_c_add_clicked(){
    if(id != 0){
        bool ok1 = false;
        bool ok2 = true;
        bool ok3 = false;
        QString name = ui->input_c_name->text();
        ok1 = checkName(name);
        QString year = QString::number(ui->input_c_year->value());
        QString type = ui->input_c_type->currentText();
        if(type.isEmpty()){
            ui->error_c_type->setText("<span style ='color: red'>Choose a type!</span>");
            ok2 = false;
        }
        else{
            ui->error_c_type->setText("");
            ok2 = true;
        }
        QString build = ui->input_c_build->currentText();
        if(build.isEmpty()){
            ui->error_c_build->setText("<span style ='color: red'>Choose a build status!</span>");
            ok3 = false;
        }
        else{
            ui->error_c_build->setText("");
            ok3 = true;
        }

        if(ok1 && ok2 && ok3){
            computer temp(id, name, year, type, build);
            s.editComputer(temp);
            qDebug() << "Computer edited!";
            this->hide();
        }
    }
    else{
        bool ok1 = false;
        bool ok2 = true;
        bool ok3 = false;
        QString name = ui->input_c_name->text();
        ok1 = checkName(name);
        QString year = QString::number(ui->input_c_year->value());
        QString type = ui->input_c_type->currentText();
        if(type.isEmpty()){
            ui->error_c_type->setText("<span style ='color: red'>Choose a type!</span>");
            ok2 = false;
        }
        else{
            ui->error_c_type->setText("");
            ok2 = true;
        }
        QString build = ui->input_c_build->currentText();
        if(build.isEmpty()){
            ui->error_c_build->setText("<span style ='color: red'>Choose a build status!</span>");
            ok3 = false;
        }
        else{
            ui->error_c_build->setText("");
            ok3 = true;
        }

        if(ok1 && ok2 && ok3){
            computer temp(-1, name, year, type, build);
            s.addComputer(temp);
            qDebug() << "Computer added!";
            this->hide();
        }
    }
}
