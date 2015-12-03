#include "core.h"

void core::controller(vector<scientists> &cs, vector<computers> &c){
    service s;
    display d;
    bool go = false;
    s.loadData(cs);
    do{
        go = false;
        char choice;
        cout << endl << "Enter a number for your choice. Any other inputs quit the program." << endl;
        cout << endl;
        cout << "1. Add unit\t\t\t2. Edit unit\n3. Display all units\t\t4. Delete unit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch(choice){
        case '1':
            cout << "1. Add scientist\t\t2. Add computer" << endl;
            cout << "Your choice: ";
            cin >> choice;
            if(choice == '1')
                s.addScientist(cs);
            else if(choice == '2')
                s.addComputer(c);
            s.saveData(cs);
            go = true;
            break;
        case '2':
            s.editScientist(cs);
            go = true;
            break;
        case '3':
            cout << "1. View scientists\t\t2. View computers\n3. View combination" << endl;
            cout << "Your choice: ";
            cin >> choice;
            if(choice == '1')
                d.viewScientists(cs);
            else if(choice == '2')
                cout << "TEST" << endl;
            else if(choice == '3')
                d.viewCombination(cs, c);
            go = true;
            break;
        case '4':
            s.deleteScientist(cs);
            go = true;
            break;
        }
    }while(go);
}

