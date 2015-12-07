#include "service.h"

void service::addScientist(){
    QSqlQuery query;
    QString name;
    bool gender;
    int yob;
    int yod;
    query.prepare("INSERT INTO scientists(name, gender, yob, yod) VALUES (:name, :gender, :yob, :yod)");
    QTextStream qtin(stdin);
    do{
        cout << "Enter name of scientist: ";
        cin.ignore();
        name = qtin.readLine();
    }while(!checkName(name));
    query.bindValue(":name", name);
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
    cout << "1. Name\t\t\t2. Gender\n3. Year of birth\t4. Year of death" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if(choice == '1'){
        query.prepare("UPDATE scientists SET name = :name WHERE id = :id");
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
        query.prepare("SELECT gender FROM scientists WHERE id = :id");
        query.bindValue(":id", val);
        query.exec();
        query.next();
        gender = query.value("gender").toBool();
        query.prepare("UPDATE scientists SET gender = :gender WHERE id = :id");
        if(gender)
            gender = false;
        else
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
        if(MINYEAR < yob && yob <= MAXYEAR){
            return yob;
        }
        cout << "That is not possible!" << endl;
    }while(true);
}

int service::legalDeath(int yob){
    int yod;
    char input;
    do{
        cout << "Is this amazing person alive(y/n):";
        cin  >> input;
        if(input != 'n' && input != 'y'){
            cout << "Invalid input!" << endl;
        }
    }while(input != 'n' && input != 'y');

    yod = STILLALIVE;
    if(input == 'n'){
        do{
            cout << "Ohhhh I'm sorry, please enter year of death(yyyy): ";
            cin >> yod;
            if(MINYEAR < yod && yod <= MAXYEAR){
                if(yob <= yod){
                return yod;
                }
            }
            cout << "That is not possible!" << endl;
        }while(true);
    }
    return yod;
}

bool service::legalGender(){
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

void service::addComputer(){
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

bool service::editComputer(unsigned int val){
    QSqlQuery query;
    char choice;
    QString name, type;
    int year;
    bool built;
    cout << "1. Name\t\t2. Year\n3. Type\t\t4. Build status" << endl;
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
        if(MINYEAR < year && year <= MAXYEAR){
            return year;
        }
        cout << "That is not possible!" << endl;
    }while(true);
}

bool service::legalBuilt(){
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

unsigned int service::selectUnit(string s){
    unsigned int val = 0;
    for(unsigned int i = 0; i < s.size(); i++){
        if(i == (s.size() - 1))
            val += s[i] - 48;
        else if(i == (s.size() - 2))
            val += (s[i] - 48) * 10;
        else if(i == (s.size() - 3))
            val += (s[i] - 48) * 100;
        else if(i == (s.size() - 4))
            val += (s[i] - 48) * 1000;
        else if(i == (s.size() - 5))
            val += (s[i] - 48) * 10000;
    }
    return val;
}

bool service::isLetter(string s){
    for(unsigned int i = 0; i < s.size(); i++){
        if(isalpha(s[i]))
            return true;
    }
    return false;
}

bool service::checkName(QString &name){
    for(int i = 0; i < name.length(); i++){
        if((name[i].isLower() && i == 0) || (name[i].isLower() && name[i-1] == ' ')){
            name[i] = name[i].toUpper();
        }
        else if(name[i] == ' ' && name[i+1] == ' '){
            name.remove(i, 1);
            i--;
        }
        else if(!name[i].isLetterOrNumber() && name[i] != '\'' && name[i] != ',' && name[i] != '.' && name[i] != '-' && name[i] != ' '){
            cout << "Invalid name!" << endl;
            return false;
        }
    }
    return true;
}

void service::multiSearch(QString &s){
    QString a = s;
    for(unsigned int i = a.length()-1; i > 0; i--){
        a[i+1] = a[i];
    }
    a[1] = s[0];
    a[0] = '%';
    a[a.length()] = '%';
    s = a;
}

bool service::searchScientist(vector<int> &id){
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
        cout << "Is the scientist alive(y/n): ";
        cin >> choice2;
        if(choice2 == 'y')
            yod = 3000;
        else if(choice2 == 'n'){
            cout << "When did the scientist die(If B.C., write \'-\' in front of year): ";
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

bool service::searchComputer(vector<int> &id){
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

void service::addLink(int csid, int cid){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM link WHERE csid = :csid AND cid = :cid");
    query.bindValue(":csid", csid);
    query.bindValue(":cid", cid);
    query.exec();
    query.next();
    unsigned int count = query.value("COUNT(*)").toUInt();
    if(count != 0){
        cout << "This link already excists!" << endl;
    }
    else {
        query.prepare("INSERT INTO link (csid, cid) VALUES (:csid, :cid)");
        query.bindValue(":csid", csid);
        query.bindValue(":cid", cid);
        query.exec();
    }
}
