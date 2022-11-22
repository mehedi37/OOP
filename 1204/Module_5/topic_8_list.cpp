#include<bits/stdc++.h>
using namespace std;


void Display(list<int> &l) {
    cout << "Using begin() end()\n";
    for (auto i = l.begin(); i != l.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}
void DisplayRev(list<int> &l) {
    cout << "Using begin() end()\n";
    for (auto i = l.rbegin(); i != l.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}
int main() {
    list<int> li;
    li.push_back(6);
    li.push_front(5);
    li.push_front(1);
    li.push_front(7);
    Display(li);
    DisplayRev(li);
    cout << li.front() << endl;
    cout << li.back() << endl;
    li.pop_back();
    Display(li);
    li.pop_front();
    Display(li);
    auto loc = find(li.begin(), li.end(), 1);
    cout << *loc << endl;
    int x;
    cout << "Enter new element : ";
    // 11
}