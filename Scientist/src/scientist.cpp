#include "scientist.h"

const int MinYear = 1800;
const int MaxYear = 2015;

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

    do{
        valid = false;
        cout << "Enter year of birth(yyyy): ";
        cin >> this->yob;
        valid = legalBirth(yob);
    }while(!valid);

    do{
        valid = false;
        cout << "Enter year of death(yyyy): ";
        cin >> this->yod;
        valid = legalDeath(yob, yod);
    }while(!valid);

    cout << endl;
}

void scientist::editInfo(){
    bool go = false;
    char choice;
    do{
        go = false;
        cout << "Enter a number for your choice. Any other inputs return you to menu." << endl;
        cout << endl;
        cout << *this;
        cout << "1. Name\t\t\t2. Gender\n3. Date of birth\t4. Date of death" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if(choice == '1')
        {
            cin >> this->name;
            go = true;
        }
        else if(choice == '2')
        {
            if(this->gender)
                this->gender = false;
            else
                this->gender = true;
            go = true;
        }
        else if(choice == '3')
        {
            bool valid = false;
            do{
                valid = false;
                cin >> this->yob;
                valid = legalBirth(yob);
            }while(!valid);
            go = true;
        }
        else if(choice == '4')
        {
            bool valid = false;
            do{
                valid = false;
                cin >> this->yod;
                valid = legalDeath(yob, yod);
            }while(!valid);
            go = true;
        }
    }while(go);
}

bool scientist::legalBirth(int yob){
    if(MinYear < yob && yob <= MaxYear){
        return true;
    }
    cout << "Invalid input!" << endl;
    return false;
}

bool scientist::legalDeath(int yob, int yod){
    if(MinYear < yod && yod <= MaxYear){
        if(yob <= yod){
        return true;
        }
    }
    cout << "Invalid input!" << endl;
    return false;
}

ostream& operator<<(ostream& stream, const scientist &s){
    stream << s.name << endl;
    if(s.gender)
        stream << "Female" << endl;
    else
        stream << "Male" << endl;
    stream << s.yob << endl;
    stream << s.yod << endl;
    stream << endl;
    return stream;
}

string retName(scientist &s){
    return s.name;
}
