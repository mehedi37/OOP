#include<bits/stdc++.h>
using namespace std;

class A {
 public:
    virtual void print() = 0;
};
class B : public A {
 public:
     void print() {
        cout << "Inside Print() of class B\n";
    }
};

int main() {
    // A a;              // Pure virtual function
    // a.print();       // Abstract class
    // B b;
    // b.print();       // From B
    // A a;
    // A *p;
    // p = &a;
    // p->print();      // From A
    B b;
    A *p;
    p = &b;
    p->print();         // From A
                        // From B in virtual
}