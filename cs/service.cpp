#include "data.h"
#include "service.h"

istream& service::readName(string &s){
    return getline(cin, s);
}

istream& service::readLine(ifstream &load, string &a){
    return getline(load, a);
}

void service::printData(vector<data> &cs){
    cout << setfill(' ') << setw(6) << "" << left << setw(25) << "Name" << left << setw(12) << "Gender";
    cout << setfill(' ') << left << setw(14) << "Birth" << left << "Death" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(63) << "" << endl;
    for(unsigned int i = 0; i < cs.size(); i++){
        cout << right << setfill(' ') << setw(4) << i+1 << ": ";
        cout << cs[i] << endl;
    }
}

void service::addData(vector<data> &cs){
    string name;
    bool gender;
    int yob;
    int yod;
    cout << "Enter name: ";
    cin.ignore();
    readName(name);
    gender = legalGender();
    yob = legalBirth();
    yod = legalDeath(yob);
    data temp(name, gender, yob, yod);
    cs.push_back(temp);
}

void service::editData(vector<data> &cs){
    char choice;
    string option;
    bool go = false;
    int scientist;
    string name;
    bool gender;
    int yob;
    int yod;
    if(cs.size() == 0)
        cout << endl << "No scientists stored!" << endl;
    else{
        cout << endl;
        printData(cs);
        cout << "Enter scientist number to edit.\n(If input is not a listed number, you will be returned to menu): ";
        cin >> option;
        cout << endl;
        go = false;
        unsigned int val = selectData(option);
        if(isLetter(option) || val == 0);
        else{
            for(unsigned int i = 0; i < cs.size(); i++){
                if(val == i+1)
                {
                    scientist = i;
                    name = cs[i].returnName();
                    gender = cs[i].returnGender();
                    yob = cs[i].returnYob();
                    yod = cs[i].returnYod();
                    go = true;
                }
            }
        }
        while(go){
            go = false;
            cout << "1. Name\t\t\t2. Gender\n3. Year of birth\t4. Year of death" << endl;
            cout << "Your choice: ";
            cin >> choice;
            switch(choice){
            case '1':
                cout << "Enter name: ";
                cin.ignore();
                readName(name);
                go = true;
                break;
            case '2':
                gender = legalGender();
                go = true;
                break;
            case '3':
                yob = legalBirth();
                go = true;
                break;
            case '4':
                yod = legalDeath(yob);
                go = true;
                break;
            }
            if(go){
                data temp(name, gender, yob, yod);
                cs[scientist] = temp;
                cout << endl;
                saveData(cs);
                printData(cs);
            }
        }
    }
}

int service::legalBirth(){
    int yob;
    do{
        cout << "Enter year of birth(yyyy): ";
        cin >> yob;
        if(MinYear < yob && yob <= MaxYear){
            return yob;
        }
        cout << "That is not possible! Try again: " << endl;
    }while(true);
}

int service::legalDeath(int yob){
    int yod;
    char input;
    do{  // makes sures that the input is y (yes) or n (no)
        cout << "Is this amazing person alive(y/n):";
        cin  >> input;
        if(input != 'n' && input != 'y'){
            cout << "Invalid input!" << endl;
        }
    }while(input != 'n' && input != 'y');

    yod = StillAlive;
    if(input == 'n'){
        do{
            cout << "Ohhhh I'm sorry, please enter year of death(yyyy): ";
            cin >> yod;
            if(MinYear < yod && yod <= MaxYear){
                if(yob <= yod){
                return yod;
                }
            }
            cout << "That is not possible! Try again: " << endl;
        }while(true);
    }
    return yod;
}

bool service::legalGender(){
    bool valid = false;
    bool gender;
    char input;
    do{
        valid = false;
        cout << "Enter gender(m/f): ";
        cin >> input;
        if(input == 'f'){
            gender = false;
            valid = true;
        }
        else if(input == 'm'){
            gender = true;
            valid = true;
        }
        else
            cout << "Invalid input!" << endl;
    }while(!valid);
    return gender;
}

unsigned int service::selectData(string &s){
    unsigned int val = 0;
    for(unsigned int i = 0; i < s.size(); i++){
        if(i == (s.size() - 1))
            val += s[i] - 48;
        else if(i == (s.size() - 2))
            val += (s[i] - 48) * 10;
        else if(i == (s.size() - 3))
            val += (s[i] - 48) * 100;
        else if(i == (s.size() - 4))
            val += (s[i] - 48) * 1000;
        else if(i == (s.size() - 5))
            val += (s[i] - 48) * 10000;
    }
    return val;
}

bool service::isLetter(string &s){
    for(unsigned int i = 0; i < s.size(); i++){
        if(isalpha(s[i]))
            return true;
    }
    return false;
}

void service::saveData(vector<data> &cs){
    ofstream save("scientists.txt", ofstream::out);
    for(unsigned int i = 0; i < cs.size(); i++){
        save << cs[i].returnName() << endl;
        save << cs[i].returnGender() << endl;
        save << cs[i].returnYob() << endl;
        save << cs[i].returnYod() << endl;
    }
    save.close();
}

void service::loadData(vector<data> &cs){
    ifstream load("scientists.txt");
        string in;
        string a;
        bool b;
        int c;
        int d;
        int counter = 0;
    while(readLine(load, in)){
        counter++;
        if(counter == 1){
            a = in;
        }
        if(counter == 2){
            if(in == "0"){
                b = false;
            }else{
                b = true;
            }
        }
        if(counter == 3)
            c = atoi(in.c_str());
        if(counter == 4){
            d = atoi(in.c_str());
            data temp(a, b, c, d);
            cs.push_back(temp);
            counter = 0;
        }
    }
    if(cs.size() > 0)
        cout << endl << "All entries are loaded from database!" << endl;
}

void service::deleteData(vector<data> &cs){
    string option;
    unsigned int val = 0;
    printData(cs);
    cout << "Enter scientist number to delete.\n(If input is not a listed number, you will be returned to menu): ";
    cin >> option;
    val = selectData(option);
    if(isLetter(option) || val == 0);
    else{
        for(unsigned int i = 0; i < cs.size(); i++){
            if(val == i+1)
            {
                cs.erase(cs.begin()+i);
            }
        }
    }
    saveData(cs);
}
