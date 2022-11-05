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
    void getXYZ() {
        // cout << "X : " << x << endl;  // Private
        cout << "y : " << y << endl;
        cout << "z : " << z << endl;
    }
};

int main() {
    B b;
    b.getXYZ();
}