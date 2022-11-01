#include<bits/stdc++.h>
using namespace std;

class A {
 private:
    int x;
 public:
    A() {
        x = 0;
    }

    void display() {
        cout << x << endl;
    }
    friend void IncX(A &t);
    friend void add(A &t);
    friend void DecX(A &t);
};
void add(A &t) {
    int a;
    cout << "Enter number to assign : ";
    cin >> a;
    t.x = a;
}
void DecX(A &t) {
    int a;
    cout << "Enter number to decrease : ";
    cin >> a;
    t.x -= a;
}
void IncX(A &t) {
    int a;
    cout << "Enter number to Increase : ";
    cin >> a;
    t.x += a;
}

int main() {
    A a;
    add(a);
    a.display();
    IncX(a);
    a.display();
    DecX(a);
    a.display();
}