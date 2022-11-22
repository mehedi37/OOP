#include<bits/stdc++.h>
using namespace std;

int main() {
    int i;
    int ax[5] = {10, 20, 60, 40, 30};
    cout << "Enter index: " << endl;
    cin >> i;
    try {
        if (i > 4) {
            throw i;
            throw runtime_error("Runtime Error\n");
        }
        cout << "ax[" << i << "]=" << ax[i] << endl;
    }
    catch (int x) {
        cout << "Error ! Index accessed at : " << x << endl;
    }
    try {
        if (i > 4) {
            throw "Out of range\n";
            throw runtime_error("Runtime Error\n");
        }
        cout << "ax[" << i << "]=" << ax[i] << endl;
    }
    catch(char const * ex) {
        cout << ex << endl;
    }
    try {
        if (i > 4) {
            throw runtime_error("Runtime Error\n");
        }
        cout << "ax[" << i << "]=" << ax[i] << endl;
    }
    catch (...) {
        cout << "For default errors\n";
    }
}