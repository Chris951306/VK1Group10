#include "scientists.h"

scientists::scientists(unsigned int id, string a, bool b, int c, int d){
    cs_id = id;
    name = a;
    gender = b;
    yob = c;
    yod = d;
}

unsigned int scientists::returnId(){
    return cs_id;
}

string scientists::returnName(){
    return name;
}

bool scientists::returnGender(){
    return gender;
}

int scientists::returnYob(){
    return yob;
}

int scientists::returnYod(){
    return yod;
}

ostream& operator<<(ostream& stream, const scientists &s){
    stream << right << setfill(' ') << setw(4) << s.cs_id << ": ";
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
    return stream;
}

