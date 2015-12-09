#include "display.h"

void display::printCStop(){
    cout << setfill(' ') << right << setw(4) << "#" << left << setw(2) << "" << left << setw(25) << "Name" << left << setw(12) << "Gender";
    cout << setfill(' ') << left << setw(14) << "Birth" << left << "Death" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(63) << "" << endl;
}

void display::printCSbot(){
    service s;
    unsigned int count = s.returnCScount();
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(63) << "" << endl;
    cout << setfill(' ') << setw(3) << "" << "Total amount of scientists: " << count << endl << endl;
}

void display::printCtop(){
    cout << setfill(' ') << right << setw(4) << "#" << left << setw(2) << "" << left << setw(30) << "Name" << left << setw(12) << "Year";
    cout << setfill(' ') << left << setw(18) << "Type" << left << "Build status" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(75) << "" << endl;
}

void display::printCbot(){
    service s;
    unsigned int count = s.returnCcount();
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(75) << "" << endl;
    cout << setfill(' ') << setw(3) << "" << "Total amount of computers: " << count << endl << endl;
}

void display::addScientist(){
    QTextStream in(stdin);
    service s;
    QString name;
    bool gender;
    int yob, yod;
    cin.ignore();
    do{
        cout << "Enter name of scientist: ";
        name = in.readLine();
    }while(!checkName(name));
    gender = legalGender();
    yob = legalBirth();
    yod = legalDeath(yob);
    s.addScientist(name, gender, yob, yod);
}

bool display::editScientist(unsigned int val){
    QTextStream in(stdin);
    service s;
    char choice;
    QString name;
    bool gender;
    int yob;
    int yod;
    cout << "1. Scientist name\t\t2. Gender\n3. Year of birth\t\t4. Year of death" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        cin.ignore();
        do{
            cout << "Enter name of scientist: ";
            name = in.readLine();
        }while(!checkName(name));
        s.updateCSname(val, name);
        return true;
    }
    else if(choice == '2'){
        gender = s.returnCSgender(val);
        if(gender)// If male --> female
            gender = false;
        else// If female --> male
            gender = true;
        s.updateCSgender(val, gender);
        return true;
    }
    else if(choice == '3'){
        yob = legalBirth();
        s.updateCSyob(val, yob);
        return true;
    }
    else if(choice == '4'){
        yob = s.returnCSyob(val);
        yod = legalDeath(yob);
        s.updateCSyod(val, yod);
        return true;
    }
    return false;
}

void display::printScientist(unsigned int val){
    service s;
    scientist cs(0, "", 0, 0, 0);
    s.returnScientist(val, cs);
    cout << right << setfill(' ') << setw(4) << cs.returnId() << ": ";
    cout << left << setfill(' ') << setw(25) << cs.returnName();
    if(cs.returnGender())
        cout << left << setw(12) << "Male";
    else
        cout << left << setw(12) << "Female";
    int yob = cs.returnYob();
    if(yob < 0){
        cout << right << setfill('0') << setw(4) << abs(yob) << " B.C. --> ";
    }
    else{
        cout << right << setfill('0') << setw(4) << yob << " A.D. --> ";
    }
    int yod = cs.returnYod();
    if(yod == STILLALIVE){
        cout << "Alive";
    }
    else if(yod < 0){
        cout << right << setfill('0') << setw(4) << abs(yod) << " B.C.";
    }
    else{
        cout << right << setfill('0') << setw(4) << yod << " A.D.";
    }
}

void display::printScientists(){
    service s;
    printCStop();
    vector<scientist> cs;
    s.returnScientists(cs);
    for(unsigned int i = 0; i < cs.size(); i++){
        unsigned int id = cs[i].returnId();
        string name = cs[i].returnName();
        bool gender = cs[i].returnGender();
        int yob = cs[i].returnYob();
        int yod = cs[i].returnYod();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(25) << name;
        if(gender)
            cout << left << setw(12) << "Male";
        else
            cout << left << setw(12) << "Female";
        if(yob < 0)
            cout << right << setfill('0') << setw(4) << abs(yob) << " B.C. --> ";
        else
            cout << right << setfill('0') << setw(4) << yob << " A.D. --> ";
        if(yod == STILLALIVE)
            cout << "Alive";
        else if(yod < 0)
            cout << right << setfill('0') << setw(4) << abs(yod) << " B.C.";
        else
            cout << right << setfill('0') << setw(4) << yod << " A.D.";
        cout << endl;
    }
    printCSbot();
}

bool display::sortScientists(bool &namesort, bool &gendersort, bool &yobsort){
    service s;
    vector<int> cs;
    char choice;
    cout << "1. Sort by name\t\t2. Sort by gender\t3. Sort by year of birth" << endl;
    cout << "Same option twice sorts opposite." << endl;
    cout << "Enter choice: ";
    cin  >> choice;
    if(choice == '1'){
        cout << endl;
        printCStop();
        if(namesort){
            s.sortCSname(namesort, cs);
            for(unsigned int i = 0; i < cs.size(); i++){
                printScientist(cs[i]);
                cout << endl;
            }
            namesort = false;
        }
        else{
            s.sortCSname(namesort, cs);
            for(unsigned int i = 0; i < cs.size(); i++){
                printScientist(cs[i]);
                cout << endl;
            }
            namesort = true;
        }
    }
    else if(choice == '2'){
        cout << endl;
        printCStop();
        if(gendersort){
            s.sortCSgender(gendersort, cs);
            for(unsigned int i = 0; i < cs.size(); i++){
                printScientist(cs[i]);
                cout << endl;
            }
            gendersort = false;
        }
        else{
            s.sortCSgender(gendersort, cs);
            for(unsigned int i = 0; i < cs.size(); i++){
                printScientist(cs[i]);
                cout << endl;
            }
            gendersort = true;
        }
    }
    else if(choice == '3'){
        cout << endl;
        printCStop();
        if(yobsort){
            s.sortCSyob(yobsort, cs);
            for(unsigned int i = 0; i < cs.size(); i++){
                printScientist(cs[i]);
                cout << endl;
            }
            yobsort = false;
        }
        else{
            s.sortCSyob(yobsort, cs);
            for(unsigned int i = 0; i < cs.size(); i++){
                printScientist(cs[i]);
                cout << endl;
            }
            yobsort = true;
        }
    }
    else{
        return false;
    }
    printCSbot();
    return true;
}

bool display::searchScientists(vector<int> &id){
    QTextStream in(stdin);
    service s;
    char choice, choice2;
    QString name;
    bool gender;
    int yob, yod = 0;
    cout << "1. Search by name\t\t2. Search by gender\n3. Search by year of birth\t4. Search by year of death" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        cin.ignore();
        cout << "Enter name of scientist: ";
        name = in.readLine();
        multiSearch(name);
        s.searchCSname(name, id);
        return true;
    }
    else if(choice == '2'){
        gender = legalGender();
        s.searchCSgender(gender, id);
        return true;
    }
    else if(choice == '3'){
        yob = legalBirth();
        s.searchCSyob(yob, id);
        return true;
    }
    else if(choice == '4'){
        cout << "Is this amazing person alive(y/n): ";
        cin >> choice2;
        if(choice2 == 'y')
            yod = 3000;
        else if(choice2 == 'n'){
            cout << "Ohhhh I'm sorry, please enter year of death(yyyy): ";
            cin >> yod;
        }
        s.searchCSyod(yod, id);
        return true;
    }
    return false;
}

int display::legalBirth(){
    int yob;
    do{
        cout << "Enter year of birth(yyyy): ";
        cin >> yob;
        if(MINYEAR < yob && yob <= MAXYEAR){// Makes sure the user inputs a valid year of birth, based on constants declared in database.h
            return yob;
        }
        cout << "That is not possible!" << endl;
    }while(true);
}

int display::legalDeath(int yob){
    int yod;
    char input;
    do{
        cout << "Is this amazing person alive(y/n): ";// Gives the user the option to make the scientist 'still alive'
        cin  >> input;
        if(input != 'n' && input != 'y'){// Makes sure user answers the question in an appropriate fashion
            cout << "Invalid input!" << endl;
        }
    }while(input != 'n' && input != 'y');// Loops as long as input is invalid

    yod = STILLALIVE;// Sets the scientists year of death to a value above MAXYEAR, as declared in database.h
    if(input == 'n'){
        do{
            cout << "Ohhhh I'm sorry, please enter year of death(yyyy): ";
            cin >> yod;
            if(MINYEAR < yod && yod <= MAXYEAR){// Makes sure the year of death is within the limits of the constants MINYEAR and MAXYEAR
                if(yob <= yod){// Makes sure the person is born before it died
                return yod;
                }
            }
            cout << "That is not possible!" << endl;
        }while(true);
    }
    return yod;
}

bool display::legalGender(){// Entire function only makes sure input is either m or f, and sets the appropriate boolean value to the variable
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

bool display::checkName(QString &name){
    if(name.isEmpty()){// If the input string is empy, user is told to input at least(!) something
        cout << "Name can't be empty!" << endl;
        return false;
    }
    for(int i = 0; i < name.size(); i++){
        if((name[i].isLower() && i == 0) || (name[i].isLower() && name[i-1] == ' ')){// If first charachter is lower or first character after a space is lower, change the letter to capital
            name[i] = name[i].toUpper();
        }
        else if((name[i] == ' ' && name[i+1] == ' ') || (name[i] == ' ' && i == 0)){// If there are two spaces after each other or the string begins with one or more spaces, remove a space
            name.remove(i, 1);
            i--;
        }
        else if(!name[i].isLetterOrNumber() && name[i] != '\'' && name[i] != ',' && name[i] != '.' && name[i] != '-' && name[i] != ' '){// If the current character is not a letter nor a number or any of the legal symbols, make user input a new, valid, string
            cout << "Invalid name!" << endl;
            return false;
        }
    }
    return true;
}

void display::addComputer(){
    QTextStream in(stdin);
    service s;
    QString name, type;
    int year;
    bool built;
    cin.ignore();
    do{
        cout << "Enter name of computer: ";
        name = in.readLine();
    }while(!checkName(name));
    year = legalYear();
    cin.ignore();
    do{
        cout << "Enter type of computer: ";
        type = in.readLine();
    }while(!checkName(type));
    built = legalBuilt();
    s.addComputer(name, year, type, built);
}

bool display::editComputer(unsigned int val){
    QTextStream in(stdin);
    service s;
    char choice;
    QString name, type;
    int year;
    bool built;
    cout << "1. Computer name\t\t2. Build year\n3. Computer type\t\t4. Build status" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        cin.ignore();
        do{
            cout << "Enter name of computer: ";
            name = in.readLine();
        }while(!checkName(name));
        s.updateCname(val, name);
        return true;
    }
    else if(choice == '2'){
        year = legalYear();
        s.updateCyear(val, year);
        return true;
    }
    else if(choice == '3'){
        cin.ignore();
        do{
            cout << "Enter type of computer: ";
            type = in.readLine();
        }while(!checkName(type));
        s.updateCtype(val, type);
        return true;
    }
    else if(choice == '4'){
        built = s.returnCbuilt(val);
        if(built)
            built = false;
        else
            built = true;
        s.updateCbuilt(val, built);
        return true;
    }
    return false;
}


void display::printComputer(unsigned int val){
    service s;
    computer c(0, "", 0, "", 0);
    s.returnComputer(val, c);
    unsigned int id = c.returnId();
    string name = c.returnName();
    int year = c.returnYear();
    string type = c.returnType();
    bool built = c.returnBuilt();
    cout << right << setfill(' ') << setw(4) << id << ": ";
    cout << left << setfill(' ') << setw(30) << name;
    if(year < 0)
    {
        cout << left << setfill('0') << setw(4) << abs(year) << setfill(' ') << setw(8) << " B.C.";
    }
    else{
        cout << left << setfill('0') << setw(4) << year << setfill(' ') << setw(8) << " A.D.";
    }
    cout << left << setfill(' ') << setw(18) << type;
    if(built)
        cout << left << setw(9) << "Built";
    else
        cout << left << setw(9) << "Not built";
}

void display::printComputers(){
    service s;
    printCtop();
    vector<computer> c;
    s.returnComputers(c);
    for(unsigned int i = 0; i < c.size(); i++){
        unsigned int id = c[i].returnId();
        string name = c[i].returnName();
        int year = c[i].returnYear();
        string type = c[i].returnType();
        bool built = c[i].returnBuilt();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(30) << name;
        if(year < 0)
            cout << left << setfill('0') << setw(4) << abs(year) << setfill(' ') << setw(8) << " B.C.";
        else
            cout << left << setfill('0') << setw(4) << year << setfill(' ') << setw(8) << " A.D.";
        cout << left << setfill(' ') << setw(18) << type;
        if(built)
            cout << left << setw(9) << "Built";
        else
            cout << left << setw(9) << "Not built";
        cout << endl;
    }
    printCbot();
}

bool display::sortComputers(bool &namesort, bool &yearsort, bool &typesort, bool &builtsort){
    service s;
    vector<int> c;
    char choice;
    cout << "1. Sort by name\t\t\t2. Sort by year\n3. Sort by type\t\t\t4. Sort by built or not" << endl;
    cout << "Same option twice sorts opposite." << endl;
    cout << "Enter choice: ";
    cin  >> choice;
    if(choice == '1'){
        cout << endl;
        printCtop();
        if(namesort){
            s.sortCname(namesort, c);
            for(unsigned int i = 0; i < c.size(); i++){
                printComputer(c[i]);
                cout << endl;
            }
            namesort = false;
        }
        else{
            s.sortCname(namesort, c);
            for(unsigned int i = 0; i < c.size(); i++){
                printComputer(c[i]);
                cout << endl;
            }
            namesort = true;
        }
    }
    else if(choice == '2'){
        cout << endl;
        printCtop();
        if(yearsort){
            s.sortCyear(yearsort, c);
            for(unsigned int i = 0; i < c.size(); i++){
                printComputer(c[i]);
                cout << endl;
            }
            yearsort = false;
        }
        else{
            s.sortCyear(yearsort, c);
            for(unsigned int i = 0; i < c.size(); i++){
                printComputer(c[i]);
                cout << endl;
            }
            yearsort = true;
        }
    }
    else if(choice == '3'){
        cout << endl;
        printCtop();
        if(typesort){
            s.sortCtype(typesort, c);
            for(unsigned int i = 0; i < c.size(); i++){
                printComputer(c[i]);
                cout << endl;
            }
            typesort = false;
        }
        else{
            s.sortCtype(typesort, c);
            for(unsigned int i = 0; i < c.size(); i++){
                printComputer(c[i]);
                cout << endl;
            }
            typesort = true;
        }
    }
    else if(choice == '4'){
        cout << endl;
        printCtop();
        if(builtsort){
            s.sortCbuilt(builtsort, c);
            for(unsigned int i = 0; i < c.size(); i++){
                printComputer(c[i]);
                cout << endl;
            }
            builtsort = false;
        }
        else{
            s.sortCbuilt(builtsort, c);
            for(unsigned int i = 0; i < c.size(); i++){
                printComputer(c[i]);
                cout << endl;
            }
            builtsort = true;
        }
    }
    else{
        return false;
    }
    printCbot();
    return true;
}

bool display::searchComputers(vector<int> &id){
    QTextStream in(stdin);
    service s;
    char choice;
    QString name, type;
    int year;
    bool built;
    cout << "1. Search by name\t\t2. Search by build year\n3. Search by type\t\t4. Search by built or not built" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        cin.ignore();
        cout << "Enter name of computer: ";
        name = in.readLine();
        multiSearch(name);
        s.searchCname(name, id);
        return true;
    }
    else if(choice == '2'){
        year = legalYear();
        s.searchCyear(year, id);
        return true;
    }
    else if(choice == '3'){
        cin.ignore();
        cout << "Enter type: ";
        type = in.readLine();
        multiSearch(type);
        s.searchCtype(type, id);
        return true;
    }
    else if(choice == '4'){
        do{
            built = legalBuilt();
        }while(!built);
        s.searchCbuilt(built, id);
        return true;
    }
    return false;
}

int display::legalYear(){
    int year;
    do{
        cout << "When was this computer built(yyyy): ";
        cin >> year;
        if(MINYEAR < year && year <= MAXYEAR){
            return year;
        }
        cout << "That is not possible!" << endl;
    }while(true);
}

bool display::legalBuilt(){
    bool valid = false;
    bool built;
    char input;
    do{
        valid = false;
        cout << "Was the computer built(y/n): ";
        cin >> input;
        if(input == 'n'){
            built = false;
            valid = true;
        }
        else if(input == 'y'){
            built = true;
            valid = true;
        }
        else{
            cout << "Invalid input!" << endl;
        }
    }while(!valid);
    return built;
}

void display::addLink(int csid, int cid){
    service s;
    if(s.isLink(csid, cid)){
        cout << "This link already exists!" << endl;
    }
    else{
        s.addLink(csid, cid);
    }
}

void display::editLink(){
    service s;
    vector<int> l;
    link ltemp(0, 0);
    scientist stemp(0, "", 0, 0, 0);
    computer ctemp(0, "", 0, "", 0);
    s.returnLinks(l);
    cout << endl;
    cout << setfill(' ') << setw(8) << right << "#   " <<  setfill(' ') << left << setw(25) << "Scientist name" << setfill(' ') << left << setw(30) << "Computer name" << endl;
    cout << setfill(' ') << setw(4) << "" << setfill('-') << setw(55) << "" << endl;
    for(unsigned int i = 1; i <= l.size(); i++){
        s.returnLink(i, ltemp);
        int csid = ltemp.returnCSID();
        s.returnScientist(csid, stemp);
        string csname = stemp.returnName();
        int cid = ltemp.returnCID();
        s.returnComputer(cid, ctemp);
        string cname = ctemp.returnName();
        cout << setfill(' ') << right << setw(5) << i << ":  " << setfill(' ') << left << setw(25) << csname << setfill(' ') << left << setw(30) << cname << endl;
    }
    cout << endl;
    string option;
    cout << "Enter link number to edit.\n(If input is not a listed number, you will be returned to menu): ";
    cin >> option;
    unsigned int val = selectUnit(option);
    unsigned int maxId = s.maxLid();
    if(isLetter(option) || val == 0 || option[0] == 45 || val > maxId);
    else{
        char choice;
        cout << endl;
        cout << "1. Edit scientist link\t\t2. Edit computer link" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if(choice == '1'){
            cout << endl;
            printScientists();
            cout << "Enter scientist number to change to.\n(If input is not a listed number, you will be returned to menu): ";
            cin >> option;
            unsigned int csid = selectUnit(option);
            unsigned int maxId = s.maxCSid();
            if(isLetter(option) || csid == 0 || option[0] == 45 || csid > maxId);
            else{
                vector<int> l;
                bool check = false;
                s.returnLinks(l);
                for(unsigned int i = 1; i <= l.size(); i++){
                    link temp(0, 0);
                    s.returnLink(i, temp);
                    unsigned int check_cid = temp.returnCID();
                    unsigned int check_csid = temp.returnCSID();
                    s.returnLink(val, temp);
                    unsigned int cid = temp.returnCID();
                    if(check_csid == csid && check_cid == cid){
                        if(s.isLink(csid, cid)){
                            cout << endl << "This link already exists!" << endl;
                            check = true;
                        }
                    }
                }
                if(!check){
                    s.updateCSlink(val, csid);
                }
            }
        }
        else if(choice == '2'){
            cout << endl;
            printComputers();
            cout << "Enter computer number to change to.\n(If input is not a listed number, you will be returned to menu): ";
            cin >> option;
            unsigned int cid = selectUnit(option);
            unsigned int maxId = s.maxCid();
            if(isLetter(option) || cid == 0 || option[0] == 45 || cid > maxId);
            else{
                vector<int> l;
                bool check = false;
                s.returnLinks(l);
                for(unsigned int i = 1; i <= l.size(); i++){
                    link temp(0, 0);
                    s.returnLink(i, temp);
                    unsigned int check_cid = temp.returnCID();
                    unsigned int check_csid = temp.returnCSID();
                    s.returnLink(val, temp);
                    unsigned int csid = temp.returnCSID();
                    if(check_csid == csid && check_cid == cid){
                        if(s.isLink(csid, cid)){
                            cout << endl << "This link already exists!" << endl;
                            check = true;
                        }
                    }
                }
                if(!check){
                    s.updateClink(val, cid);
                }
            }
        }
    }
}

unsigned int display::selectUnit(string s){
    unsigned int val = 0;
    for(unsigned int i = 0; i < s.size(); i++){
        if(i == (s.size() - 1))// Counts amount of 1s
            val += s[i] - 48;
        else if(i == (s.size() - 2))// Counts amount of 10s
            val += (s[i] - 48) * 10;
        else if(i == (s.size() - 3))// Counts amount of 100s
            val += (s[i] - 48) * 100;
        else if(i == (s.size() - 4))// Counts amount of 1.000s
            val += (s[i] - 48) * 1000;
        else if(i == (s.size() - 5))// Counts amount of 10.000s
            val += (s[i] - 48) * 10000;
    }
    return val;
}

bool display::isLetter(string s){
    for(unsigned int i = 0; i < s.size(); i++){
        if(isalpha(s[i]))
            return true;
    }
    return false;
}

void display::multiSearch(QString &s){
    QString a = s;// In case shit should happen and function brakes, doesn't fuck up original string
    if(!s.isEmpty()){// Checks if string is empty, if not - '%' is not added to prevent an empty search to list everything
        for(unsigned int i = a.length()-1; i > 0; i--){
            a[i+1] = a[i];// Shifts all the characters in the string one position to the right
        }
        a[1] = s[0];// Workaround for a bug where the first character was not moved
        a[0] = '%';// Replaces the character in position 0 with a '%'
        a[a.length()] = '%';// Adds a '%' to the end of string
    }
    s = a;// Things went as expected, set input string equal to the edited string
}

void display::printCStoC(){
    service s;
    unsigned int n, m, csid, cid;
    string csname, cname;
    n = s.maxCSid();
    for(unsigned int i = 1; i <= n; i++){
        cout << endl;
        s.getCSid(csname, csid, i);
        cout << "   " << csname << ":" << endl;
        m = s.getCIDcount(csid);
        for(unsigned int j = 1; j <= m; j++){
            s.getCidFromCSid(csid, cid, j);
            s.getCnameFromCid(cid, cname);
            cout << "\t- " << cname << endl;
        }
    }
}

void display::printCtoCS(){
    service s;
    unsigned int n, m, csid, cid;
    string csname, cname;
    n = s.maxCid();
    for(unsigned int i = 1; i <= n; i++){
        cout << endl;
        s.getCid(cname, cid, i);
        cout << "   " << cname << ":" << endl;
        m = s.getCSIDcount(cid);
        for(unsigned int j = 1; j <= m; j++){
            s.getCSidFromCid(cid, csid, j);
            s.getCSnameFromCSid(csid, csname);
            cout << "\t- " << csname << endl;
        }
    }
}
