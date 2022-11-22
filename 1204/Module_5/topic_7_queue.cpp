#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> qu;
    qu.push(5);
    qu.push(6);
    cout << qu.front() << endl;
    qu.pop();
    cout << qu.empty() << endl;
    cout << qu.back() << endl;
    qu.pop();
    cout << qu.empty() << endl;
}