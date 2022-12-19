#include<bits/stdc++.h>
using namespace std;
#define cl "cls"


class employee {
 private:
    string name{""};
    int Emp_Code{0};
    int salary{0};
    int age{0};

 public:
    void setData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter employee code: ";
        cin >> Emp_Code;
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter age: ";
        cin >> age;
    }
    void setData(string n, int ec, int salary, int age) {
        this->name = n;
        this->Emp_Code = ec;
        this->salary = salary;
        this->age = age;
        // cout << "Hello world - Employee\n";
    }
    void dis() {
        cout << "\nName : " << this->name << endl;
        cout << "Employee Code : " << this->Emp_Code << endl;
        cout << "Salary : " << this->salary << endl;
        cout << "Age : " << this->age << endl;
        cin.ignore();
    }
    int getID() {
        return Emp_Code;
    }
    string getName() {
        return name;
    }
};

class manager : public employee {
 private:
    employee * me;
    employee * eArray[10];
    int empCount{0};

 public:
    manager() {
        me = new employee();
        me->setData();
    }
    void disManShort() {
        cout << me->getName() << " " << me->getID() << endl;
    }
    int getID() {
        return me->getID();
    }

    void disMan() {
        cout << "Manager Details\n";
        me->dis();
        cout << "\nHis Employee Details\n";
        for (int i{0}; i < empCount; i++) {
            eArray[i]->dis();
        }
    }
    void add() {
        eArray[empCount++] = new employee();
    }
    void add(string n, int ec, int salary, int age) {
        eArray[empCount++] = new employee();
        eArray[empCount-1]->setData(n, ec, salary, age);
    }
    void add(employee * e) {
        eArray[empCount++] = e;
    }
    void remove(int id) {
        int pos = search(id);
        if (eArray[pos]->getID() != -1) {
            eArray[pos] = eArray[empCount-1];
            eArray[empCount-1] = NULL;
            empCount--;
            return;
        }
        cout << "Employee is not working under me !\n";
    }
    int search(int empID) {
        for (int i{0}; i < empCount; i++) {
            if (eArray[i]->getID() == empID)
                return i;
        }
        return -1;
    }
    void transfer(manager * m, int empID) {
        int pos = search(empID);
        if (eArray[pos]->getID() != -1) {
            m->add(eArray[pos]);
            eArray[pos] = eArray[empCount-1];
            eArray[empCount-1] = NULL;
            empCount--;
            return;
        }
        cout << "Employee is not working under me !\n";
    }
};




manager * noBody[100];
employee * someBody[100];
int managerCnt{0}, employeeCnt{0};

int findManager(int id) {
    for (int i{0}; i < managerCnt; i++) {
        if (noBody[i]->getID() == id) {
            return i;
        }
    }
    return -1;
}
int findEmployee(int id) {
    for (int i{0}; i < employeeCnt; i++) {
        if (someBody[i]->getID() == id) {
            return i;
        }
    }
    return -1;
}

void manShow() {
    for (int i{0}; i < managerCnt; i++) {
        noBody[i]->disManShort();
    }
}


int main() {
    while (true) {
        system(cl);
        int choose;
        cout << "1) Add Manager\n";
        cout << "2) Add Employee\n";
        cout << "3) Show Manager Details\n";
        cout << "4) Show Employee Details\n";
        cout << "5) Set Employee under Manager\n";
        cout << "6) Transfer employee to Another Manager\n";
        cout << "7) Fire an Employee\n";
        cout << "8) Exit\n";
        cin >> choose;
        int mID, eID, tmID, mpos, epos, tmpos;
        switch (choose) {
        case 1:
            noBody[managerCnt++] = new manager();
            break;
        case 2:
            someBody[employeeCnt++] = new employee();
            someBody[employeeCnt-1]->setData();
            break;
        case 3:
            cout << "Enter Manager ID: ";
            cin >> mID;
            mpos = findManager(mID);
            if (mpos == -1) {
                cout << "Manager not found\n";
                break;
            }
            system(cl);
            noBody[mpos]->disMan();
            cin.ignore();
            break;
        case 4:
            cout << "Enter Employee ID: ";
            cin >> eID;
            epos = findEmployee(eID);
            if (epos == -1) {
                cout << "Employee not found\n";
                break;
            }
            system(cl);
            someBody[epos]->dis();
            cin.ignore();
            break;
        case 5:
            system(cl);
            manShow();
            cout << "Enter Manager ID: ";
            cin >> mID;
            cout << "Enter Employee ID: ";
            cin >> eID;
            epos = findEmployee(eID), mpos = findManager(mID);
            if (mpos == -1 || epos == -1) {
                cout << "Data not found\n";
                break;
            }
            noBody[mpos]->add(someBody[epos]);
            break;
        case 6:
            system(cl);
            manShow();
            cout << "Enter Current Manager ID: ";
            cin >> mID;
            cout << "Enter Employee ID: ";
            cin >> eID;
            cout << "Transfer to Manager: ";
            cin >> tmID;
            mpos = findManager(mID), tmpos = findManager(tmID);
            if (mpos == -1 || tmpos == -1) {
                cout << "Data not found\n";
                break;
            }
            noBody[mpos]->transfer(noBody[tmpos], eID);
            break;
         case 7:
            system(cl);
            manShow();
            cout << "Enter Manager ID: ";
            cin >> mID;
            cout << "Enter Employee ID: ";
            cin >> eID;
            mpos = findManager(mID);
            if (mpos == -1) {
                cout << "Data not found\n";
                break;
            }
            noBody[mpos]->remove(eID);
            break;
        }
        if (choose == 8) {
            system(cl);
            cout << "\t\t# TATA :)\n";
            cin.ignore();
            cin.ignore();
            break;
        }
    }
}