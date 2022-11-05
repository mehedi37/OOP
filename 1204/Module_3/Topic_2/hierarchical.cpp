#include<bits/stdc++.h>
using namespace std;

class A {
 private:
    int x{0};
 protected:
    int y{1};
 public:
    int z{3};
};

class B : public A {
 public:
    void get() {
        cout << "Inside B\n";
        cout << y << " " << z << endl;
    }
};
class C : public A {
 public:
    void get() {
        cout << "Inside C\n";
        cout << y << " " << z << endl;
    }
};

int main() {
    B b;
    C c;
    b.get();
    c.get();
}