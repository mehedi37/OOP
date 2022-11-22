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




template <typename T, typename U> class multNumb {
 private:
    T x;
    U y;
 public:
    multNumb(T x = 0, U y = 0) {
        this->x = x;
        this->y = y;
    }
    void setData(T x = 0, U y = 0) {
        this->x = x;
        this->y = y;
    }
    T sum() {
        return x+y;
    }
};

int main() {
    multNumb m;
    while(1) {
        //
    }
}