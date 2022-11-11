#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data{0};
    Node *next = NULL;
    Node *prev = NULL;
};

class stack_linked {
 private:
    int n, x;
    Node *h;
    Node *tp;

 public:
    stack_linked() {
        n = 0, x = 0;
        h = NULL;
        tp = NULL;
    }
    void push() {
        Node *p = new Node();
        cout << "Enter value : ";
        cin >> p->data;
        cout << "Node created\n";
        if (h == NULL) {
            h = p;
            h->prev = NULL;
        } else {
            if (tp != NULL) {
                p->prev = tp;
                tp->next = p;
            }
        }
        tp = p;
    }
    void pop() {
        if (tp == h) {
            tp = NULL;
            return;
        }
        tp = tp->prev;
        tp->next = NULL;
        cout << "Poped \n";
    }
    void dis() {
        Node *tv = tp;
        if (tv == NULL) {
            cout << "List Empty\n";
            return;
        }
        while (tv->prev != NULL) {
            cout << tv->data << " -> ";
            tv = tv->prev;
        }
        cout << h->data << endl;
    }
};

int main() {
    stack_linked sl;
    while (1) {
        cout << "1) Push\n";
        cout << "2) Pop\n";
        cout << "3) Display\n";
        cout << "4) Top\n";
        cout << "Enter option : ";
        int sel; cin >> sel;
        switch (sel) {
            case 1:
                sl.push();
                cout << "value pushed !\n";
                break;
            case 2:
                sl.pop();
                cout << "value popped !\n";
                break;
            case 3:
                sl.dis();
                break;
            default :
                cout << "Invalid choice\n";
                break;
        }
    }
}