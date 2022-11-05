#include<bits/stdc++.h>
using namespace std;

class Father {
 private:
    int money;
 protected:
    int gold;
 public:
    int land;
    int getMoney() {
        return money;
    }
    int getGold() {
        return gold;
    }
    int getLand() {
        return land;
    }
};
class son : public Father {
};
class grandSon : public son {
};

int main() {
    son s;
    cout << s.getGold() << endl;
}