#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class BankAccount
{
private:
    int acc_number[100];
    string balance[100];
    string acc_type[100];

public:
    string acc_holder_name[100];
    static int accPos; // Declare accPos as a static member variable

    void createAccount();
    void withdrawAmt(int amount);
    void depositAmt();
};

// Define accPos outside the class definition
int BankAccount::accPos = 0;

void BankAccount::createAccount()
{
    string name, account_type;
    char type;
    int startingAmt;

    cout << "Enter your name: " << endl;
    getline(cin, name);
    cout << "Choose Account type ==>\nType [C] for Current Account.\nType [S] for Savings Account." << endl;
    cin >> type;
    switch (type)
    {
    case 'c':
    case 'C':
        account_type = "Current";
        break;
    case 's':
    case 'S':
        account_type = "Savings";
        break;
    default:
        cout << "Invalid Choice!" << endl;
        break;
    }

    int id = accPos;
    acc_number[accPos] = id;

    cout << "Welcome " << name << "!" << endl
         << "Your " << account_type << " account has been created.\n"
         << "Your Account Number is:\t" << id << endl;
    
    accPos++; // Increment accPos after creating an account
}

void BankAccount::depositAmt()
{
    int amount, id;
    cout << "Enter your ID: " << endl;
    cin >> id;
    cout << "Searching your account";
    Sleep(2000);
    cout << ".";
    Sleep(2000);
    cout << ".";
    Sleep(2000);
    cout << "." << endl;
    Sleep(2000);
    string name = acc_holder_name[id];
    cout << "Enter amount to deposit: " << endl;
    cin >> amount;
    balance[id] = to_string(amount); // Convert amount to string for balance
    name = acc_holder_name[id];
    cout << "Added " << amount << " to " << acc_holder_name[id] << "'s account." << endl;
    Sleep(3000);
    system("cls");
}

void BankAccount::withdrawAmt(int amount)
{
    int accNum, amtToDraw;
    cout << "Enter your Account Number: " << endl;
    cin >> accNum;
    cout << "Enter amount withdraw: " << endl;
    cin >> amtToDraw;

    cout << "Successfully withdrawn $" << amtToDraw << "From your Account." << endl;
}

int main()
{
    BankAccount Hari;

    Hari.createAccount();
    Sleep(2000);
    Hari.depositAmt();
    // Hari.withdrawAmt(350);
    return 0;
}
