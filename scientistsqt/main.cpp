#include <QCoreApplication>
#include "scientist.h"

void core(vector<scientist> &s);
void logo();

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    vector<scientist> s;

    logo();

    loadInfo(s);

    core(s);

    return a.exec();
}

void core(vector<scientist> &s){
    bool go = false;
    do{
        go = false;
        char choice;
        cout << endl << "Enter a number for your choice. Any other inputs quit the program." << endl;
        cout << endl;
        cout << "1. Add scientist\t\t2. Edit scientist\n3. Display all scientists\t4. Delete scientist" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if(choice == '1'){
            scientist temp;
            cout << endl;
            temp.readInfo();
            s.push_back(temp);
            saveInfo(s);
            cout << endl;
            cout << "!Scientist saved to database!" << endl;
            go = true;
        }
        else if(choice == '2'){
            bool check = false;
            string in;
            int choice;
            cout << "Enter name to search for(Searches are case sensitive): ";
            cin >> in;
            for(unsigned int i = 0; i < s.size(); i++){
                if(in == retName(s[i]))
                {
                    choice = i;
                    check = true;
                }
            }
            if(check){
                cout << endl;
                s[choice].editInfo();
                saveInfo(s);
            }
            else{
                cout << endl << "No such scientist!" << endl;
            }
            go = true;
        }
        else if(choice == '3')
        {
            cout << endl;
            viewInfo(s);
            go = true;
        }
        else if(choice == '4')
        {
            cout << endl;
            delInfo(s);
            saveInfo(s);
            go = true;
        }
    }while(go);
}

void logo(){    // This is our awesome logo!!! It might not look like it, but we had to work around the escape
    char i = 92;// sequence, so we just made a char with the ascii value of \.
    cout << "  ________                          ___________    " << endl;
    cout << " /  _____/______  ____  __ ________/_   " << i << "   _  " << i << "   " << endl;
    cout << "/   " << i << "  __" << i << "_  __ " << i << "/  _ " << i << "|  |  " << i << "____ "
         << i << "|   /  /_" << i << "  " << i << "  " << endl;
    cout << i << "    " << i << "_" << i << "  " << i << "  | " << i
         << "(  <_> )  |  /  |_> >   " << i << "  " << i << "_/   " << i << " " << endl;
    cout << " " << i << "______  /__|   " << i << "____/|____/|   __/|___|" << i << "_____  / " << endl;
    cout <<  "        " << i << "/                   |__|              " << i << "/        " << endl;
}
