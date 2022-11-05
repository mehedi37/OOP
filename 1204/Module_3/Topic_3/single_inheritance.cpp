#include<bits/stdc++.h>
using namespace std;

class A {
 private:
    int ax;
 public:
    int get() {
        return ax;
    }
    A() {
        cin >> ax;
        cout << "Created A\n";
    }
    ~A() {
        cout << "A destructed\n";
    }
};

class B : public A {
 private:
    int bx;

 public:
    B() {
        cin >> bx;
        cout << "B created\n";
    }
    void sum() {
        cout << "Sum is : " << bx + get() << endl;
    }
    ~B() {
        cout << "B destructed\n";
    }
};

int main() {
    B b;
    b.sum();
}