#include<bits/stdc++.h>
using namespace std;


class Node{
 public:
    int data{0};
    Node *next = NULL;
    Node *prev = NULL;
};

class linked_list {
 private:
    int n, x;
    Node *h;
    Node *q;
    Node *p;
    Node *split[1000]{NULL};
    int split_count{0};

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
                    p->prev = q;
                }
            }
            q = p;
    // cout << "\nAfter\nh : " << h << " p: " << p << " q : " << q << " p.data : " << p->data << " q.data : " << q->data << endl;
        }
        // system("cls");
        cout << "\tList created\n";
        cin.ignore();
        cin.ignore();
    }
    // Normal display function to print only values
    void display_Data() {
        p = h;
        if (p != NULL) {
            cout << "List empty" << endl;
        }
        cout << "h";
        while (p != NULL) {
            // cout << "\np : " << p << " p->data : " << p->data << " p->next: " << p->next << endl;
            cout << " -> " << p->data;
            p = p->next;
        }
        cin.ignore();
    }
    void insert_Data() {
        display_Data();
        p = h;
        cout << "\nEnter Target value: ";
        int tval;
        cin >> tval;
        cout << "Enter new number : ";
        int up_val;
        cin >> up_val;
        system("cls");
        // handling 0 index insertion
        if (tval == h->data) {
            bool in;
            cout << "Want to insert beginning of the list ? (1 or 0) ";
            cin >> in;
            Node *add = new Node;
            add->data = up_val;
            if (in) {
                add->next = h;
                h = add;
            } else {
                add->next = h->next;
                h->next = add;
            }
            cout << "\n\tAdded\n";
            cin.ignore();
            cin.ignore();
            return;
        }
        while (p != NULL) {
            if (p->data == tval) {
                // Adding new node to the list
                Node *add = new Node();
                add->data = up_val;
                add->next = p->next;
                p->next = add;
                cout << "\n\tAdded\n";
                cin.ignore();
                cin.ignore();
                return;
            }
            p = p->next;
        }
        cout << "\n\tNot Found\n";
        cin.ignore();
        cin.ignore();
    }
    void delete_Data() {
        display_Data();
        p = h;
        cout << "\nEnter number to delete : ";
        int pos_val;
        cin >> pos_val;
        bool fg{1}, repeat{0};
        cout << "Want to search all the ? (1 or 0) : ";
        cin >> repeat;
        // If the value is at beginning of list
        while (h->data == pos_val && h->next != NULL) {
            h = h->next;
            fg = 0;
            cout << "\n\tDeleted\n";
            // Bug fixed for all same value deletion
            if (h->next == NULL) {
                return;
            }
            if (!repeat) return;
        }
        system("cls");
        while (p != NULL) {
            if (p->data == pos_val) {
                p->prev->next = p->next;    // Keeping the deleted node (p)'s next location (p.next) to the previous node "q"
                cout << "\n\tDeleted\n";
                cin.ignore();
                fg = 0;
                if (!repeat) return;
            }
            p = p->next;    // Then going to the next node
        }
        if (fg) cout << "Not Found\n";
        cin.ignore();
        cin.ignore();
    }
    void update_Data() {
        display_Data();
        p = h;
        cout << "\nWhich number to update ? ";
        int pos_val;
        cin >> pos_val;
        cout << "Enter new number : ";
        int up_val;
        cin >> up_val;
        system("cls");
        bool fg{1}, repeat{0};
        cout << "Want to search all the ? (1 or 0) : ";
        cin >> repeat;
        while (p != NULL) {
            if (p->data == pos_val) {
                p->data = up_val;
                cout << "\n\tData Updated\n";
                cin.ignore();
                cin.ignore();
                fg = 0;
                if (!repeat) return;
            }
            p = p->next;
        }
        if (fg) cout << "Val not found\n";
        cin.ignore();
        cin.ignore();
    }


/* For Circular Linked List */
void c_create() {
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
        p->next = h;
        cout << "\tList created\n";
        cin.ignore();
    }
    void c_display_Data() {
        p = h;
        if (p->next == h) {
            cout << "List empty" << endl;
        }
        cout << "h";
        while (p->next != h) {
            cout << " -> " << p->data;
            p = p->next;
        }
        cout << " -> " << p->data;
        cin.ignore();
    }
    void c_insert_Data() {
        c_display_Data();
        p = h;
        cout << "\nEnter Target value: ";
        int tval;
        cin >> tval;
        cout << "Enter new number : ";
        int up_val;
        cin >> up_val;
        system("cls");
        // handling 0 index insertion
        if (tval == h->data) {
            bool in;
            cout << "Want to insert begining of the list ? (1 or 0) ";
            cin >> in;
            Node *add = new Node;
            add->data = up_val;
            if (in) {
                add->next = h;
                h = add;
            } else {
                add->next = h->next;
                h->next = add;
            }
            cout << "\n\tAdded\n";
            cin.ignore();
            cin.ignore();
            return;
        }

// BUG
        bool f{1};
        while (p != h && f) {
            if (p->data == tval) {
                // Adding new node to the list
                Node *add = new Node();
                add->data = up_val;
                add->next = p->next;
                p->next = add;
                cout << "\n\tAdded\n";
                cin.ignore();
                cin.ignore();
                return;
            }
            p = p->next;
            f = 0;
        }
        cout << "\n\tNot Found\n";
        cin.ignore();
        cin.ignore();
    }


    void c_delete_Data() {
        c_display_Data();
        p = h;
        q = h;
        cout << "\nEnter number to delete : ";
        int pos_val;
        cin >> pos_val;
        bool fg{1}, repeat{0};
        cout << "Want to search all the ? (1 or 0) : ";
        cin >> repeat;
        // If the value is at beginning of list
        while (h->data == pos_val && h->next != h) {
            h = h->next;
            fg = 0;
            cout << "\n\tDeleted\n";
            // Bug fixed for all same value deletion
            if (h->next == h) {
                return;
            }
            if (!repeat) return;
        }
        system("cls");
        while (p->next != h) {
            if (p->data == pos_val) {
                p->prev->next = p->next;    // Keeping the deleted node (p)'s next location (p.next) to the previous node "q"
                cout << "\n\tDeleted\n";
                cin.ignore();
                fg = 0;
                if (!repeat) return;
            }
            p = p->next;    // Then going to the next node
        }
        if (p->data == pos_val) {
            p->prev->next = p->next;
            cout << "\n\tDeleted\n";
            cin.ignore();
            fg = 0;
            return;
        }
        if (fg) cout << "Not Found\n";
        cin.ignore();
        cin.ignore();
    }
    void c_update_Data() {
        c_display_Data();
        p = h;
        cout << "\nWhich number to update ? ";
        int pos_val;
        cin >> pos_val;
        cout << "Enter new number : ";
        int up_val;
        cin >> up_val;
        system("cls");
        bool fg{1}, repeat{0};
        cout << "Want to search all the ? (1 or 0) : ";
        cin >> repeat;
        while (p->next != h) {
            if (p->data == pos_val) {
                p->data = up_val;
                cout << "\n\tData Updated\n";
                cin.ignore();
                cin.ignore();
                fg = 0;
                if (!repeat) return;
            }
            p = p->next;
        }
        if (fg) cout << "Val not found\n";
        cin.ignore();
        cin.ignore();
    }

/* End of functions */
};

int main() {
    linked_list l;
    int cir{2};
    cout << "1) Circular Linked List\n";
    cout << "2) Liner Linked List\n";
    cin >> cir;
    while (1) {
        system("cls");
        cout << "*****MENU*****" <<endl;
        cout << "1.Create" << endl;
        cout << "2.Insert" << endl;
        cout << "3.Delete" << endl;
        cout << "4.Update" << endl;
        cout << "5.Display" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter option : ";
        int option;
        cin >> option;
        cout << endl;
        int cnt{0};
        switch (option) {
            case 1:
                system("cls");
                if (cir == 2) l.create();
                else l.c_create();
                break;
            case 2:
                system("cls");
                if (cir == 2) l.insert_Data();
                else l.c_insert_Data();
                cout << endl;
                break;
            case 3:
                system("cls");
                if (cir == 2) l.delete_Data();
                else l.c_delete_Data();
                cout << endl;
                break;
            case 4:
                system("cls");
                if (cir == 2) l.update_Data();
                else l.c_update_Data();
                cout << endl;
                break;
            case 5:
                system("cls");
                if (cir == 2) l.display_Data();
                else l.c_display_Data();
                cout << endl;
                cin.ignore();
                break;
        }
        if (option == 6) {
            cout << "End of program" << endl;
            break;
        }
    }
}