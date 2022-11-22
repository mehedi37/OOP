#include<bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> px;
    px = make_pair(10, "Rajshahi");
    cout << "px : " << px.first << " " << px.second << endl << endl;
    cout << px.first << endl;
    cout << px.second << endl;
    get<0>(px) = 20;
    cout << "px : " << px.first << " " << px.second << endl << endl;
    pair<int, string> bx;
    bx = make_pair(55, "Rangpur");
    px.swap(bx);
    cout << "px : " << px.first << " " << px.second << endl;
    cout << "bx : " << bx.first << " " << bx.second << endl;
}