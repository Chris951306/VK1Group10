#include "scientist.h"

scientist::scientist(){

}
void scientist::getInfo()
{
    char gender;
    bool valid = false;
    cout << "Enter name: ";
    cin >> this->name;
    do{
        valid=false;
        cout << "Enter gender(m/f): ";
        cin >> gender;
        if (gender == 'm')
        {
            this->gender=false;
            valid = true;
        }
        else if(gender == 'f')
        {
            this->gender=true;
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
