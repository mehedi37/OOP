#include<bits/stdc++.h>
using namespace std;

class A {
 private:
    int x;
 protected:
    int y;
 public:
    int z;
    A() : x{1}, y{0}, z{5} {
        cout << "Created A\n";
    }
};

class B : public A {
 public:
    B() {
        cout << "Created B\n";
    }
    void BgetXYZ() {
        // cout << "X : " << x << endl;  // Private
        cout << "y : " << y << endl;
        cout << "z : " << z << endl;
    }
};
class C : public B {
 public:
    C() {
        cout << "Created C\n";
    }
    void CgetXYZ() {
        // cout << "X : " << x << endl;  // Private
        cout << "y : " << y << endl;
        cout << "z : " << z << endl;
    }
};

int main() {
    C c;
    c.CgetXYZ();
    return 0;
}