#include<bits/stdc++.h>
using namespace std;

class A {
 private:
    int x{8};
 protected:
    int y{37};
 public:
    int z{9};
};

// class B : public A {
class B : public virtual A {
};

// class C : public A {
class C : public virtual A {
};

class D : public B, public C {
 public:
    void get() {
        cout << y << " " << z << endl;
    }
};

int main() {
    D d;
    d.get();
}