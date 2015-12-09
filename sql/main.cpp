//  Made by:
//  Christian Andreas Jacobsen
//  Hekla Rún Ámundadóttir
//  Kristín Vala Einarsdóttir
//  Þórmundur Smári Hilmarsson
#include "control.h"

void logo();
    //Logo

int main(){
    logo();
    database db;// Initializes a db class
    db.start();// Makes use of db class to start the SQL-server
    control c;// Initializes the control
    c.maincontrol();// Enter main control
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
