/*
MD. Mehedi Hasan Maruf
Dept. of CSE , RUET
2003037

07/10/2022 10:38 AM
*/

#include<bits/stdc++.h>
using namespace std;

class Test {
 private:
    int x;
    int y;
    static int z;
 public:
    Test() {
        x = y = 0;
        cout << "Default constructor is called !\n";
        z++;
    }
    Test(int i, int j) {
        x = i;
        y = j;
        cout << "Parameterized constructor is called !\n";
        z++;
    }
    Test(Test &a) {
        x = a.x;
        y = a.y;
        z++;
        cout << "Copy constructor is Called\n";
    }
    int Xval() const{
        return x;
    }
    int Yval() const{
        return y;
    }
    void setData(int i, int j) {
        x = i;
        y = j;
        cout << "Data of X & Y is updated !\n";
    }
    void showZ() {
        cout << "Z: " << z << endl;
        /*
        cout << "Y(Before): " << y << endl;
        y++;
        cout << "Y(after): " << y << endl;
        */
    }
    void showAll() const {
        cout << "X: " << x << " Y: " << y << " Z: " << z << endl;
        /*
        cout << "Y(Before): " << y << endl;
        y++;
        cout << "Y(after): " << y << endl;
        */
    }
};

int Test::z = 0;
// For static

int main() {
    system("cls");
    cout << "How many Objects? : ";
    int n; cin >> n;
    Test obj[n];
    for (int i{0}; i < n; i++) {
        cout << "\nEnter details of object : " << i+1 << endl;
        int tx, ty;
        cin >> tx >> ty;
        obj[i].setData(tx, ty);
    }
    int sumX{0}, maxY{0}, maxYidx{0};
    for (int i{0}; i < n; i++) {
        sumX += obj[i].Xval();
        if (obj[i].Yval() > maxY) maxYidx = i, maxY = obj[i].Yval();
    }
    cout << "\nSum of all X: " << sumX << endl;
    cout << "\nMax val of Y:\nIn object no : " << maxYidx+1 << "\nvalue of Y is: " << maxY << "\n\n";
    return 0;
}
