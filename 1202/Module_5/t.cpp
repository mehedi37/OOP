#include<bits/stdc++.h>
using namespace std;

class player {
 private:
    int xp, health, money;

 public:
    player() {
        cout << "Player object is created\n";
        xp = 0;
        health = 100;
        money = 0;
    }
    player(int h, int x, int m) {
        cout << "Player object is created by parameter\n";
        xp = x;
        health = h;
        money = m;
    }
    player(int h) {
        cout << "Player object is created by parameter one\n";
        xp = 0;
        health = h;
        money = 0;
    }
    void getHealth() {
        cout << "inside gethealth\n";
        cout << health << endl;
    }
    void hurt(int damage) {
        health -= damage;
    }
    void regain(int heal) {
        health += heal;
    }
};

int main() {
    player a(100, 0, 5000), b(100);
}