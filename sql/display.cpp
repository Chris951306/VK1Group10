#include "display.h"

void display::printCStop(){
    cout << setfill(' ') << right << setw(4) << "#" << left << setw(2) << "" << left << setw(25) << "Name" << left << setw(12) << "Gender";
    cout << setfill(' ') << left << setw(14) << "Birth" << left << "Death" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(63) << "" << endl;
}

void display::printCSbot(){
    QSqlQuery bot;
    bot.exec("SELECT COUNT(id) FROM scientists");
    bot.next();
    unsigned int count = bot.value("COUNT(id)").toUInt();
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(63) << "" << endl;
    cout << setfill(' ') << setw(3) << "" << "Total amount of scientists: " << count << endl << endl;
}

void display::printCtop(){
    cout << setfill(' ') << right << setw(4) << "#" << left << setw(2) << "" << left << setw(30) << "Name" << left << setw(12) << "Year";
    cout << setfill(' ') << left << setw(18) << "Type" << left << "Build status" << endl;
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(75) << "" << endl;
}

void display::printCbot(){
    QSqlQuery bot;
    bot.exec("SELECT COUNT(id) FROM computers");
    bot.next();
    unsigned int count = bot.value("COUNT(id)").toUInt();
    cout << setfill(' ') << setw(3) << "" << setfill('-') << setw(75) << "" << endl;
    cout << setfill(' ') << setw(3) << "" << "Total amount of computers: " << count << endl << endl;
}

void display::printScientists(){
    printCStop();
    QSqlQuery query;
    query.exec("SELECT * FROM scientists");
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        bool gender = query.value("gender").toBool();
        int yob = query.value("yob").toInt();
        int yod = query.value("yod").toInt();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(25) << name;
        if(gender)
            cout << left << setw(12) << "Male";
        else
            cout << left << setw(12) << "Female";
        if(yob < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yob) << " B.C. --> ";
        }
        else{
            cout << right << setfill('0') << setw(4) << yob << " A.D. --> ";
        }

        if(yod == STILLALIVE){
            cout << "Alive";
        }
        else if(yod < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yod) << " B.C.";
        }
        else{
            cout << right << setfill('0') << setw(4) << yod << " A.D.";
        }
        cout << endl;
    }
    printCSbot();
}

void display::printScientist(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT * FROM scientists WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        bool gender = query.value("gender").toBool();
        int yob = query.value("yob").toInt();
        int yod = query.value("yod").toInt();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(25) << name;
        if(gender)
            cout << left << setw(12) << "Male";
        else
            cout << left << setw(12) << "Female";
        if(yob < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yob) << " B.C. --> ";
        }
        else{
            cout << right << setfill('0') << setw(4) << yob << " A.D. --> ";
        }

        if(yod == STILLALIVE){
            cout << "Alive";
        }
        else if(yod < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yod) << " B.C.";
        }
        else{
            cout << right << setfill('0') << setw(4) << yod << " A.D.";
        }
    }
}

bool display::sortScientist(bool &namesort, bool &gendersort, bool &yobsort){
    QSqlQuery query;
    char choice;
    cout << "1. Sort by name\t\t2. Sort by gender\t3. Sort by year of birth" << endl;
    cout << "Same option twice sorts opposite." << endl;
    cout << "Enter choice: ";
    cin  >> choice;

    if(choice == '1'){
        cout << endl;
        printCStop();
        if(namesort){
            query.exec("SELECT * FROM scientists ORDER BY name DESC");
            query.exec();
            namesort = false;
        }
        else{
            query.exec("SELECT * FROM scientists ORDER BY name");
            query.exec();
            namesort = true;
        }
    }
    else if(choice == '2'){
        cout << endl;
        printCStop();
        if(gendersort){
            query.exec("SELECT * FROM scientists ORDER BY gender DESC");
            query.exec();
            gendersort = false;
        }
        else{
            query.exec("SELECT * FROM scientists ORDER BY gender");
            query.exec();
            gendersort = true;
        }
    }
    else if(choice == '3'){
        cout << endl;
        printCStop();
        if(yobsort){
            query.exec("SELECT * FROM scientists ORDER BY yob DESC");
            query.exec();
            yobsort = false;
        }
        else{
            query.exec("SELECT * FROM scientists ORDER BY yob");
            query.exec();
            yobsort = true;
        }
    }
    else{
        return false;
    }
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        bool gender = query.value("gender").toBool();
        int yob = query.value("yob").toInt();
        int yod = query.value("yod").toInt();
        cout << right << setfill(' ') << setw(4) << id << ": ";
        cout << left << setfill(' ') << setw(25) << name;
        if(gender)
            cout << left << setw(12) << "Male";
        else
            cout << left << setw(12) << "Female";
        if(yob < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yob) << " B.C. --> ";
        }
        else{
            cout << right << setfill('0') << setw(4) << yob << " A.D. --> ";
        }

        if(yod == STILLALIVE){
            cout << "Alive";
        }
        else if(yod < 0)
        {
            cout << right << setfill('0') << setw(4) << abs(yod) << " B.C.";
        }
        else{
            cout << right << setfill('0') << setw(4) << yod << " A.D.";
        }
        cout << endl;
    }
    printCSbot();
    return true;
}

void display::printComputers(){
    printCtop();
    QSqlQuery query;
    query.exec("SELECT * FROM computers");
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int year = query.value("year").toInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
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

        cout << endl;
    }
    printCbot();
}

void display::printComputer(unsigned int val){
    QSqlQuery query;
    query.prepare("SELECT * FROM computers WHERE id = :id");
    query.bindValue(":id", val);
    query.exec();
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int year = query.value("year").toInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
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
}

bool display::sortComputers(bool &namesort, bool &yearsort, bool &typesort, bool &builtsort){
    QSqlQuery query;
    char choice;
    cout << "1. Sort by name\t\t\t2. Sort by year\n3. Sort by type\t\t\t4. Sort by built or not" << endl;
    cout << "Same option twice sorts opposite." << endl;
    cout << "Enter choice: ";
    cin  >> choice;

    if(choice == '1'){
        cout << endl;
        printCtop();
        if(namesort){
            query.exec("SELECT * FROM computers ORDER BY name DESC");
            query.exec();
            namesort = false;
        }
        else{
            query.exec("SELECT * FROM computers ORDER BY name");
            query.exec();
            namesort = true;
        }
    }
    else if(choice == '2'){
        cout << endl;
        printCtop();
        if(yearsort){
            query.exec("SELECT * FROM computers ORDER BY year DESC");
            query.exec();
            yearsort = false;
        }
        else{
            query.exec("SELECT * FROM computers ORDER BY year");
            query.exec();
            yearsort = true;
        }
    }
    else if(choice == '3'){
        cout << endl;
        printCtop();
        if(typesort){
            query.exec("SELECT * FROM computers ORDER BY type DESC");
            query.exec();
            typesort = false;
        }
        else{
            query.exec("SELECT * FROM computers ORDER BY type");
            query.exec();
            typesort = true;
        }
    }
    else if(choice == '4'){
        cout << endl;
        printCtop();
        if(builtsort){
            query.exec("SELECT * FROM computers ORDER BY built DESC");
            query.exec();
            builtsort = false;
        }
        else{
            query.exec("SELECT * FROM computers ORDER BY built");
            query.exec();
            builtsort = true;
        }
    }
    else{
        return false;
    }
    while(query.next()){
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int year = query.value("year").toInt();
        string type = query.value("type").toString().toStdString();
        bool built = query.value("built").toBool();
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

        cout << endl;
    }
    printCbot();
    return true;
}

void display::printCStoC(){
    unsigned int n, m, csid, cid;
    string csname, cname;
    QSqlQuery query;
    query.exec("SELECT MAX(id) FROM scientists");
    query.next();
    n = query.value("MAX(id)").toUInt();
    for(unsigned int i = 1; i <= n; i++){
        cout << endl;
        query.exec("SELECT id, name FROM scientists");
        for(unsigned int j = 0; j < i; j++)
            query.next();
        csname = query.value("name").toString().toStdString();
        csid = query.value("id").toUInt();
        cout << "   " << csname << ":" << endl;
        query.prepare("SELECT COUNT(cid) FROM link WHERE csid = :id");
        query.bindValue(":id", csid);
        query.exec();
        query.next();
        m = query.value("COUNT(cid)").toUInt();
        for(unsigned int k = 1; k <= m; k++){
            query.prepare("SELECT cid FROM link WHERE csid = :id");
            query.bindValue(":id", csid);
            query.exec();
            for(unsigned int l = 0; l < k; l++)
                query.next();
            cid = query.value("cid").toUInt();
            query.prepare("SELECT name FROM computers WHERE id = :id");
            query.bindValue(":id", cid);
            query.exec();
            query.next();
            cname = query.value("name").toString().toStdString();
            cout << "\t- " << cname << endl;
        }
    }
}

void display::printCtoCS(){
    unsigned int n, m, csid, cid;
    string csname, cname;
    QSqlQuery query;
    query.exec("SELECT MAX(id) FROM computers");
    query.next();
    n = query.value("MAX(id)").toUInt();
    for(unsigned int i = 1; i <= n; i++){
        cout << endl;
        query.exec("SELECT id, name FROM computers");
        for(unsigned int j = 0; j < i; j++)
            query.next();
        cname = query.value("name").toString().toStdString();
        cid = query.value("id").toUInt();
        cout << "   " << cname << ":" << endl;
        query.prepare("SELECT COUNT(csid) FROM link WHERE cid = :id");
        query.bindValue(":id", cid);
        query.exec();
        query.next();
        m = query.value("COUNT(csid)").toUInt();
        for(unsigned int k = 1; k <= m; k++){
            query.prepare("SELECT csid FROM link WHERE cid = :id");
            query.bindValue(":id", cid);
            query.exec();
            for(unsigned int l = 0; l < k; l++)
                query.next();
            csid = query.value("csid").toUInt();
            query.prepare("SELECT name FROM scientists WHERE id = :id");
            query.bindValue(":id", csid);
            query.exec();
            query.next();
            csname = query.value("name").toString().toStdString();
            cout << "\t- " << csname << endl;
        }
    }
}

