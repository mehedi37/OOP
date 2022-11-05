#include<bits/stdc++.h>
using namespace std;

class A {
 public:
    int ax;
    A() {
        cin >> ax;
        cout << "Created A\n";
    }
    int getA() {
        return ax;
    }
    ~A() {
        cout << "A destructed\n";
    }
};

// class B : public A {
class B : public virtual A {
 public:
    int bx;
    B() {
        cin >> bx;
        cout << "Created B\n";
    }
    int getB() {
        return bx;
    }
    ~B() {
        cout << "B destructed\n";
    }
};

// class C : public A {
class C : public virtual A {
 public:
    int cx;
    C() {
        cin >> cx;
        cout << "Created C\n";
    }
    int getC() {
        return cx;
    }
    ~C() {
        cout << "C destructed\n";
    }
};

class D : public B, public C {
 private:
    int dx;
 public:
    D() {
        cin >> dx;
        cout << "Created D\n";
    }
    void sum() {
        cout << getA() + getB() + getC() + dx << endl;
    }
    ~D() {
        cout << "D destructed\n";
    }
};

int main() {
    D d;
    d.sum();
}