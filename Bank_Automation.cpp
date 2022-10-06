/*
MD. Mehedi Hasan Maruf
Dept. of CSE , RUET
2003037


20/09/2022 8:20 PM
*/

#include<bits/stdc++.h>
#include <conio.h>
using namespace std;


class Account {
 private:
    int accountNumber;
    int age;
    string accountHolderName;
    double balance;
    string admin_pass = "sudo";
 public:
    Account(int accountNumber, string accountHolderName, double balance, int age) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
        this->age = age;
    }
    int getAccountNumber() {
        return accountNumber;
    }
    string getAccountHolderName() {
        return accountHolderName;
    }
    double getBalance() {
        return balance;
    }
    int getAge() {
        return age;
    }
    void setAccountNumber(int accountNumber) {
        this->accountNumber = accountNumber;
    }
    void setAccountHolderName(string accountHolderName) {
        this->accountHolderName = accountHolderName;
    }
    void setBalance(double balance) {
        this->balance = balance;
    }
    void setAge(int age) {
        this->age = age;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            system("cls");
            cout << "\n\n#################################################################################\n" << endl;
            cout << "\tSuccessfully withdrew : " << amount << " TK" << endl;
            cout << "\tCurrent Balance is : " << balance << " TK" << endl;
            cout << "\n\n#################################################################################\n\n" << endl;
        } else {
            system("cls");
            cout << "\n\n##########################################################\n" << endl;
            cout << "\tInsufficient Balance !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        }
    }
    void display() {
        cout << "\n\n############### ACCOUNT DETAILS ###############\n\n";
        cout << "\tAccount Number: " << accountNumber << endl;
        cout << "\tAccount Holder Name: " << accountHolderName << endl;
        cout << "\tBalance: " << balance << endl;
        cout << "\tAge: " << age << endl;
        cout << "\n\n############### ACCOUNT DETAILS ###############\n\n";
    }
    bool security() {
        cout << "Enter Admin Password: ";
        char password[32];
        int flag = 4;
        while (flag > 0) {
            int i = 0;
            char a;
            for (i = 0;;) {
                a = getch();
                // Only alphabets and numbers
                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
                    password[i] = a;
                    ++i;
                    cout << "*";
                }
                if (a == '\b' && i >= 1) {
                    cout << "\b \b";  //  rub the character behind the cursor.
                    --i;
                }
                if (a == '\r') {
                    password[i]='\0';
                    break;
                }
            }
            system("cls");
            cout << "Invalid Password (Press 'Q' to quite)\nTry Again : (remaining attempts : " << flag-1 << ")\n";
            if (password == "Q" || password == "q") {flag = 0; break;}
            else if (password == admin_pass) {flag = 1; break;}
            else {flag--;}
        }
        return flag;
    }
};

class Bank {
 private:
    Account *accounts[100];
    int created[100000];
    int accountCount;
    string admin_pass = "sudo";
 public:
    Bank() {
        accountCount = 0;
    }
    void addAccount(Account *account) {
        system("cls");
        if (created[account->getAccountNumber()] == 1) {
            cout << "\n\n##########################################################\n" << endl;
            cout << "\tAccount Already Exists of number: " << account->getAccountNumber() << endl;
            cout << "\n\n##########################################################\n\n" << endl;
            return;
        }
        bool flag = account->security();
        if (flag == 0) {
            system("cls");
            cout << "Too many attempts !\n";
            cout << "Tries : " << flag << endl;
            return;
        } else {
            system("cls");
            accounts[accountCount++] = account;
            created[account->getAccountNumber()] = 1;
            cout << "\n\n##########################################################\n" << endl;
            cout << "\tYour account has been created successfully !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        }

    }
    void displayAll() {
        if (accountCount == 0) {
            cout << "\n\n##########################################################\n" << endl;
            cout << "\tNo Account Found !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
            return;
        }
        for (int i = 0; i < accountCount; i++) {
            accounts[i]->display();
        }
    }
    void displayAccount(int accountNumber) {
        bool flag{false};
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                accounts[i]->display();
                flag = true;
            }
        }
        if (!flag) {
            system("cls");
            cout << "\n\n##########################################################\n" << endl;
            cout << "\t\tAccount no : " << accountNumber << " not found !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        }
    }
    void deposit(int accountNumber, double amount) {
        bool fg{1};
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                accounts[i]->deposit(amount);
                fg = 0;
            }
        }
        if (fg) {
            system("cls");
            cout << "\n\n##########################################################\n" << endl;
            cout << "\t\tAccount no : " << accountNumber << " not found !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        } else {
            system("cls");
            cout << "\n\n######################################################################################################\n" << endl;
            cout << "\t\tAccount no : " << accountNumber << " was successfully credited with : " << amount << " TK" << endl;
            cout << "\n\n#######################################################################################################\n\n" << endl;
        }
    }
    void withdraw(int accountNumber, double amount) {
        bool fg{1};
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                accounts[i]->withdraw(amount);
                fg = 0;
            }
        }
        if (fg) {
            system("cls");
            cout << "\n\n##########################################################\n" << endl;
            cout << "\t\tAccount no : " << accountNumber << " not found !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        }
    }
    void deleteAccount(int accountNumber) {
        system("cls");
        string password;
        bool flag{false};
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber && accounts[i]->getBalance() != 0) {
                bool fg = accounts[i]->security();
                if (fg == 0) {
                    system("cls");
                    cout << "Too many attempts !\n";
                    cout << "Tries : " << fg << endl;
                    return;
                }
                system("cls");
                cout << "\n\n##########################################################\n" << endl;
                cout << "\tSorry ! Can't Delete an account with balance !" << endl;
                cout << "\n\n##########################################################\n\n" << endl;
                return;
            } else if (accounts[i]->getAccountNumber() == accountNumber) {
                bool fg = accounts[i]->security();
                if (fg == 0) {
                    system("cls");
                    cout << "Too many attempts !\n";
                    cout << "Tries : " << fg << endl;
                    return;
                }
                accounts[i] = accounts[accountCount - 1];
                accountCount--;
                created[accountNumber] = 0;
                flag = true;
                if (accounts[i]->getAccountNumber() == accountNumber && accounts[i]->getBalance() != 0) {
                    system("cls");
                    cout << "\n\n##########################################################\n" << endl;
                    cout << "\tSuccessfully Deleted account !" << endl;
                    cout << "\n\n##########################################################\n\n" << endl;
                }
            }
        }
        if (flag) {
            cout << "\n\n##########################################################\n" << endl;
            cout << "\tAccount no : " << accountNumber << " Deleted Successfully !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;

        } else {
            cin.ignore();
            system("cls");
            cout << "\n\n##########################################################\n" << endl;
            cout << "\t\tAccount no : " << accountNumber << " not found !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice = 0;
    system("cls");
    while (true) {
        cout << "\n***************** MAIN MENU *****************" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Display Account" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << "6. Delete Account" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            system("cls");
            int accountNumber;
            string accountHolderName;
            double balance;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            cout << "Enter Account Holder Name: ";
            cin >> accountHolderName;
            cout << "Enter Balance: ";
            cin >> balance;
            cout << "Enter Age: ";
            int age;
            cin >> age;
            Account *account = new Account(accountNumber, accountHolderName, balance, age);
            bank.addAccount(account);
            cin.ignore();
            cin.ignore();
            system("cls");
        } else if (choice == 2) {
            system("cls");
            bank.displayAll();
            cin.ignore();
            cin.ignore();
            system("cls");
        } else if (choice == 3) {
            system("cls");
            int accountNumber;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            bank.displayAccount(accountNumber);
            cin.ignore();
            cin.ignore();
            system("cls");
        } else if (choice == 4) {
            system("cls");
            int accountNumber;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            cout << "Enter Amount: ";
            cin >> amount;
            bank.deposit(accountNumber, amount);
            cin.ignore();
            cin.ignore();
            system("cls");
        } else if (choice == 5) {
            system("cls");
            int accountNumber;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            cout << "Enter Amount: ";
            cin >> amount;
            bank.withdraw(accountNumber, amount);
            // system("cls");
            cin.ignore();
            cin.ignore();
            system("cls");
        } else if (choice == 6) {
            system("cls");
            int accountNumber;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            bank.deleteAccount(accountNumber);
            cin.ignore();
            cin.ignore();
            system("cls");
        } else if (choice == 7) {
            cout << "\n\n##########################################################\n" << endl;
            cout << "\t\t\tThank You !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
            cin.ignore();
            cin.ignore();
            system("cls");
            break;
        }  else {
            cout << "\n\n##########################################################\n" << flush;
            cout << "\t\t\tInvalid Choice" << flush;
            cout << "\n\n##########################################################\n\n" << flush;
            cin.ignore();
            cin.ignore();
            system("cls");
            continue;
        }
    }
    return 0;
}
