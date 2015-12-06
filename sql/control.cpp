#include "control.h"

void control::maincontrol(database &db){
    display d;
    service s;
    bool go = false;
    char choice;
    char choice2;
    db.onoff();
    cout << db.status() << endl;
    do{
        go = false;
        cout << "1. Add to database\t\t2. Edit database" << endl;
        cout << "3. Display database\t\tAny other will quit program"<< endl;
        cout << "Enter your choice: ";
        cin  >> choice;
        cout << endl;
        if(choice == '1'){
            cout << "1. Add scientists \t\t 2. Add computer" << endl;
            cout << "Any other will go to menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                s.addScientist();
            }
            else if(choice2 == '2'){
                s.addComputer();
            }
            cout << endl;
            go = true;
        }
        else if(choice == '2'){
            cout << "1. Edit scientists \t\t 2. Edit computer" << endl;
            cout << "Any other will go to menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                d.printScientists();
                string option;
                cout << "Enter scientist number to edit.\n(If input is not a listed number, you will be returned to menu): ";
                cin >> option;
                cout << endl;
                unsigned int val = s.selectUnit(option);
                unsigned int maxId;
                QSqlQuery query;
                query.exec("SELECT MAX(id) FROM scientists");
                query.next();
                maxId = query.value("MAX(id)").toUInt();
                if(s.isLetter(option) || val == 0 || option[0] == 45 || val > maxId);
                else{
                    do{
                        go = false;
                        d.printScientist(val);
                        cout << endl << endl;
                        go = s.editScientist(val);
                    }while(go);
                }
            }
            else if(choice2 == '2'){
                d.printComputers();
                string option;
                cout << "Enter computer number to edit.\n(If input is not a listed number, you will be returned to menu): ";
                cin >> option;
                cout << endl << endl;
                unsigned int val = s.selectUnit(option);
                if(s.isLetter(option) || val == 0 || option[0] == 45);
                else{
                    do{
                        go = false;
                        //d.printComputer(val);
                        //cout << endl << endl;
                        go = s.editComputer(val);
                    }while(go);
                }
            }
            cout << endl;
            go = true;
        }
        else if(choice == '3'){
            cout << "1. Display scientists \t\t 2. Display computer" << endl;
            cout << "Any other will go to menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                d.printScientists();
                do{
                    go = false;
                    go = d.sortScientist();
                }while(go);
            }
            else if(choice2 == '2'){
                 d.printComputers();
                 /*do{
                     go = false;
                     go = d.sortComputer();
                 }while(go);
                 */
            }
            cout << endl;
            go = true;
        }
    }while(go);
}
