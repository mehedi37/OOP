#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data{0};
    Node *next = NULL;
};


class Queue {
 private:
    Node *fr = NULL;
    Node *rr = NULL;
    Node *p = NULL;
 public:
    void create() {
        fr = rr = p = NULL;
        cout << "How many elements : ";
        int n; cin >> n;
        for (int i{0}; i < n; i++) {
            Node *p = new Node;
            cin >> p->data;
            if (rr == NULL) {
                fr = rr = p;
            }
            rr->next = p;
            rr = rr->next;
        }
    }
    void enQueue() {
        Node *p = new Node;
        cout << "Enter value : ";
        cin >> p->data;
        if (rr == NULL) {
            fr = rr = p;
        }
        rr->next = p;
        rr = rr->next;
    }
    void deQueue() {
        if (fr == NULL) {
            cout << "Empty List\n";
            return;
        }
        fr = fr->next;
        if (fr == NULL) {
            rr = NULL;
        }
    }
    void dis() {
        Node *trv = fr;
        if (trv == NULL) {
            cout << "Empty List\n";
            return;
        }
        while (trv != NULL) {
            cout << trv->data << " ";
            trv = trv->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    while (1) {
        cout << "1) Create\n";
        cout << "2) Enqueue\n";
        cout << "3) Dequeue\n";
        cout << "4) Display\n";
        cout << "Enter option : ";
        int sel; cin >> sel;
        switch (sel) {
            case 1:
                q.create();
                break;
            case 2:
                q.enQueue();
                break;
            case 3:
                q.deQueue();
                break;
            case 4:
                q.dis();
                break;
            default :
                cout << "Invalid choice\n";
                break;
        }
    }
}