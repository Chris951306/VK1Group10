#include "scientist.h"

const int MinYear = -1000;
const int MaxYear = 2015;
const int StillAlvie = 3000; //value that makes the program know that a person is still alive

scientist::scientist(){

}

unsigned int scientist::size(){
    return this->size();
}

void scientist::readInfo(){  //function that reads the info (name, gender, birthyear and year of death) about the scientists.
    char gender;
    char alive;
    bool valid = false;
    cout << "Enter name: ";
    cin >> this->name;
    do{     //makes sures that the input is either female or male
        valid = false;
        cout << "Enter gender(m/f): ";
        cin >> gender;
        if(gender == 'm'){
            this->gender = false;
            valid = true;
        }
        else if(gender == 'f'){
            this->gender = true;
            valid = true;
        }
        else
            cout << "Invalid input!" << endl;
    }while(!valid);

    do{
        valid = false;
        cout << "Enter year of birth(yyyy): ";
        cin >> this->yob;
        valid = legalBirth(yob); //uses bool function legalBirth which returns true if yob (year of birth) is a legalBirth
    }while(!valid);

    do{  // makes sures that the input is y (yes) or n (no)
        cout << "Is this amazing person alive(y/n):";
        cin  >> alive;
        if(alive != 'n' && alive != 'y'){
            cout << "Invalid input! Didn't you understand the instruction or are you just trolling... ENTER AGAIN: " << endl;
        }
    }while(alive != 'n' && alive != 'y');
    this->yod = StillAlive;
    if(alive == 'n'){
        do{
            valid = false;
            cout << "Ohhhh I'm sorry, please enter year of death(yyyy): ";
            cin >> this->yod;
            valid = legalDeath(yob, yod); //uses bool function legalDeath which returns true if yod (year of death) is a legalDeath
        }while(!valid);
    }
}

void scientist::editInfo(){ //
    bool go = false;
    char choice;
    do{
        go = false;
        cout << "Enter a number for your choice. Any other inputs return you to menu." << endl;
        cout << endl;
        cout << *this;
        cout << endl;
        cout << "1. Name\t\t\t2. Gender\n3. Year of birth\t4. Year of death" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if(choice == '1'){
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, this->name);
            go = true;
        }
        else if(choice == '2'){
            if(this->gender)
                this->gender = false;
            else
                this->gender = true;
            go = true;
        }
        else if(choice == '3'){
            bool valid = false;
            do{
                valid = false;
                cin >> this->yob;
                valid = legalBirth(yob);
            }while(!valid);
            go = true;
        }
        else if(choice == '4'){
            bool valid = false;
            char alive;
            do{
                cout << "So.... Is this person alive(y/n)? ";
                cin  >> alive;
                if(alive != 'y' && alive != 'n'){
                    cout << "Invalid input!" << endl;
                }
            }while(alive != 'y' && alive != 'n');
            this->yod = StillAlive;
            do{
                valid = true;
                if(alive == 'n'){
                    cout << "Invalid input! Didn't you understand the instruction or are you just trolling... ENTER AGAIN: " << endl;
                    cin >> this->yod;

                    valid = legalDeath(yob, yod);
                }
            }while(!valid);
            go = true;
        }
    }while(go);
}

bool scientist::legalBirth(int yob){
    if(MinYear < yob && yob <= MaxYear){
        return true;
    }
    cout << "That is not possible! Try again:" << endl;
    return false;
}

bool scientist::legalDeath(int yob, int yod){
    if(MinYear < yod && yod <= MaxYear){
        if(yob <= yod){
        return true;
        }
    }
    cout << "Why is this world so cruel? When did the scientist die? :´( ";
    return false;
}

ostream& operator<<(ostream& stream, const scientist &s){
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

string retName(scientist &s){
    return s.name;
}

void viewInfo(vector<scientist> &s){
    char choice;
    bool go = false;
    do{
        go = false;
        cout << "Enter a number for your choice. Any other inputs return you to menu." << endl;
        cout << endl;
        if(s.size() == 0){
            cout << "There are no scientists stored!" << endl;
        }
        else{
            for(unsigned int i = 0; i<s.size(); i++)
                cout << s[i] << endl;
            cout << "1. Sort by name\t2. Sort by gender\n3. Sort by year of birth" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            if(choice == '1'){
                vector<string> v;
                for(unsigned int i = 0; i < s.size(); i++){
                    v.push_back(s[i].name);
                }
                sort(v.begin(), v.end());
                for(unsigned int i=0; i < v.size(); i++){
                    for(unsigned int j = 0; j < s.size(); j++){
                        if(v[i] == s[j].name){
                            swap(s[i].name, s[j].name);
                            swap(s[i].gender, s[j].gender);
                            swap(s[i].yob, s[j].yob);
                            swap(s[i].yod, s[j].yod);
                        }
                    }
                }
                go = true;
            }
            else if(choice == '2'){
                bool swapped = false;
                do{
                    swapped = false;
                    for(unsigned int i=1; i < s.size(); i++){
                        if(!s[i-1].gender && s[i].gender){
                            swap(s[i-1].name, s[i].name);
                            swap(s[i-1].gender, s[i].gender);
                            swap(s[i-1].yob, s[i].yob);
                            swap(s[i-1].yod, s[i].yod);
                            swapped = true;
                        }
                    }
                }while(swapped);
                go = true;
            }
            else if(choice == '3'){
                bool swapped = false;
                do{
                    swapped = false;
                    for(unsigned int i=1; i < s.size(); i++){
                        if(s[i-1].yob > s[i].yob){
                            swap(s[i-1].name, s[i].name);
                            swap(s[i-1].gender, s[i].gender);
                            swap(s[i-1].yob, s[i].yob);
                            swap(s[i-1].yod, s[i].yod);
                            swapped = true;
                        }
                    }
                }while(swapped);
                go = true;
            }
        }
    }while(go);
}

void saveInfo(vector<scientist> &s){
    ofstream save("scientists.txt", ofstream::out);
    save << s.size();
    for(unsigned int i = 0; i < s.size(); i++){
        save << s[i].name << endl;
        save << s[i].gender << endl;
        save << s[i].yob << endl;
        save << s[i].yod << endl;
    }
    save.close();
}

void loadInfo(vector<scientist> &s){
    ifstream load("scientists.txt");
    scientist temp;
    unsigned int n;
    string a;
    bool b;
    int c;
    int d;
    load >> n;
    while(n > 0)
    {
        int te = 4;
        while(te > 0){
        getline(load, a);
            if(te == 4){
                load >> a;
                temp.name = a;
                //load >> a;
                //temp.name += a;
            }

            else if(te == 3) {
                load >> b;
                temp.gender = b;
            }

            else if(te == 2) {
                load >> c;
                temp.yob = c;
            }

            else if(te == 1) {
                load >> d;
                temp.yod = d;
            }
            te--;
        }
        //cout << a << " " << b << " " << c << " " << d << endl;
        cout << temp.name << " " << temp.gender << " " << temp.yob << " " << temp.yod << endl;

        s.push_back(temp);
        n--;
    }

    if(s.size() > 0)
        cout << endl << "!All entries are loaded from database!" << endl;
}

void delInfo(vector<scientist> &s){
    unsigned int choice;
    bool go = false;
    for(unsigned int i=0; i<s.size(); i++){
        cout << i+1 << ": " << s[i] << endl;
    }
    cout << "Enter scientist number to delete(To return to menu, type \'0\'): ";
    cin >> choice;
    do{
        go = false;
        if(choice >= (s.size()+1)){
            cout << "Invalid input! Didn't you understand the instruction or are you just trolling... ENTER AGAIN: " << endl;
            cin >> choice;
            go = true;
        }
        else{
            if(choice != 0){
                for(unsigned int i=0; i<s.size(); i++){
                    if(choice == i+1)
                    {
                        s.erase(s.begin()+i);
                    }

                }
            }
        }
    }while(go);
}
