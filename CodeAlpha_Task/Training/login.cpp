#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int user_exist(string user){
    string line, s_user;
    ifstream file("user.txt");
    while(getline(file, line)){
        size_t sep = line.find(':');
        s_user = line.substr(0, sep);//stored username
        if(s_user == user){
            return true;
        }
    }return false;
}

void login(){
    string user, pass;
    cout << "Enter the username: ";
    cin >> user ;
    cout << "Enter the Password: ";
    cin >> pass ;
    string line, s_user, s_hash;
    ifstream file("user.txt");
    while(getline(file, line)){
        size_t sep = line.find(':');
        s_user = line.substr(0, sep);//stored username
        s_hash = line.substr(sep + 1);
        if(s_user == user){
            if(s_hash == pass){
                cout<< "Login Successfully.\n";
            }else
                cout<< "Wrong Password. Try again!!\n";
            return;
        }
    }
    cout<< "Username not found.\n";
}

void Register(){
    string user, pass;
    cout << "Enter the username: ";
    cin >> user ;
    cout << "Enter the Password: ";
    cin >> pass ;
    string line, s_user, s_hash;
    if(user_exist(user)){
        cout << "Registration failed: Already used. Get another username.\n";
        return;
    }
    ofstream file("user.txt");
    file << user << ":" << pass << endl;
    file.close();
    cout<< "Registered Successfully.\n";
}

int main(){
    int choice;
    do{
        cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: Register(); break;
            case 2: login(); break;
            case 3: return 0;
            default: cout << "Invalid option.\n";
        }
    }while(choice < 3);
    return 0;
}
