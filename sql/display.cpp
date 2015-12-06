#include "display.h"

void display::printScientists(){
    cout << setfill(' ') << setw(4) << "#" << left << setw(2) << "" << left << setw(25) << "Name" << left << setw(12) << "Gender";
    cout << setfill(' ') << left << setw(14) << "Birth" << left << "Death" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(63) << "" << endl;
    QSqlQuery query;
    query.exec("SELECT * FROM scientists");
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        bool gender = query.value("gender").toBool();
        int yob = query.value("yob").toInt();
        int yod = query.value("yod").toInt();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(25) << name;
        if(gender)
            cout << left << setw(12) << "Male";
        else
            cout << left << setw(12) << "Female";
        if(yob < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yob) << " B.C. --> ";
        }
        else{
            cout << right << setfill('0') << setw(4) << yob << " A.D. --> ";
        }

        if(yod == STILLALIVE){
            cout << "Alive";
        }
        else if(yod < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yod) << " B.C.";
        }
        else{
            cout << right << setfill('0') << setw(4) << yod << " A.D.";
        }
        cout << endl << endl;
    }
}

void display::printScientist(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT * FROM scientists WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        bool gender = query.value("gender").toBool();
        int yob = query.value("yob").toInt();
        int yod = query.value("yod").toInt();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(25) << name;
        if(gender)
            cout << left << setw(12) << "Male";
        else
            cout << left << setw(12) << "Female";
        if(yob < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yob) << " B.C. --> ";
        }
        else{
            cout << right << setfill('0') << setw(4) << yob << " A.D. --> ";
        }

        if(yod == STILLALIVE){
            cout << "Alive";
        }
        else if(yod < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yod) << " B.C.";
        }
        else{
            cout << right << setfill('0') << setw(4) << yod << " A.D.";
        }
    }
}

bool display::sortScientist(){
    QSqlQuery query;
    char choice;
    cout << "1. Sort by name\t\t2. Sort by gender\t3. Sort by year of birth" << endl;
    cout << "Enter choice: ";
    cin  >> choice;

    if(choice == '1'){
        query.exec("SELECT * FROM scientists ORDER BY name");
        query.exec();
    }
    else if(choice == '2'){
        query.exec("SELECT * FROM scientists ORDER BY gender");
        query.exec();
    }
    else if(choice == '3'){
        query.exec("SELECT * FROM scientists ORDER BY yob");
        query.exec();
    }
    else{
        cout << "Invalid input!" << endl;
        return false;
    }
    cout << setfill(' ') << setw(4) << "#" << left << setw(2) << "" << left << setw(25) << "Name" << left << setw(12) << "Gender";
    cout << setfill(' ') << left << setw(14) << "Birth" << left << "Death" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(63) << "" << endl;
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        bool gender = query.value("gender").toBool();
        int yob = query.value("yob").toInt();
        int yod = query.value("yod").toInt();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(25) << name;
        if(gender)
            cout << left << setw(12) << "Male";
        else
            cout << left << setw(12) << "Female";
        if(yob < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yob) << " B.C. --> ";
        }
        else{
            cout << right << setfill('0') << setw(4) << yob << " A.D. --> ";
        }

        if(yod == STILLALIVE){
            cout << "Alive";
        }
        else if(yod < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yod) << " B.C.";
        }
        else{
            cout << right << setfill('0') << setw(4) << yod << " A.D.";
        }
        cout << endl << endl;
    }
    return true;
}

void display::printComputers(){
    cout << setfill(' ') << setw(4) << "#" << left << setw(2) << "" << left << setw(30) << "Name" << left << setw(12) << "Year";
    cout << setfill(' ') << left << setw(18) << "Type" << left << "Build status" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(75) << "" << endl;
    QSqlQuery query;
    query.exec("SELECT * FROM computers");
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int year = query.value("year").toInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(30) << name;
        if(year < 0)
        {
            cout << left << setfill('0') << setw(4) << abs(year) << setfill(' ') << setw(8) << " B.C.";
        }
        else{
            cout << left << setfill('0') << setw(4) << year << setfill(' ') << setw(8) << " A.D.";
        }
        cout << left << setfill(' ') << setw(18) << type;
        if(built)
            cout << left << setw(9) << "Built";
        else
            cout << left << setw(9) << "Not built";

        cout << endl << endl;
    }
}

void display::printComputer(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT * FROM computers WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int year = query.value("year").toInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(30) << name;
        if(year < 0)
        {
            cout << left << setfill('0') << setw(4) << abs(year) << setfill(' ') << setw(8) << " B.C.";
        }
        else{
            cout << left << setfill('0') << setw(4) << year << setfill(' ') << setw(8) << " A.D.";
        }
        cout << left << setfill(' ') << setw(18) << type;
        if(built)
            cout << left << setw(9) << "Built";
        else
            cout << left << setw(9) << "Not built";
    }
}

bool display::sortComputers(){
    QSqlQuery query;
    char choice;
    cout << "1. Sort by name\t\t2. Sort by year\n3. Sort by type\t\t4. Sort by built or not" << endl;
    cout << "Enter choice: ";
    cin  >> choice;

    if(choice == '1'){
        query.exec("SELECT * FROM computers ORDER BY name");
        query.exec();
    }
    else if(choice == '2'){
        query.exec("SELECT * FROM computers ORDER BY year");
        query.exec();
    }
    else if(choice == '3'){
        query.exec("SELECT * FROM computers ORDER BY type");
        query.exec();
    }
    else if(choice == '4'){
        query.exec("SELECT * FROM computers ORDER BY built DESC");
        query.exec();
    }
    else{
        cout << "Invalid input!" << endl;
        return false;
    }
    cout << setfill(' ') << setw(4) << "#" << left << setw(2) << "" << left << setw(30) << "Name" << left << setw(12) << "Year";
    cout << setfill(' ') << left << setw(18) << "Type" << left << "Build status" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(75) << "" << endl;
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int year = query.value("year").toInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(30) << name;
        if(year < 0)
        {
            cout << left << setfill('0') << setw(4) << abs(year) << setfill(' ') << setw(8) << " B.C.";
        }
        else{
            cout << left << setfill('0') << setw(4) << year << setfill(' ') << setw(8) << " A.D.";
        }
        cout << left << setfill(' ') << setw(18) << type;
        if(built)
            cout << left << setw(9) << "Built";
        else
            cout << left << setw(9) << "Not built";

        cout << endl << endl;
    }
    return true;
}
