#include "control.h"

void logo();
    //Logo

int main(){
    logo();
    control c;// Initializes the control
    c.maincontrol();// Enter main control, takes the database named db with it
    return 0;
}

void logo(){    //This is our logo - had to add the character value for '\' so it wouldn't count as an escape character
    char i = 92;
    cout << "  ________                          ___________    " << endl;
    cout << " /  _____/______  ____  __ ________/_   " << i << "   _  " << i << "   " << endl;
    cout << "/   " << i << "  __" << i << "_  __ " << i << "/  _ " << i << "|  |  " << i << "____ "
         << i << "|   /  /_" << i << "  " << i << "  " << endl;
    cout << i << "    " << i << "_" << i << "  " << i << "  | " << i
         << "(  <_> )  |  /  |_> >   " << i << "  " << i << "_/   " << i << " " << endl;
    cout << " " << i << "______  /__|   " << i << "____/|____/|   __/|___|" << i << "_____  / " << endl;
    cout <<  "        " << i << "/                   |__|              " << i << "/        " << endl << endl;
}
