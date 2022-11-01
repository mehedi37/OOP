#include<bits/stdc++.h>
using namespace std;

class circuit {
 private:
    int real;
    int img;
 public:
    circuit() {
        real = 0;
        img = 0;
    }
    circuit(int r, int i) {
        real = r;
        img =i;
    }
    void dis() {
        cout << real << (img < 0?"":"+") << img << "j" << endl;
    }
    circuit operator + (const circuit &a) {
        circuit tmp;
        tmp.real = this->real+a.real;
        tmp.img = this->img+a.img;
        return tmp;
    }
    circuit operator * (const circuit &a) {
        circuit tmp;
        // cout << "Real : " << this->real << " img: " << this->img << endl;
        int tmpR;
        tmp.real = (a.real*this->real)-(a.img*this->img);       // i^2 = -1
        tmp.img = (a.img*this->real)+(a.real*this->img);
        // cout << "Real : " << a.real << " img: " << a.img << endl;
        return tmp;
    }
    circuit operator / (const circuit &a) {
        circuit tmp;
        tmp.real = this->real/(a.real+a.img);
        tmp.img = this->img/(a.real+a.img);
        return tmp;
    }
    circuit operator !() {
        circuit tmp;
        tmp.real = this->real;
        tmp.img = this->img*-1;
        return tmp;
    }
};

int main() {
    circuit z1(3, 4), z2(4, -3), z3(0, 6), v(100, 50);
    circuit z;
    z = z1+z2+z3;      // operator overloading
    z.dis();
    circuit i;
    i = (v*(!z))/(z*(!z));
    cout << "Current is : ";
    i.dis();
}