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

        if(yod == StillAlive){
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
