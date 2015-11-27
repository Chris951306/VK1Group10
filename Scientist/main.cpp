#include "scientist.h"

void core(vector<scientist> &s);
void logo();

int main()
{
    vector<scientist> s;

    logo();

    loadInfo(s);

    core(s);

    return 0;
}

void core(vector<scientist> &s)
{
    bool go = false;
    do{
        go = false;
        char choice;
        cout << endl << "Enter a number for your choice. Any other inputs quit the program." << endl;
        cout << endl;
        cout << "1. Add scientist\t2. Edit scientist\n3. Display all scientists" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if(choice == '1'){
            scientist temp;
            cout << endl;
            temp.readInfo();
            s.push_back(temp);
            saveInfo(s);
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
    }while(go);
}

void logo(){
    char i = 92;
    cout << "  ________                          ___________    " << endl;
    cout << " /  _____/______  ____  __ ________/_   " << i << "   _  " << i << "   " << endl;
    cout << "/   " << i << "  __" << i << "_  __ " << i << "/  _ " << i << "|  |  " << i << "____ "
         << i << "|   /  /_" << i << "  " << i << "  " << endl;
    cout << i << "    " << i << "_" << i << "  " << i << "  | " << i
         << "(  <_> )  |  /  |_> >   " << i << "  " << i << "_/   " << i << " " << endl;
    cout << " " << i << "______  /__|   " << i << "____/|____/|   __/|___|" << i << "_____  / " << endl;
    cout <<  "        " << i << "/                   |__|              " << i << "/        " << endl;
}
