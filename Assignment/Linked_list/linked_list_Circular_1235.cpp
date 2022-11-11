#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data{0};
    Node *next = NULL;

};

class circular_inked_list {
 private:
    Node **start = NULL;
    Node **end = NULL;
    Node *h = NULL;
    Node *p = NULL;
    Node *q = NULL;

 public:
    void create() {
        h = NULL;
        p = NULL;
        q = NULL;
        int n;
        cout << "Enter how many numbers : ";
        cin >> n;
        for (int i{0}; i < n; i++) {
            p = new Node;
            cin >> p->data;
            if (h == NULL) {
                h = p;
            } else if (q != NULL) {
                q->next = p;
            }
            q = p;
        }
        start = &h;     // Saving the head reference
        q->next = *start;
        end = &q;
    }
    bool chk() {
        if (start == NULL) {
            cout << "List is empty\n";
            return 0;
        }
        return 1;
    }
    void display() {
        if (chk()) {
            bool fg{1};
            p = *start;
            while (p != *start || fg) {
                cout << p->data << " ";
                fg = 0;
                p = p->next;
            }
            cout << endl;
        }
    }
    void insert_first() {
        p = new Node;
        cout << "Enter number to add to last : ";
        cin >> p->data;
        (*end)->next = p;
        p->next = *start;
        *start = p;
    }
    void insert_last() {
        p = new Node;
        cout << "Enter number to add to last : ";
        cin >> p->data;
        // p->next = (*end)->next;
        (*end)->next = p;
        p->next = *start;
        *end = p;
    }
    void set_head(Node *head) {
        *start = head;
    }
    void set_end(Node *ed) {
        *end = ed;
    }
    Node * get_head() {
        return *start;
    }
    Node * get_end() {
        return *end;
    }
    void merge_LL(circular_inked_list &x) {
        (*end)->next = x.get_head();
        x.set_head(*start);
        *end = x.get_end();
        (*end)->next = *start;
    }

    void replace() {
        display();
        // Getting inputs
        cout << "Which number to replace : ";
        int repl; cin >> repl;
        cout << "Enter new number : ";
        int val; cin >> val;

        // Check if the list is empty
        if (chk()) {
            bool fg{1}, found{0};
            p = *start;
            while (p != *start || fg) {
                if (p->data == repl) {
                    p->data = val;
                    found = 1;
                }
                fg = 0;
                p = p->next;
            }
            if (!found) cout << "Not found\n";
            else cout << "Replaced\n";
        }
    }
};

int main() {
    circular_inked_list l, m;
    while (1) {
        cout << "1) Create linked list\n";
        cout << "2) Insert last\n";
        cout << "3) Insert first\n";
        cout << "4) Display\n";
        cout << "5) Merge\n";
        cout << "6) Replace\n";
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
            l.merge_LL(m);
            break;
        case 6:
            l.replace();
            break;
        default:
            cout << "Invalid !\n";
            break;
        }
    }
}