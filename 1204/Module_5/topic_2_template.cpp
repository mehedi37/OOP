#include<bits/stdc++.h>
using namespace std;

template <typename T, typename U> class multiNumb {
 private:
    T x;
    U y;
 public:
    multiNumb(T x = 0, U y = 0) {
        this->x = x;
        this->y = y;
    }
    void setData(T x = 0, U y = 0) {
        this->x = x;
        this->y = y;
    }
    double sum() {
        return x+y;
    }
};

int main() {
    multiNumb ii(5, 6);
    cout << ii.sum() << endl;
    multiNumb<int, double> id(5, 6.5);
    cout << id.sum() << endl;
    multiNumb<double, int> di(17.71, 16);
    cout << di.sum() << endl;
    multiNumb dd(500.5, 11.88);
    cout << dd.sum() << endl;
}