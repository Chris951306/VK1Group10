#include "service.h"

void service::addScientist(){
    QSqlQuery query;
    QString name;
    bool gender;
    int yob;
    int yod;
    query.prepare("INSERT INTO scientists(name, gender, yob, yod) VALUES (:name, :gender, :yob, :yod)");// Queries the sql database to insert values into a new line in table, based on user input
    QTextStream qtin(stdin);// Creates a cin operator for QStrings
    do{
        cout << "Enter name of scientist: ";
        cin.ignore();// Programs normally expect a cin here, so we have to add this to make it 'ignore' it's call
        name = qtin.readLine();// Makes use of the readLine child function of the QString operator
    }while(!checkName(name));// Will continue to ask the user for a legal name if input is empty or contains illegal characters
    query.bindValue(":name", name);// Binds the users input to the placeholder from the query
    gender = legalGender();
    query.bindValue(":gender", gender);
    yob = legalBirth();
    query.bindValue(":yob", yob);
    yod = legalDeath(yob);
    query.bindValue(":yod", yod);
    query.exec();
}

bool service::editScientist(unsigned int val){
    QSqlQuery query;
    char choice;
    QString name;
    bool gender;
    int yob;
    int yod;
    cout << "1. Scientist name\t\t2. Gender\n3. Year of birth\t\t4. Year of death" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        query.prepare("UPDATE scientists SET name = :name WHERE id = :id");// Queries the sql database to update the name where the id matches the value parsed to function from controller
        QTextStream qtin(stdin);
        do{
            cout << "Enter name of scientist: ";
            cin.ignore();
            name = qtin.readLine();
        }while(!checkName(name));
        query.bindValue(":name", name);
        query.bindValue(":id", val);
        query.exec();
        return true;
    }
    else if(choice == '2'){
        query.prepare("SELECT gender FROM scientists WHERE id = :id");// Queries the sql database to return the current gender at id = parsed value
        query.bindValue(":id", val);
        query.exec();
        query.next();
        gender = query.value("gender").toBool();// Stores queried gender in the local variable
        query.prepare("UPDATE scientists SET gender = :gender WHERE id = :id");
        if(gender)// If male --> female
            gender = false;
        else// If female --> male
            gender = true;
        query.bindValue(":gender", gender);
        query.bindValue(":id", val);
        query.exec();
        return true;
    }
    else if(choice == '3'){
        query.prepare("UPDATE scientists SET yob = :yob WHERE id = :id");
        yob = legalBirth();
        query.bindValue(":yob", yob);
        query.bindValue(":id", val);
        query.exec();
        return true;
    }
    else if(choice == '4'){
        query.prepare("SELECT yob FROM scientists WHERE id = :id");
        query.bindValue(":id", val);
        query.exec();
        query.next();
        yob = query.value("yob").toInt();
        query.prepare("UPDATE scientists SET yod = :yod WHERE id = :id");
        yod = legalDeath(yob);
        query.bindValue(":yod", yod);
        query.bindValue(":id", val);
        query.exec();
        return true;
    }
    return false;
}

int service::legalBirth(){
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

int service::legalDeath(int yob){
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

bool service::legalGender(){// Entire function only makes sure input is either m or f, and sets the appropriate boolean value to the variable
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

void service::addComputer(){// Same as addScientist - only difference is that it adds different values in sql database
    QSqlQuery query;
    QString name, type;
    int year;
    bool built;
    query.prepare("INSERT INTO computers (name, year, type, built) VALUES (:name, :year, :type, :built)");
    QTextStream qtin(stdin);
    do{
        cout << "Enter name of computer: ";
        cin.ignore();
        name = qtin.readLine();
    }while(!checkName(name));
    query.bindValue(":name", name);
    year = legalYear();
    query.bindValue(":year", year);
    do{
        cout << "Enter type of computer: ";
        cin.ignore();
        name = qtin.readLine();
    }while(!checkName(name));
    query.bindValue(":type", type);
    built = legalBuilt();
    query.bindValue(":built", built);
    query.exec();
}

bool service::editComputer(unsigned int val){// Queries the server to update a value based on users input
    QSqlQuery query;
    char choice;
    QString name, type;
    int year;
    bool built;
    cout << "1. Computer name\t\t2. Build year\n3. Computer type\t\t4. Build status" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        query.prepare("UPDATE computers SET name = :name WHERE id = :id");
        QTextStream qtin(stdin);
        do{
            cout << "Enter name of computer: ";
            cin.ignore();
            name = qtin.readLine();
        }while(!checkName(name));
        query.bindValue(":name", name);
        query.bindValue(":id", val);
        query.exec();
        return true;
    }
    else if(choice == '2'){
        query.prepare("SELECT year FROM computers WHERE id = :id");
        query.bindValue(":id", val);
        query.exec();
        query.next();
        year = query.value("year").toInt();
        query.prepare("UPDATE computers SET year = :year WHERE id = :id");
        year = legalDeath(year);
        query.bindValue(":year", year);
        query.bindValue(":id", val);
        query.exec();
        return true;
    }
    else if(choice == '3'){
        query.prepare("UPDATE computers SET type = :type WHERE id = :id");
        QTextStream qtin(stdin);
        do{
            cout << "Enter type of computer: ";
            cin.ignore();
            name = qtin.readLine();
        }while(!checkName(name));
        query.bindValue(":type", type);
        query.bindValue(":id", val);
        query.exec();
        return true;
    }
    else if(choice == '4'){
        query.prepare("SELECT built FROM computers WHERE id = :id");
        query.bindValue(":id", val);
        query.exec();
        query.next();
        built = query.value("built").toBool();
        query.prepare("UPDATE computers SET built = :built WHERE id = :id");
        if(built)
            built = false;
        else
            built = true;
        query.bindValue(":built", built);
        query.bindValue(":id", val);
        query.exec();
        return true;
    }
    return false;
}

int service::legalYear(){
    int year;
    do{
        cout << "When was this computer built(yyyy): ";
        cin >> year;
        if(MINYEAR < year && year <= MAXYEAR){// Makes sure computer was built within the legal restrictions
            return year;
        }
        cout << "That is not possible!" << endl;
    }while(true);
}

bool service::legalBuilt(){// Same as legalGender - enter y or n, otherwise program will keep asking
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
        else
            cout << "Invalid input!" << endl;
    }while(!valid);
    return built;
}

unsigned int service::selectUnit(string s){// Converts a string with numbers into an unsigned integer
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

bool service::isLetter(string s){// Checks if the string, which is only supposed to contain a number, contains a letter
    for(unsigned int i = 0; i < s.size(); i++){
        if(isalpha(s[i]))
            return true;
    }
    return false;
}

bool service::checkName(QString &name){
    if(name.isEmpty()){// If the input string is empy, user is told to input at least(!) something
        cout << "Name can't be empty!" << endl;
        return false;
    }
    for(int i = 0; i < name.length(); i++){
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

void service::multiSearch(QString &s){
    QString a = s;// In case shit should happen and function brakes, doesn't fuck up original string
    if(a.length() > 0){
        for(unsigned int i = a.length()-1; i > 0; i--){
            a[i+1] = a[i];// Shifts all the characters in the string one position to the right
        }
        a[1] = s[0];// Workaround for a bug where the first character was not moved
        a[0] = '%';// Replaces the character in position 0 with a '%'
        a[a.length()] = '%';// Adds a '%' to the end of string
    }
    s = a;// Things went as expected, set input string equal to the edited string
}

bool service::searchScientist(vector<int> &id){// Allows user to search for scientist based on input - name search allows partial match due to multiSearch function
    QSqlQuery query;
    char choice, choice2;
    QString name;
    bool gender;
    int yob, yod = 0;
    cout << "1. Search by name\t\t2. Search by gender\n3. Search by year of birth\t4. Search by year of death" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        query.prepare("SELECT id FROM scientists WHERE name LIKE :name");
        QTextStream qtin(stdin);
        cout << "Enter name of scientist: ";
        cin.ignore();
        name = qtin.readLine();
        multiSearch(name);
        query.bindValue(":name", name);
        query.exec();
        while(query.next()){
            int store = query.value("id").toInt();
            id.push_back(store);
        }
        return true;
    }
    else if(choice == '2'){
        query.prepare("SELECT id FROM scientists WHERE gender = :gender");
        gender = legalGender();
        query.bindValue(":gender", gender);
        query.exec();
        while(query.next()){
            int store = query.value("id").toInt();
            id.push_back(store);
        }
        return true;
    }
    else if(choice == '3'){
        query.prepare("SELECT id FROM scientists WHERE yob = :yob");
        yob = legalBirth();
        query.bindValue(":yob", yob);
        query.exec();
        while(query.next()){
            int store = query.value("id").toInt();
            id.push_back(store);
        }
        return true;
    }
    else if(choice == '4'){
        query.prepare("SELECT id FROM scientists WHERE yod = :yod");
        cout << "Is this amazing person alive(y/n): ";
        cin >> choice2;
        if(choice2 == 'y')
            yod = 3000;
        else if(choice2 == 'n'){
            cout << "Ohhhh I'm sorry, please enter year of death(yyyy): ";
            cin >> yod;
        }
        query.bindValue(":yod", yod);
        query.exec();
        while(query.next()){
            int store = query.value("id").toInt();
            id.push_back(store);
        }
        return true;
    }
    return false;
}

bool service::searchComputer(vector<int> &id){// Allows user to search for computer based on input - name and type searches allows partial match due to multiSearch function
    QSqlQuery query;
    char choice;
    QString name, type;
    int year;
    bool built;
    cout << "1. Search by name\t\t2. Search by build year\n3. Search by type\t\t4. Search by built or not built" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        query.prepare("SELECT id FROM computers WHERE name LIKE :name");
        QTextStream qtin(stdin);
        cout << "Enter name of computer: ";
        cin.ignore();
        name = qtin.readLine();
        multiSearch(name);
        query.bindValue(":name", name);
        query.exec();
        while(query.next()){
            int store = query.value("id").toInt();
            id.push_back(store);
        }
        return true;
    }
    else if(choice == '2'){
        query.prepare("SELECT id FROM computers WHERE year = :year");
        year = legalYear();
        query.bindValue(":year", year);
        query.exec();
        while(query.next()){
            int store = query.value("id").toInt();
            id.push_back(store);
        }
        return true;
    }
    else if(choice == '3'){
        query.prepare("SELECT id FROM computers WHERE type LIKE :type");
        QTextStream qtin(stdin);
        cout << "Enter type: ";
        cin.ignore();
        type = qtin.readLine();
        multiSearch(type);
        query.bindValue(":type", type);
        query.exec();
        while(query.next()){
            int store = query.value("id").toInt();
            id.push_back(store);
        }
        return true;
    }
    else if(choice == '4'){
        query.prepare("SELECT id FROM computers WHERE built = :built");
        do{
            built = legalBuilt();
        }while(!built);
        query.bindValue(":built", built);
        query.exec();
        while(query.next()){
            int store = query.value("id").toInt();
            id.push_back(store);
        }
        return true;
    }
    return false;
}

void service::addLink(int csid, int cid){// Allows user to add a link between a scientist and a computer
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM link WHERE csid = :csid AND cid = :cid");// Queries the sql server to see if the link already exists
    query.bindValue(":csid", csid);
    query.bindValue(":cid", cid);
    query.exec();
    query.next();
    unsigned int count = query.value("COUNT(*)").toUInt();
    if(count != 0){// Checks to see if match exists
        cout << "This link already excists!" << endl;
    }
    else {// If match does not exist, add new match
        query.prepare("INSERT INTO link (csid, cid) VALUES (:csid, :cid)");
        query.bindValue(":csid", csid);
        query.bindValue(":cid", cid);
        query.exec();
    }
}
