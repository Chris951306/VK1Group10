#include "data.h"

data::data();

ostream& operator<<(ostream& stream, const data &s){
    stream << s.name << "\t";
    if(s.gender)
        stream << "Female" << "\t";
    else
        stream << "Male" << "\t";
    if(s.yob < 0)
    {
        stream << abs(s.yob) << " B.C. --> ";
    }
    else{
        stream << s.yob << " A.D. --> ";
    }

    if(s.yod == StillAlive){
        for(unsigned int i = 0; i < 4; i++){
            stream << "?";
        }
    }
    else if(s.yod < 0)
    {
        stream << abs(s.yod) << " B.C.";
    }
    else{
        stream << s.yod << " A.D.";
    }
    stream << endl;
    return stream;
}

