#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data{0};
    Node *next = NULL;
};

class LL {
 private:
    int n{0}, x{0}, mx{0};
    Node *h = NULL;
    Node *p = NULL;
    Node *q = NULL;

 public:
    void create() {
        h = NULL;
        q = NULL;
        p = NULL;
        cout << "How many numbers : ";
        cin >> n;
        cout << endl;
        for (int i=0; i < n; i++) {
            p = new Node();
            cin >> x;
            p -> data = x;
            if (h == NULL) {
                h = p;
            } else {
                if (q != NULL) {
                    q->next = p;
                }
            }
            q = p;
        }
    }
    void display() {
        p = h;
        if (p == NULL) {
            cout << "List empty" << endl;
        }
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    void insert_first() {
        Node *p = new Node();
        cout << "Enter data : ";
        cin >> p->data;
        p->next = h;
        h = p;
    }
    void insert_last() {
        p = h;
        Node *q = new Node();
        cout << "Enter data : ";
        cin >> q->data;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = q;
    }
    void maxx() {
        p = h;
        while (p != NULL) {
            mx = max(p->data, mx);
            p = p->next;
        }
        cout << "Max is : " << mx <<endl;
    }
    void dlt() {
        p = h;
        q = h;
        cout << "Which number to delete ? ";
        int dl; cin >> dl;
        bool f{0};
        while (h->data == dl) {
            if (h->next == NULL) {
                h = NULL;
                return;
            }
            h = h->next;
            f = 1;
        }
        while (p != NULL) {
            if (p->data == dl) {
                f = 1;
                q->next = p->next;
            }
            q = p;
            p = p->next;
        }
        if (!f) cout << "Not found\n";
        else cout << "Deleted\n";
    }
    Node * get_head() {
        return h;
    }
    void merge(LL &x) {
        p = h;
        Node *last = p;
        q = x.get_head();
        while (p != NULL && q != NULL) {
            if (p->data > q->data) {
                Node * tmp = q->next;
                last->next = q;
                q->next = p;
                q = tmp;
            }
            last = p;
            p = p->next;
        }
        if (q != NULL) last->next = q;
    }
};

int main() {
    LL l, m;
    while (1) {
        cout << "1) Create linked list\n";
        cout << "2) Insert last\n";
        cout << "3) Insert first\n";
        cout << "4) Display\n";
        cout << "5) Merge\n";
        cout << "6) Max\n";
        cout << "7) Delete\n";
        int cs;
        cin >> cs;
        switch (cs) {
        case 1:
            l.create();
            break;
        case 2:
            l.insert_last();
            break;
        case 3:
            l.insert_first();
            break;
        case 4:
            l.display();
            break;
        case 5:
            m.create();
            l.merge(m);
            break;
        case 6:
            l.maxx();
            break;
        case 7:
            l.dlt();
            break;
        default:
            cout << "Invalid !\n";
            break;
        }
    }
}