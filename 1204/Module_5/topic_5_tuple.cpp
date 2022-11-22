#include<bits/stdc++.h>
using namespace std;


int main() {
    tuple<int, string, double> tx;
    tx = make_tuple(100, "Kamal", 3.5);
    cout << get<0>(tx) << endl;
    cout << get<1>(tx) << endl;
    cout << get<2>(tx) << endl;
    get<2>(tx) = 3.7;
    cout << "tx: " << get<0>(tx) << " " << get<1>(tx) << " " << get<2>(tx) << " " << endl;

    tuple<int, string, double> bx;
    bx = make_tuple(50, "Abdul", 3.9);
    cout << "bx: " << get<0>(bx) << " " << get<1>(bx) << " " << get<2>(bx) << " " << endl;
    cout << "After\n";
    tx.swap(bx);
    cout << "tx: " << get<0>(tx) << " " << get<1>(tx) << " " << get<2>(tx) << " " << endl;
    cout << "bx: " << get<0>(bx) << " " << get<1>(bx) << " " << get<2>(bx) << " " << endl;
    // 5
}