#include "control.h"

void control::maincontrol(database &db){
    display d;
    service s;
    bool go = false;
    char choice, choice2, choice3;
    unsigned int val, csid, cid;
    db.onoff();
    cout << db.status() << endl;
    do{
        go = false;
        cout << "Enter a number for your choice. Any other input quits the program!" << endl << endl;
        cout << "1. Add to database\t\t2. Edit database" << endl;
        cout << "3. Display database\t\t4. Search in database"<< endl;
        cout << "Enter your choice: ";
        cin  >> choice;
        cout << endl;
        if(choice == '1'){
            cout << "1. Add scientist\t\t2. Add computer\n3. Add link" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                s.addScientist();
            }
            else if(choice2 == '2'){
                s.addComputer();
            }
            else if(choice2 == '3'){
                cout << "1. Link computers to scientist\t2. Link scientists to computer" << endl;
                cin >> choice3;
                cout << endl;
                if(choice3 == '1'){
                    string option;
                    d.printScientists();
                    cout << "Enter id of scientist to link: ";
                    cin >> option;
                    csid = s.selectUnit(option);
                    unsigned int maxId;
                    QSqlQuery query;
                    query.exec("SELECT MAX(id) FROM scientists");
                    query.next();
                    maxId = query.value("MAX(id)").toUInt();
                    if(s.isLetter(option) || csid == 0 || option[0] == 45 || csid > maxId){
                        cout << "Invalid id!" << endl;
                    }
                    else{
                        char again;
                        do{
                            d.printComputers();
                            cout << "Enter id of computer to link to this scientist:" << endl;
                            d.printScientist(csid);
                            cout << endl;
                            cin >> option;
                            cid = s.selectUnit(option);
                            QSqlQuery query;
                            query.exec("SELECT MAX(id) FROM computers");
                            query.next();
                            maxId = query.value("MAX(id)").toUInt();
                            if(s.isLetter(option) || cid == 0 || option[0] == 45 || cid > maxId){
                                cout << "Invalid id!" << endl;
                            }
                            else{
                                s.addLink(csid, cid);
                            }
                            cout << "Do you want to add another computer to this scientist(y/n): ";
                            cin >> again;
                        }while(again == 'Y' || again == 'y');
                    }

                }
                else if(choice3 == '2'){
                    string option;
                    d.printComputers();
                    cout << "Enter id of computer to link: ";
                    cin >> option;
                    cid = s.selectUnit(option);
                    unsigned int maxId;
                    QSqlQuery query;
                    query.exec("SELECT MAX(id) FROM computers");
                    query.next();
                    maxId = query.value("MAX(id)").toUInt();
                    if(s.isLetter(option) || cid == 0 || option[0] == 45 || cid > maxId){
                        cout << "Invalid id!" << endl;
                    }
                    else{
                        char again;
                        do{
                            d.printScientists();
                            cout << "Enter id of scientist to link to this computer:" << endl;
                            d.printComputer(cid);
                            cout << endl;
                            cin >> option;
                            csid = s.selectUnit(option);
                            QSqlQuery query;
                            query.exec("SELECT MAX(id) FROM scientists");
                            query.next();
                            maxId = query.value("MAX(id)").toUInt();
                            if(s.isLetter(option) || csid == 0 || option[0] == 45 || csid > maxId){
                                cout << "Invalid id!" << endl;
                            }
                            else{
                                s.addLink(csid, cid);
                            }
                            cout << "Do you want to add another scientist to this computer(y/n): ";
                            cin >> again;
                        }while(again == 'Y' || again == 'y');
                    }

                }

            }
            cout << endl;
            go = true;
        }
        else if(choice == '2'){
            cout << "1. Edit scientists \t\t 2. Edit computers" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if(choice2 == '1'){
                cout << endl;
                d.printScientists();
                string option;
                cout << "Enter scientist number to edit.\n(If input is not a listed number, you will be returned to menu): ";
                cin >> option;
                val = s.selectUnit(option);
                unsigned int maxId;
                QSqlQuery query;
                query.exec("SELECT MAX(id) FROM scientists");
                query.next();
                maxId = query.value("MAX(id)").toUInt();
                if(s.isLetter(option) || val == 0 || option[0] == 45 || val > maxId);
                else{
                    do{
                        go = false;
                        cout << endl;
                        d.printCStop();
                        d.printScientist(val);
                        cout << endl << endl;
                        go = s.editScientist(val);
                    }while(go);
                }
            }
            else if(choice2 == '2'){
                cout << endl;
                d.printComputers();
                string option;
                cout << "Enter computer number to edit.\n(If input is not a listed number, you will be returned to menu): ";
                cin >> option;
                val = s.selectUnit(option);
                unsigned int maxId;
                QSqlQuery query;
                query.exec("SELECT MAX(id) FROM computers");
                query.next();
                maxId = query.value("MAX(id)").toUInt();
                if(s.isLetter(option) || val == 0 || option[0] == 45 || val > maxId);
                else{
                    do{
                        go = false;
                        cout << endl;
                        d.printCtop();
                        d.printComputer(val);
                        cout << endl << endl;
                        go = s.editComputer(val);
                    }while(go);
                }
            }
            cout << endl;
            go = true;
        }
        else if(choice == '3'){
            cout << "1. Display scientists\t\t2. Display computers" << endl;
            cout << "3. CS connected to C\t\t4. C connected to CS" << endl;
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
                    go = d.sortScientist(namesort, gendersort, yobsort);
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
                    go = s.searchScientist(id);
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
                    go = s.searchComputer(id);
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
