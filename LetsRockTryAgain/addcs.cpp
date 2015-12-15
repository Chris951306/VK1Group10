#include "addcs.h"
#include "ui_addcs.h"

//Default constructor for class. Takes an optional id for edit
AddCS::AddCS(int n, QWidget *parent) : QDialog(parent), ui(new Ui::AddCS){
    ui->setupUi(this);
    setMaxYear();
    id = n;
    if(id != 0){ //If id is not 0, we fill the fields with current selection
        ui->button_cs_add->setText("Edit scientist");
        std::vector<scientist> scientists;
        s.getAllScientists(scientists);
        for(unsigned int i = 0; i < scientists.size(); i++){
            if(n == scientists[i].getId()){
                ui->input_cs_name->setText(scientists[i].getName());
                ui->input_cs_gender->setCurrentText(scientists[i].getGender());
                ui->input_cs_yob->setValue(scientists[i].getYob().toInt());
                if(scientists[i].getYod() == "Alive"){
                    ui->input_cs_alive->setChecked(true);
                }
                else{
                    ui->input_cs_yod->setValue(scientists[i].getYod().toInt());
                }
            }
        }
    }
    else{
        ui->button_cs_add->setText("Add scientist");
    }
}

//Default destructor for class
AddCS::~AddCS(){
delete ui;
}

//Sets the maximum year for birth- and death-input equal to current year
void AddCS::setMaxYear(){
    QDate today = QDate::currentDate();
    int year = today.year();
    ui->input_cs_yob->setMaximum(year);
    ui->input_cs_yod->setMaximum(year);
}

//Checks the name-input for errors and formats it accorded to set standard
bool AddCS::checkName(QString &name){
    if(name.isEmpty()){// If the input string is empy, user is told to input at least(!) something
        ui->error_cs_name->setText("<span style ='color: red'>Input a name!</span>");
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
            ui->error_cs_name->setText("<span style ='color: red'>Name contains invalid symbols!</span>");
            return false;
        }
    }
    ui->error_cs_name->setText("");
    return true;
}

//Signal to check if 'still alive' checkbox is toggled
void AddCS::on_input_cs_alive_toggled(bool checked){
    if(checked){
        ui->input_cs_yod->setEnabled(false);
    }
    else{
        ui->input_cs_yod->setEnabled(true);
    }
}

//Signal for add/edit button to be clicked
void AddCS::on_button_cs_add_clicked(){
    bool ok1 = false; //Name-check
    bool ok2 = true; //Gender-check
    bool ok3 = false; //Death-check
    QString name = ui->input_cs_name->text();
    ok1 = checkName(name);
    QString gender = ui->input_cs_gender->currentText();
    if(gender.isEmpty()){
        ui->error_cs_gender->setText("<span style ='color: red'>Choose a gender!</span>");
        ok2 = false;
    }
    else{
        ui->error_cs_gender->setText("");
        ok2 = true;
    }
    QString yob = QString::number(ui->input_cs_yob->value());
    QString yod = QString::number(ui->input_cs_yod->value());
    if(ui->input_cs_alive->isChecked()){
        yod = "Alive";
        ui->error_cs_yod->setText("");
        ok3 = true;
    }
    else{
        if(ui->input_cs_yob->value() > ui->input_cs_yod->value()){
            ui->error_cs_yod->setText("<span style ='color: red'>Can't be dead before date of birth!</span>");
            ok3 = false;
        }
        else{
            ui->error_cs_yod->setText("");
            ok3 = true;
        }
    }
    if(ok1 && ok2 && ok3){
        if(id != 0){
            scientist temp(id, name, gender, yob, yod);
            s.editScientist(temp);
            qDebug() << "Scientist edited!";
        }
        else{
            //Sets the value to -1 as a placeholder. Value is not used by addScientist
            scientist temp(-1, name, gender, yob, yod);
            s.addScientist(temp);
            qDebug() << "Scientist added!";
        }
        this->hide();
    }
}
