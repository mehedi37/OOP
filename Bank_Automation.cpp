#include<bits/stdc++.h>
using namespace std;


class Account {
 private:
    int accountNumber;
    int age;
    string accountHolderName;
    double balance;
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
};

class Bank {
 private:
    Account *accounts[10];
    int accountCount;
    string admin_pass = "cpp_is_fun";
 public:
    Bank() {
        accountCount = 0;
    }
    void addAccount(Account *account) {
        cout << "Enter Admin Password: ";
        string password;
        while (cin >> password && password != admin_pass) {
            cout << "Invalid Password (Press 'Q' to quite)\nTry Again : ";
            if (password == "Q" || password == "q") return;
        }
        accounts[accountCount++] = account;
        cout << "\n\n##########################################################\n" << endl;
        cout << "\tYour account has been created successfully !" << endl;
        cout << "\n\n##########################################################\n\n" << endl;
    }
    void displayAll() {
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
            cout << "\n\n##########################################################\n" << endl;
            cout << "\t\tAccount no : " << accountNumber << " not found !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        }
    }
    void deposit(int accountNumber, double amount) {
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                accounts[i]->deposit(amount);
            }
        }
    }
    void withdraw(int accountNumber, double amount) {
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                accounts[i]->withdraw(amount);
            }
        }
    }
    void deleteAccount(int accountNumber) {
        cout << "Enter Admin Password: ";
        string password;
        bool flag{false};
        while (cin >> password && password != admin_pass) {
            cout << "\tInvalid Password (Press 'Q' to quite) !\n\tTry Again : ";
            if (password == "Q" || password == "q") return;
        }
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber && accounts[i]->getBalance() != 0) {
                cout << "\n\n##########################################################\n" << endl;
                cout << "\tSorry ! Can't Delete an account with balance !" << endl;
                cout << "\n\n##########################################################\n\n" << endl;
                return;
            } else if (accounts[i]->getAccountNumber() == accountNumber) {
                accounts[i] = accounts[accountCount - 1];
                accountCount--;
                flag = true;
            }
        }
        if (flag) {
            cout << "\n\n##########################################################\n" << endl;
            cout << "\tAccount no : " << accountNumber << " Deleted Successfully !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        } else {
            cout << "\n\n##########################################################\n" << endl;
            cout << "\t\tAccount no : " << accountNumber << " not found !" << endl;
            cout << "\n\n##########################################################\n\n" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;
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
        } else if (choice == 2) {
            bank.displayAll();
        } else if (choice == 3) {
            int accountNumber;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            bank.displayAccount(accountNumber);
        } else if (choice == 4) {
            int accountNumber;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            cout << "Enter Amount: ";
            cin >> amount;
            bank.deposit(accountNumber, amount);
        } else if (choice == 5) {
            int accountNumber;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            cout << "Enter Amount: ";
            cin >> amount;
            bank.withdraw(accountNumber, amount);
        } else if (choice == 6) {
            int accountNumber;
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            bank.deleteAccount(accountNumber);
        } else if (choice == 7) {
            break;
        }
    }
    return 0;
}
