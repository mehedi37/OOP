#include<bits/stdc++.h>
using namespace std;

class Father {
 private:
    int money = 500;
 protected:
    int gold = 100;
 public:
    int land = 200;
};

class son : protected Father {
 public:
    // int getMoney() {
    //     return money;
    // }
    int getGold() {
        return gold;
    }
    int getLand() {
        return land;
    }
};

class grandSon : public son {
 public:
    // int getMoney() {
    //     return money;
    // }
    int getGold() {
        return gold;
    }
    int getLand() {
        return land;
    }
};

int main() {
    son s;
    grandSon g;
    cout << s.getLand() << endl;
    cout << g.getLand() << endl;
}