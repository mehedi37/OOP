#include<bits/stdc++.h>
using namespace std;


int main() {
    array<int, 6> ax;
    for (auto &v : ax) {
        cin >> v;
    }
    cout << "Using at:" << ax.at(2) << endl;
    cout << "Using []: " << ax[2] << endl;
    cout << "Front: " << ax.front() << endl;
    cout << "Back:" << ax.back() << endl;
    ax.fill(6);
    if (ax.empty()) {
        cout << "Empty\n";
    } else {
        cout << "Not Empty\n";
    }
    cout << ax.size() << endl;
    cout << ax.max_size() << endl;
    cout << ax.begin() << endl;
    cout << ax.end() << endl;
    cout << "Data: " << ax.data() << endl;
    cout << ax.cbegin() << endl;
    cout << ax.cend() << endl;
    // 13 methods used
}