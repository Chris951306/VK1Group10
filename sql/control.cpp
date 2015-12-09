#include "control.h"

//Main control function - lets user choose between different functions
void control::maincontrol(){
    display d;
    bool go = false;
    char choice, choice2, choice3;
    unsigned int val, csid, cid;
    do{
        go = false;
        cout << "Enter a number for your choice. Any other input quits the program!" << endl;
        cout << "Throughout the program, options that are not listed will return you to menu!" << endl << endl;
        cout << "1. Add to database\t\t2. Edit database" << endl;
        cout    << "3. Display database\t\t4. Search in database"<< endl;
        cout << "Enter your choice: ";
        cin  >> choice;
        cout << endl;
        if(choice == '1'){
            cout << "1. Add scientist\t\t2. Add computer\n3. Add link" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                d.addScientist();
            }
            else if(choice2 == '2'){
                d.addComputer();
            }
            else if(choice2 == '3'){
                cout << endl;
                cout << "1. Link computers to scientist\t2. Link scientists to computer" << endl;
                cout << "Enter choice: ";
                cin >> choice3;
                cout << endl;
                if(choice3 == '1'){
                    service s;
                    string option;
                    d.printScientists();
                    cout << "Enter id of scientist to link: ";
                    cin >> option;
                    cout << endl;
                    csid = d.selectUnit(option);
                    unsigned int maxId = s.maxCSid();
                    if(d.isLetter(option) || csid == 0 || option[0] == 45 || csid > maxId){
                        cout << "Invalid id!" << endl;
                    }
                    else{
                        char again;
                        do{
                            d.printComputers();
                            cout << "Enter id of computer to link to this scientist:" << endl << endl;
                            d.printCStop();
                            d.printScientist(csid);
                            cout << endl << endl;
                            cout << "Enter choice: ";
                            cin >> option;
                            cid = d.selectUnit(option);
                            maxId = s.maxCid();
                            if(d.isLetter(option) || cid == 0 || option[0] == 45 || cid > maxId){
                                cout << "Invalid id!" << endl;
                            }
                            else{
                                d.addLink(csid, cid);
                            }
                            cout << endl << "Do you want to add another computer to this scientist(y/n): ";
                            cin >> again;
                        }while(again == 'Y' || again == 'y');
                    }
                }
                else if(choice3 == '2'){
                    service s;
                    string option;
                    d.printComputers();
                    cout << "Enter id of computer to link: ";
                    cin >> option;
                    cid = d.selectUnit(option);
                    unsigned int maxId = s.maxCid();
                    if(d.isLetter(option) || cid == 0 || option[0] == 45 || cid > maxId){
                        cout << "Invalid id!" << endl;
                    }
                    else{
                        char again;
                        do{
                            d.printScientists();
                            cout << "Enter id of scientist to link to this computer:" << endl << endl;
                            d.printCtop();
                            d.printComputer(cid);
                            cout << endl << endl;
                            cout << "Enter choice: ";
                            cin >> option;
                            csid = d.selectUnit(option);
                            maxId = s.maxCSid();
                            if(d.isLetter(option) || csid == 0 || option[0] == 45 || csid > maxId){
                                cout << "Invalid id!" << endl;
                            }
                            else{
                                d.addLink(csid, cid);
                            }
                            cout << endl << "Do you want to add another scientist to this computer(y/n): ";
                            cin >> again;
                        }while(again == 'Y' || again == 'y');
                    }
                }
            }
            cout << endl;
            go = true;
        }
        else if(choice == '2'){
            service s;
            cout << "1. Edit scientists \t\t2. Edit computers\n3. Edit link" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                cout << endl;
                d.printScientists();
                string option;
                cout << "Enter scientist number to edit.\n(If input is not a listed number, you will be returned to menu): ";
                cin >> option;
                val = d.selectUnit(option);
                unsigned int maxId = s.maxCSid();
                if(d.isLetter(option) || val == 0 || option[0] == 45 || val > maxId);
                else{
                    do{
                        go = false;
                        cout << endl;
                        d.printCStop();
                        d.printScientist(val);
                        cout << endl << endl;
                        go = d.editScientist(val);
                    }while(go);
                }
            }
            else if(choice2 == '2'){
                service s;
                cout << endl;
                d.printComputers();
                string option;
                cout << "Enter computer number to edit.\n(If input is not a listed number, you will be returned to menu): ";
                cin >> option;
                val = d.selectUnit(option);
                unsigned int maxId = s.maxCid();
                if(d.isLetter(option) || val == 0 || option[0] == 45 || val > maxId);
                else{
                    do{
                        go = false;
                        cout << endl;
                        d.printCtop();
                        d.printComputer(val);
                        cout << endl << endl;
                        go = d.editComputer(val);
                    }while(go);
                }
            }
            else if(choice2 == '3'){
                d.editLink();
            }
            cout << endl;
            go = true;
        }
        else if(choice == '3'){
            cout << "1. Display scientists\t\t2. Display computers" << endl;
            cout << "3. Scientist --> Computer\t4. Computer --> Scientist" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                cout << endl;
                d.printScientists();
                bool namesort = false;
                bool gendersort = false;
                bool yobsort = false;
                do{
                    go = false;
                    go = d.sortScientists(namesort, gendersort, yobsort);
                }while(go);
            }
            else if(choice2 == '2'){
                cout << endl;
                d.printComputers();
                bool namesort = false;
                bool yearsort = false;
                bool typesort = false;
                bool builtsort = false;
                do{
                    go = false;
                    go = d.sortComputers(namesort, yearsort, typesort, builtsort);
                }while(go);
            }
            else if(choice2 == '3'){
                d.printCStoC();
            }
            else if(choice2 == '4'){
                d.printCtoCS();
            }
            cout << endl;
            go = true;
        }
        else if(choice == '4'){
            vector<int> id;
            cout << "1. Search for scientist\t\t2. Search for computer" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                do{
                    go = false;
                    cout << endl;
                    go = d.searchScientists(id);
                    if(go){
                        cout << endl;
                        d.printCStop();
                        for(unsigned int i = 0; i < id.size(); i++){
                            d.printScientist(id[i]);
                            cout << endl;
                        }
                    }
                    id.erase(id.begin(), id.end());
                }while(go);
            }
            else if(choice2 == '2'){
                do{
                    go = false;
                    cout << endl;
                    go = d.searchComputers(id);
                    if(go){
                        cout << endl;
                        d.printCtop();
                        for(unsigned int i = 0; i < id.size(); i++){
                            d.printComputer(id[i]);
                            cout << endl;
                        }
                    }
                    id.erase(id.begin(), id.end());
                }while(go);
            }
            cout << endl;
            go = true;
        }
    }while(go);
}
