#include "control.h"

void control::maincontrol(database &db){
    display d;
    service s;
    bool go = false;
    char choice;
    db.onoff();
    cout << db.status() << endl;
    do{
        go = false;
        cout << "Hello my friend." << endl;
        cout << "So what do you wana do?" << endl;
        cout << "1. Display scientists \t\t 2. Add scientists" << endl;
        cout << "3. Edit scientists \t\t Any other will quit" << endl;
        cout << "Enter your choice plz: ";
        cin  >> choice;
        switch(choice){
        case '1':
            d.printScientists();
            do{
                go = false;
                go = d.sortScientist();
            }while(go);
            go = true;
            break;
        case '2':
            s.addScientist();
            go = true;
            break;
        case '3':
            d.printScientists();
            string option;
            cout << "Enter scientist number to edit.\n(If input is not a listed number, you will be returned to menu): ";
            cin >> option;
            cout << endl << endl;
            unsigned int val = s.selectUnit(option);
            if(s.isLetter(option) || val == 0);
            else{
                do{
                    go = false;
                    d.printScientist(val);
                    cout << endl << endl;
                    go = s.editScientist(val);
                }while(go);
            }
            go = true;
            break;
        }
    }while(go);
}
