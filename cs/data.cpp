#include "data.h"

data::data(string a, bool b, int c, int d){
    name = a;
    gender = b;
    yob = c;
    yod = d;
}

string data::returnName(){
    return name;
}

bool data::returnGender(){
    return gender;
}

int data::returnYob(){
    return yob;
}

int data::returnYod(){
    return yod;
}

ostream& operator<<(ostream& stream, const data &s){
    stream << left << setfill(' ') << setw(25) << s.name;
    if(s.gender)
        stream << left << setw(12) << "Male";
    else
        stream << left << setw(12) << "Female";
    if(s.yob < 0)
    {
        stream << right << setfill('0') << setw(4) << abs(s.yob) << " B.C. --> ";
    }
    else{
        stream << right << setfill('0') << setw(4) << s.yob << " A.D. --> ";
    }

    if(s.yod == StillAlive){
        stream << "Alive";
    }
    else if(s.yod < 0)
    {
        stream << right << setfill('0') << setw(4) << abs(s.yod) << " B.C.";
    }
    else{
        stream << right << setfill('0') << setw(4) << s.yod << " A.D.";
    }
    stream << endl;
    return stream;
}

