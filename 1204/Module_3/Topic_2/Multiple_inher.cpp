#include<bits/stdc++.h>
using namespace std;

class A {
 private:
    int x{9};
 protected:
    int y{10};
 public:
    int z;
};

class B {
 private:
    int p{0};
 protected:
    int q{1};
 public:
    int r{2};
    B() {
        cout << "Created B\n";
    }
};

class C : public A, public B {
 public:
        C() {
            cout << "Created C\n";
        }
        void Cget() {
            // cout << "X : " << x << endl;  // Private
            cout << "y : " << y << endl;
            cout << "z : " << z << endl;

            // cout << "p : " << p << endl; // Private
            cout << "q : " << q << endl;
            cout << "r : " << r << endl;
    }
};

int main() {
    C c;
    c.Cget();
}