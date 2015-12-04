#include "control.h"

void control::maincontrol(database &db){
    display d;
    bool go = false;
    db.onoff();
    cout << db.status() << endl;
    do{
        go = false;
        char choice;
        cin >> choice;
        switch(choice){
        case '1':
            d.printScientists();
            go = true;
            break;
        }
    }while(go);
}
