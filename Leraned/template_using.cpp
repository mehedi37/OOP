/*
Copyright [2022] Mehedi_Hasan
08.11.22 | 11.30 AM

* Using template for not using polymorphism and rewrite code again and again
* template can be used to create multiple class of same type
* template is declared as :

        # template<class T>
        # template<typename T, class T>

    or various combination of these

    SO IT'S LIKE  SUPERPOWER :)
*/


#include<bits/stdc++.h>
using namespace std;


template <class T> class numb {
 private:
    T x;
    T y;
 public:
    numb(T x = 0, T y = 0) {
        this->x = x;
        this->y = y;
    }
    T sum() {
        return x+y;
    }
};


template <typename T, class U> class multNumb {
// template <class T = double, class U = double> class multNumb {     // can also be declared as this
 private:
    T x;
    U y;
 public:
    multNumb(T x = 0, U y = 0) {
        this->x = x;
        this->y = y;
    }
    T sum() {       // ekta dilei hb, higher type ta cast hoy automatic
        return x+y;
    }
};

int main() {
    numb doubleType(5.2, 5.5);
    numb intType(5, 6);
    cout << doubleType.sum() << endl;
    cout << intType.sum() << endl;
}