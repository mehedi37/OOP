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
    cout << "Using rbegin() rend()\n";
    for (auto i = l.rbegin(); i != l.rend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

bool isOdd(const int &x) {
    return x&1 == 1;
}

int main() {
    list<int> li;
    li.push_back(37);
    li.push_back(37);
    li.push_back(37);
    li.push_back(9);
    li.push_back(9);
    li.push_back(99);
    li.push_back(66);
    li.push_back(16);
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
    cin >> x;
    cout << "After which element : ";
    int y; cin >> y;
    auto xit = find(li.begin(), li.end(), y);
    auto xt = xit;
    li.insert(++xt, x);
    Display(li);
    li.insert(--xit, x);
    Display(li);
    cout << "Which number to find ? ";
    int f; cin >> f;
    int ct = count(li.begin(), li.end(), f);
    // int ctt = count(li.begin(), li.end(), isOdd);
    cout << "Found " << f << ", " << ct << " times\n";
    // cout << "Found " << f << ", " << ctt << " times using predicate fuction\n";

    li.erase(li.begin());
    li.erase(li.begin());
    li.erase(li.begin());
    li.erase(li.begin());
    cout << "1st 4 elements erased\n";

    cout << "Which number to remove ? ";
    cin >> x;
    li.remove(x);
    cout << "\nAfter Remove\n";
    Display(li);
    li.remove_if(isOdd);
    cout << "\nAfter All odd Remove\n";
    Display(li);

    list<int> bl;
    for (int i{0}; i < 5; i++) {
        bl.push_back(i);
        bl.push_back(i+1);
    }
    cout << "After assigning from list\n";
    li.assign(bl.begin(), bl.end());
    Display(li);

    array<int, 5> arr;
    x = 6;
    for (auto &i : arr) {
        i = x--;
    }

    cout << "After assigning from array\n";
    li.assign(arr.begin(), arr.end());
    Display(li);

    cout << "After sort\n";
    li.sort();

    cout << "After unique\n";
    li.unique();
    Display(li);
    // 11
}