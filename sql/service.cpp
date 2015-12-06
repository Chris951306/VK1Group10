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

bool service::checkName(QString s){
    for(unsigned int i = 0; i < s.length(); i++){
        if((islower(s[i]) && i == 0) || (islower(s[i]) && s[i-1] == ' '))
            s[i] = toupper(s[i]);
        else if(s[i] == ' ' && n[i+1] == ' ')
            s.erase(s.begin()+i); i--;
        else if(!islower(s[i])){
            if((isupper(s[i]) && i == 0) || (isupper(s[i]) && s[i-1] == ' '));
            else if((s[i] == '-' && islower(s[i-1])) || s[i] == ',' || s[i] == '.' || s[i] == ' ');
            else if(isalpha(s[i]))
                s[i] = tolower(s[i]);
            else{
                cout << "Invalid name!" << endl;
                return false;
            }
        }
    }
    return true;
}
