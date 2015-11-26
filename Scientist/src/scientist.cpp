#include "scientist.h"

scientist::scientist(){

}

unsigned int scientist::size(){
    return this->size();
}

void scientist::readInfo(){
    char gender;
    bool valid = false;
    cout << "Enter name: ";
    cin >> this->name;
    do{
        valid = false;
        cout << "Enter gender(m/f): ";
        cin >> gender;
        if(gender == 'm'){
            this->gender = false;
            valid = true;
        }
        else if(gender == 'f'){
            this->gender = true;
            valid = true;
        }
        else
            cout << "Invalid input!" << endl;
    }while(!valid);
    cout << "Enter date of birth(ddmmyyyy): ";
    cin >> this->dob;
    cout << "Enter date of death(ddmmyyyy): ";
    cin >> this->dod;
}

void scientist::editInfo(){
    char choice;
    bool go = false;
    do{
        cout << "Currently stored scientists:" << endl;
        cout << this;
        cout << "Print again(y/n): ";
        cin >> choice;
        if(choice == 'y')
            go = true;
        else if(choice == 'n')
            go = false;
        else
            cout << "Invalid input!" << endl;
    }while(go);
}

ostream& operator<<(ostream& stream, const scientist &s){
    stream << s.name << endl;
    if(s.gender)
        stream << "Female" << endl;
    else
        stream << "Male" << endl;
    stream << s.dob << endl;
    stream << s.dod << endl;
    stream << endl;
    return stream;
}

void temp(scientist &s1, vector<scientist> &s2){
    s1.name = s2[0].name;
    s1.gender = s2[0].gender;
    s1.dob = s2[0].dob;
    s1.dod = s2[0].dod;
}
