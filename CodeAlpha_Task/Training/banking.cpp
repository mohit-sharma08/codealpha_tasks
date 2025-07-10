#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> logs;
int PIN, pin;

class Account{
public:
    int Create();
    int Balance(int, int);
    int TransactionDetail();
};

class Transaction{
public:
    int FundTransfer(int, int);
    int Deposit(int);
    int Withdraw(int, int);
    int History();
};

int main(){
    Account a;
    Transaction t;
    int n, x;

    cout << "\n=== BANKING MENU ===\n";
    cout << "1: Create an Account\n";
    cout << "2: Check the Balance\n";
    cout << "3: Transaction Details\n";
    cout << "4: Transfer the Fund\n";
    cout << "5: Deposit Money\n";
    cout << "6: Withdraw the Amount\n";
    cout << "7: Check the Recent Transaction History\n";
    cout << "8: Exit\n";

    if (n == 1){
        a.Create();
    }else{
        x = 10000;
        PIN = 1234;
    }

    do{
        cout << "Your Choice : ";
        cin >> n;
        
        switch (n){
            case 1: 
                x = a.Create();
                break;
            case 2:
                x = a.Balance(x, PIN);
                break;
            case 3:
                a.TransactionDetail();
                break;
            case 4:
                x = t.FundTransfer(x, PIN);
                break;
            case 5:
                x = t.Deposit(x);
                break;
            case 6:
                x = t.Withdraw(x, PIN);
                break;
            case 7:
                t.History();
                break;
            case 8:
                exit(1);
        }
    } while (n < 8);
    return -1;
}

int Account::Create(){
    string name, fname, mname, dob;
    double phn, aadhar;
    int deposit;
    struct residance{
    public:
        int hno, stno;
        string area, city, state, country;
        void input(){
            cin >> hno;
            cin >> stno;
            cin >> area;
            cin >> city;
            cin >> state;
            cin >> country;
        }
    };
    residance r;
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your Father's name: ";
    getline(cin, fname);
    cout << "Enter your Mother's name: ";
    getline(cin, mname);
    cout << "Enter your Date of Birth (DD/MM/YYYY): ";
    getline(cin, dob);
    cout << "Enter your Phone no.: ";
    cin >> phn;
    cout << "Enter your Aadhar Number: ";
    cin >> aadhar;
    cout << "Enter your Residance: ";
    r.input();
    cout << "Enter your PIN no.: ";
    cin >> PIN;
    cout << "Enter your Deposit: ";
    cin >> deposit;
    logs.push_back("Account created with "+ to_string(deposit) +" deposit");
    return deposit;
}

int Account::Balance(int x, int PIN){
    for (int i = 1; i < 4; i++){
        cout << "Enter PIN: ";
        cin >> pin;
        if (pin == PIN){
            cout << "Balance amount is " << x << endl;
            return x;
        }
        else if (pin < 1000 || pin > 9999){
            cout << "PIN can only be of 4 digits.Try again\n";
        }
        else{
            cout << "Entered wrong PIN attempt no. " << i << ".Try again\n";
        }
    }
    return -1;
}

int Account::TransactionDetail(){
    if(logs.empty()){
        cout<< "No transaction occured yet!!\n";
    }else{
        cout << "Last transaction: " << logs.back() << endl;
    }
    return -1;
}

int Transaction::FundTransfer(int x, int PIN){
    int ac, n, a = 0;
    cout << "Enter the account number u want to transfer money: ";
    cin >> ac;
    cout << "Enter the amount: ";
    cin >> n;
    for (int i = 1; i < 4; i++){
        cout << "Enter PIN: ";
        cin >> pin;
        if (pin == PIN){
            if (x >= n){
                x -= n;
                a += n; // receiver's principal money
                cout << "Fund transfer successfully\n";
                logs.push_back(to_string(n) + " Rs. transfered from your account to "+ to_string(ac));
                break;
            }
            else{
                cout << " Not sufficient balance";
                logs.push_back("Money transfer cancelled. Don't have sufficient balance in your account ");
                break;
            }
        }else if (pin < 1000 || pin > 9999){
            cout << "PIN can only be of 4 digits.Try again\n";
        }
        else{
            cout << "Entered wrong PIN attempt no. " << i << ".Try again\n";
        }
    }
    return x;
}

int Transaction::Deposit(int x){
    int n;
    cout << "Enter the amount you wanna deposit: ";
    cin >> n;
    x += n;
    logs.push_back(to_string(n) + " Rs. deposited in your account");
    return x;
}

int Transaction::Withdraw(int x, int PIN){
    int w;
    cout << "Enter the amount to be withdrawn: ";
    cin >> w;
    for (int i = 1; i < 4; i++){
        cout << "Enter PIN: ";
        cin >> pin;
        if (pin == PIN){
            if (x >= w){
                x -= w;
                cout << "Money withdrawn successfully\n";
                logs.push_back(to_string(w) + " Rs. withdrawn from your account");
                return x;
            }else
                cout << " Not sufficient balance";
                logs.push_back("Money withdrawn cancelled. Don't have enough balance");
        }else if (pin < 1000 || pin > 9999){
            cout << "PIN can only be of 4 digits.Try again\n";
        }
        else{
            cout << "Entered wrong PIN attempt no. " << i << ".Try again\n";
        }
    }
    return x;
}

int Transaction::History(){
    if(logs.empty()){
        cout<< "No transaction occured yet!!";
    }else{
        cout << "All the transactions are: \n";
        for(int i=0; i< logs.size(); i++){
            cout<< i+1 <<". "<< logs[i] << endl;
        }
    }
}