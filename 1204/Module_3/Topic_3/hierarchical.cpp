#include<bits/stdc++.h>
using namespace std;

class A {
 public:
    int ax;
    A() {
        cin >> ax;
        cout << "Created A\n";
    }
    ~A() {
        cout << "A destructed\n";
    }
};

class B : public A {
 public:
    int bx;
    B() {
        cin >> bx;
        cout << "Created B\n";
    }
    void sum() {
        cout << ax+bx << endl;
    }
    ~B() {
        cout << "B destructed\n";
    }
};
class C : public A {
 public:
    int cx;
    C() {
        cin >> cx;
        cout << "Created C\n";
    }
    void sum() {
        cout << ax+cx << endl;
    }
    ~C() {
        cout << "C destructed\n";
    }
};

int main() {
    B b;
    C c;
    b.sum();
    c.sum();
}