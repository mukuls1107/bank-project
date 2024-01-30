#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class BankAccount
{
private:
    static const int MAX_ACCOUNTS = 100;
    int acc_number[MAX_ACCOUNTS];
    double balance[MAX_ACCOUNTS];
    string acc_type[MAX_ACCOUNTS];
    string acc_holder_name[MAX_ACCOUNTS];
    int accPos;

public:
    BankAccount() : accPos(0) {} // Constructor to initialize accPos

    void createAccount();
    void depositAmt();
    void withdrawAmt();
    void showBalance();
    void displayAccounts();
};

void BankAccount::createAccount()
{
    string name, account_type;
    char type;
    system("cls");
    cout << "Please Wait..." << endl;
    Sleep(2000);
    cin.ignore();
    system("cls");

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Choose Account type:\nType [C] for Current Account.\nType [S] for Savings Account: ";
    cin >> type;
    type = toupper(type);

    switch (type)
    {
    case 'C':
        account_type = "Current";
        break;
    case 'S':
        account_type = "Savings";
        break;
    default:
        cout << "Invalid Choice!" << endl;
        return;
    }

    acc_number[accPos] = accPos; // Assign account number
    acc_holder_name[accPos] = name;
    acc_type[accPos] = account_type;

    cout << "Welcome " << name << "!" << endl
         << "Your " << account_type << " account has been created." << endl
         << "Your Account Number is: " << accPos << endl;

    accPos++; // Increment account position for the next account
    Sleep(3000);
    system("cls");
}

void BankAccount::depositAmt()
{
    int id;
    cout << "Enter your Account Number: ";
    cin >> id;

    if (id < 0 || id >= accPos)
    {
        cout << "Invalid Account Number!" << endl;
        return;
    }

    double amount;
    cout << "Enter amount to deposit: $";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid deposit amount!" << endl;
        return;
    }

    balance[id] += amount;

    cout << "Deposited $" << amount << " to " << acc_holder_name[id] << "'s account." << endl;
    Sleep(3000);
    system("cls");
}

void BankAccount::withdrawAmt()
{
    int id;
    cout << "Enter your Account Number: ";
    cin >> id;

    if (id < 0 || id >= accPos)
    {
        cout << "Invalid Account Number!" << endl;
        return;
    }

    double amount;
    cout << "Enter amount to withdraw: $";
    cin >> amount;

    if (amount <= 0 || amount > balance[id])
    {
        cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        return;
    }

    balance[id] -= amount;

    cout << "Withdrawn $" << amount << " from " << acc_holder_name[id] << "'s account." << endl;
    Sleep(3000);
    system("cls");
}

void BankAccount::displayAccounts()
{
    cout << "---------------------------------------------" << endl;
    cout << "ID\tName\t\tBalance" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < accPos; ++i)
    {
        cout << acc_number[i] << "\t" << acc_holder_name[i] << "\t\t$" << balance[i] << endl;
    }

    cout << "---------------------------------------------" << endl;
}

void BankAccount::showBalance()
{
    int id;
    cout << "Enter your Account Number: ";
    cin >> id;

    if (id < 0 || id >= accPos)
    {
        cout << "Invalid Account Number!" << endl;
        return;
    }

    cout << "Balance for Account Number " << id << ": $" << balance[id] << endl;
    Sleep(3000);
    system("cls");
}

int main()
{
    int password;
    Sleep(3000);
    cout << "Starting the program..." << endl;
    Sleep(2000);
    system("cls");
    BankAccount accounts;

    char choice;
    do
    {
        cout << "\n\t=======\tMenu\t=======:\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Show Balance\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            accounts.createAccount();
            break;
        case '2':
            accounts.depositAmt();
            break;
        case '3':
            accounts.withdrawAmt();
            break;
        case '4':
            accounts.showBalance();
            break;
        case '5':
            cout << "Exiting program.\n";
            break;
        case 'a':
        case 'A':
            cout << "Enter password: ";
            cin >> password;
            if (password != 3078)
            {
                cout << "Invalid Access!"
                     << "Flushing the data ..." << endl;
                exit(1);
            }
            else
            {
                accounts.displayAccounts();
            }
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != '5');

    return 0;
}