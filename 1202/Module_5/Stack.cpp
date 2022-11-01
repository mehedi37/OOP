#include<bits/stdc++.h>
using namespace std;


class stacked {
 private:
    int a[1000];
    int top = 0;
 public:
    void push(int at) {
        while (top <= at) {
            cin >> a[top++];
        }
    }
    void pop() {
        top--;
    }
    void topp() {
        cout << a[top] << endl;
    }
    void dis() {
        int tmp = top;
        while (tmp--) {
            cout << a[tmp] << " -> ";
        }
        cout << endl;
    }
};

class Node {
 public:
    int data{0};
    Node *next = NULL;
    Node *prev = NULL;
};

class stack_linked {
 private:
    int n, x;
    Node *h = NULL;
    Node *tr = NULL;
 public:
    void push() {
        Node *p = new Node;
        cout << "Enter value : ";
        cin >> p->data;
        h->next = p;
        p->prev = h;
        h = p;
    }
    void pop() {
        h = h->prev;
        h->next = NULL;
    }
    void dis() {
        tr = h;
        while (tr != NULL) {
            cout << tr->data << " -> ";
            tr = tr->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << "1) Array Stack\n";
    cout << "2) Linked list Stack\n";
    cout << "Enter Option : ";
    int cs;
    cin >> cs;
    if (cs != 1 && cs != 2) {
        cout << "Invalid selection\n";
    } else if (cs == 1) {
        stacked st;
        while(1) {
            cout << "1) Push\n";
            cout << "2) Pop\n";
            cout << "3) Display\n";
            cout << "4) Top\n";
            cout << "Enter option : ";
            int sel; cin >> sel;
            switch (sel) {
                case 1:
                    cout << "How many numbers you want to push ? ";
                    int n; cin >> n;
                    st.push(n);
                    cout << "value pushed !\n";
                    break;
                case 2:
                    st.pop();
                    cout << "value popped !\n";
                    break;
                case 3:
                    st.dis();
                    break;
                case 4:
                    st.topp();
                    break;
            }
            if (sel > 4 || sel < 1) cout << "Invalid choice\n";
        }
    } else {
        stack_linked sl;
        while(1) {
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
            }
            if (sel > 4 || sel < 1) cout << "Invalid choice\n";
        }
    }
}