#include "scientist.h"

void core(vector<scientist> &s);

int main()
{
    vector<scientist> s;

    core(s);

    return 0;
}

void core(vector<scientist> &s)
{
    bool go = false;
    do{
        go = false;
        char choice;
        cout << "Enter a number for your choice. Any other inputs quit the program." << endl;
        cout << endl;
        cout << "1. Add scientist\t2. Edit scientist" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if(choice == '1'){
            scientist temp;
            temp.readInfo();
            s.push_back(temp);
            go = true;
        }
        else if(choice == '2'){
            bool check = false;
            string in;
            int choice = 99;
            cin >> in;
            for(unsigned int i = 0; i < s.size(); i++){
                if(in == retName(s[i]))
                {
                    choice = i;
                    check = true;
                }
            }
            if(check)
                s[choice].editInfo();
            else{
                cout << "No such scientist!" << endl;
                cout << endl;
            }
            go = true;
        }
    }while(go);
}
