#include <iostream>
#include <string>
using namespace std;

static int accPos = 0;

class BankAccount
{

private:
    int acc_number[100];
    string balance[100];
    string acc_type[100];

public:
    string acc_holder_name[100];

    void createAccount();
    void withdrawAmt(int amount);
    void depositAmt();
};

void BankAccount ::createAccount()
{

    string name, account_type;
    char type;
    int startingAmt;

    cout << "Enter your name: " << endl;
    cin >> name;
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
    accPos = accPos + 1;

    cout << "Welcome " << name << "!" << endl
         << "Your " << account_type << " account has been created.\n" << "Your Account Number is:\t"<< id <<endl;
}

void BankAccount ::depositAmt()
{
    int amount,id;
    cout << "Enter your ID: " <<endl;
    cin >> id;

    string name =acc_holder_name[id];
    cout << "Enter amount to deposit: " << endl;
    cin >> amount;
    balance[accPos] = amount;
    name = acc_holder_name[accPos];
    cout << "Added " << amount << " to" << name << "'s account." << endl;
}

void BankAccount ::withdrawAmt(int amount)
{
    int accNum, amtToDraw;
    cout << "Enter your Account Number: " << endl;
    cin >> accNum;
    cout << "Enter amount withdraw: " <<endl;
    cin >> amtToDraw;
    if(balance[accNum] < 200){
        cout << "Can't Withdraw!\nYour Balance is less than 200" << endl;
    }else{
        cout << "Successfully withdrawn $"<< amtToDraw << "From your Account." <<endl; 
    }
}

int main()
{
    BankAccount Hari;

    Hari.createAccount();
    Hari.depositAmt();
    Hari.withdrawAmt(350);
    return 0;
}
