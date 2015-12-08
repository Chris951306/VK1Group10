#include "service.h"

istream& service::readName(string &s){
    return getline(cin, s);
}

istream& service::readLine(ifstream &load, string &a){
    return getline(load, a);
}

void service::printScientists(vector<scientists> &cs){
    cout << setfill(' ') << setw(4) << "#" << left << setw(2) << "" << left << setw(25) << "Name" << left << setw(12) << "Gender";
    cout << setfill(' ') << left << setw(14) << "Birth" << left << "Death" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(63) << "" << endl;
    for(unsigned int i = 0; i < cs.size(); i++){
        cout << cs[i] << endl << endl;
    }
}

void service::addScientist(vector<scientists> &cs){
    unsigned int cs_id = 1;
    if(cs.size() > 0)
        cs_id = (cs.size() + 1);
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
    scientists temp(cs_id, name, gender, yob, yod);
    cs.push_back(temp);
}

void service::addComputer(vector<computers> &c){
    unsigned int c_id = 1;
    if(c.size() > 0)
        c_id = (c.size() + 1);
    string c_name;
    int c_year;
    string c_type;
    bool c_built;
    cout << "Enter name: ";
    cin.ignore();
    readName(c_name);
    c_year = legalYear();
    cout << "Enter type: ";
    cin.ignore();
    readName(c_type);
    c_built = legalBuilt();
    computers temp(c_id, c_name, c_year, c_type, c_built);
    c.push_back(temp);
}

void service::editScientist(vector<scientists> &cs){
    char choice;
    string option;
    bool go = false;
    int scientist;
    unsigned int cs_id;
    string name;
    bool gender;
    int yob;
    int yod;
    if(cs.size() == 0)
        cout << endl << "No scientists stored!" << endl;
    else{
        cout << endl;
        printScientists(cs);
        cout << "Enter scientist number to edit.\n(If input is not a listed number, you will be returned to menu): ";
        cin >> option;
        cout << endl;
        go = false;
        unsigned int val = selectUnit(option);
        if(isLetter(option) || val == 0);
        else{
            for(unsigned int i = 0; i < cs.size(); i++){
                if(val == i+1)
                {
                    scientist = i;
                    cs_id = cs[i].returnId();
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
            cout << setfill('-') << setw(70) << "" << endl;
            cout << "|" << cs[scientist] << "  |" << endl;
            cout << setfill('-') << setw(70) << "" << endl << endl;
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
                scientists temp(cs_id, name, gender, yob, yod);
                cs[scientist] = temp;
                cout << endl;
                saveData(cs);
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

int service::legalYear(){
    int year;
    cout << "Enter build year(If before year 0, enter a \'-\' in front): ";
    cin >> year;
    if(MinYear < year && year < MaxYear)
        return year;
    else{
        bool legal = false;
        do{
            legal = false;
            cout << "Invalid build year. Enter again: ";
            cin >> year;
            if(MinYear < year && year < MaxYear){
                return year;
                legal = true;
            }
        }while(!legal);
    }
    return 0;
}

bool service::legalBuilt(){
    char choice;
    cout << "Was the computer built(y/n): ";
    cin >> choice;
    if(choice == 'y')
        return true;
    else if(choice == 'n')
        return false;
    else{
        bool valid = false;
        do{
            valid = false;
            cout << "Invalid input. Enter again: ";
            cin >> choice;
            if(choice == 'y'){
                return true;
                valid = true;
            }
            else if(choice == 'n'){
                return false;
                valid = true;
            }
        }while(!valid);
    }
    return false;
}

unsigned int service::selectUnit(string &s){
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

void service::saveData(vector<scientists> &cs){
    ofstream save("scientists.txt", ofstream::out);
    for(unsigned int i = 0; i < cs.size(); i++){
        save << cs[i].returnId() << "|";
        save << cs[i].returnName() << "|";
        save << cs[i].returnGender() << "|";
        save << cs[i].returnYob() << "|";
        save << cs[i].returnYod() << endl;
    }
    save.close();
}

void service::loadData(vector<scientists> &cs){
    ifstream load("scientists.txt");
        string in;
        string edit;
        string delim = "|";
        unsigned int pos;
        unsigned int id;
        string a;
        bool b;
        int c;
        int d;
        unsigned int counter = 1;
    while(readLine(load, in)){
        if(counter == 1){
            pos = in.find(delim);
            edit = in.substr(0, pos);
            id = atoi(edit.c_str());
            pos++;
            in = in.substr(pos, in.size() - pos);
            counter++;
        }
        if(counter == 2){
            pos = in.find(delim);
            a = in.substr(0, pos);
            pos++;
            in = in.substr(pos, in.size() - pos);
            counter++;
        }
        if(counter == 3){
            pos = in.find(delim);
            edit = in.substr(0, pos);
            pos++;
            in = in.substr(pos, in.size() - pos);
            counter++;
            if(edit == "0"){
                b = false;
            }else{
                b = true;
            }
        }
        if(counter == 4){
            pos = in.find(delim);
            edit = in.substr(0, pos);
            c = atoi(edit.c_str());
            pos++;
            in = in.substr(pos, in.size() - pos);
            counter++;
        }
        if(counter == 5){
            pos = in.find(delim);
            edit = in.substr(0, pos);
            d = atoi(edit.c_str());
            scientists temp(id, a, b, c, d);
            cs.push_back(temp);
            counter = 1;
        }
    }
    if(cs.size() > 0)
        cout << endl << "All entries are loaded from database!" << endl;
}

void service::deleteScientist(vector<scientists> &cs){
    string option;
    unsigned int val = 0;
    printScientists(cs);
    cout << "Enter scientist number to delete.\n(If input is not a listed number, you will be returned to menu): ";
    cin >> option;
    val = selectUnit(option);
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
