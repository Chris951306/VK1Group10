#include "data.h"
#include "service.h"
#include "display.h"
#include "core.h"

void core::controller(vector<data> &cs){
    service s;
    display d;
    bool go = false;
    s.loadData(cs);
    do{
        go = false;
        char choice;
        cout << endl << "Enter a number for your choice. Any other inputs quit the program." << endl;
        cout << endl;
        cout << "1. Add scientist\t\t2. Edit scientist\n3. Display all scientists\t4. Delete scientist" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch(choice){
        case '1':
            s.addData(cs);
            s.saveData(cs);
            go = true;
            break;
        case '2':
            s.editData(cs);
            go = true;
            break;
        case '3':
            d.viewData(cs);
            go = true;
            break;
        case '4':
            s.deleteData(cs);
            go = true;
            break;
        }
    }while(go);
}

