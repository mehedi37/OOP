#include<bits/stdc++.h>
using namespace std;


class stacked {
 private:
    int a[1000];
    int top = 0;
 public:
    void push(int at) {
        while (top < at) {
            cout << "Top : " << top << endl;
            cin >> a[top++];
        }
    }
    void pop() {
        if (top == 0) {
            cout << "Stack empty can't pop\n";
            a[top] = 0;
            return;
        }
        top--;
        cout << "value popped !\n";
    }
    void topp() {
        cout << a[top] << endl;
    }
    void dis() {
        if (top == 0) {
            cout << "Stack is Empty";
        }
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
        // if (tv == h) {
        //     cout << "List is empty\n";
        // }
        if (tv == NULL) {
            cout << "List Empty\n";
            return;
        }
        while (tv->prev != NULL) {
            cout << tv->data << " -> ";
            // cout << tp->data << " <tp ";
            tv = tv->prev;
        }
        cout << h->data << endl;
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