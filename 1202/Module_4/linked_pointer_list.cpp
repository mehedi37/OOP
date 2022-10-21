#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class linked_list {
 private:
    int n, x;
    Node *h;
    Node *q;
    Node *p;

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
        system("cls");
        cout << "\tList created\n";
        cin.ignore();
        cin.ignore();
    }
    // Normal display function to print only values
    void display_Data() {
        p = h;
        if (p == NULL) {
            cout << "List empty" << endl;
        }
        cout << "h";
        while (p != NULL) {
            cout << " -> " << p->data;
            p = p->next;
        }
        cin.ignore();
    }
    void insert_Data() {
        display_Data();
        p = h;
        q = h;
        cout << "\nEnter index (0 based): ";
        int idx;
        cin >> idx;
        cout << "Enter new number : ";
        int up_val;
        cin >> up_val;
        system("cls");
        int cnt{0};
        // handling 0 index insertion
        if (idx == 0) {
            Node *add = new Node;
            add->next = h;
            add->data = up_val;
            h = add;
            cout << "\n\tAdded\n";
            cin.ignore();
            cin.ignore();
            return;
        }
        while (p != NULL) {
            if (cnt == idx) {
                // Adding new node to the list
                Node *add = new Node;
                add->data = up_val;
                add->next = p;
                q->next = add;
                cout << "\n\tAdded\n";
                cin.ignore();
                cin.ignore();
                return;
            }
            cnt++;
            q = p;
            p = p->next;
        }
        cout << "\n\tNot Found\n";
        cin.ignore();
        cin.ignore();
    }
    void delete_Data() {
        display_Data();
        p = h;
        q = h;
        cout << "\nEnter number to delete : ";
        int pos_val;
        cin >> pos_val;

        // If the value is at beginning of list
        if (p->data == pos_val) {
            h = p->next;
            return;
        }
        system("cls");
        while (p != NULL) {
            if (p->data == pos_val) {
                q->next = p->next;      // Keeping the deleted node (p)'s next location (p.next) to the previous node "q"
                cout << "\n\tDeleted\n";
                cin.ignore();
                cin.ignore();
                return;
            }
            q = p;      // First keeping the last node position into "q"
            p = p->next;    // Then going to the next node
        }
        cout << "Not Found\n";
        cin.ignore();
        cin.ignore();
    }
    void search() {
        display_Data();
        p = h;
        cout << "\nWhich number to search ? ";
        int pos_val;
        cin >> pos_val;
        int cnt{1};
        system("cls");
        while (p != NULL) {
            if (p->data == pos_val) {
                cout << "Found\nAt : " << cnt << " node\n";
                cin.ignore();
                cin.ignore();
                return;
            }
            p = p->next;
            cnt++;      // Keeping track of how many nodes have been visited
        }
        cout << "Not Found\n";
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
        while (p != NULL) {
            if (p->data == pos_val) {
                p->data = up_val;
                cout << "\n\tData Updated\n";
                cin.ignore();
                cin.ignore();
                return;
            }
            p = p->next;
        }
        cout << "Val not found\n";
        cin.ignore();
        cin.ignore();
    }
};

int main() {
    linked_list l;
    while (1) {
        system("cls");
        cout << "*****MENU*****" <<endl;
        cout << "1.Create" << endl;
        cout << "2.Insert" << endl;
        cout << "3.Delete" << endl;
        cout << "4.Update" << endl;
        cout << "5.Display" << endl;
        cout << "6.Search a value" << endl;
        cout << "7.Exit" << endl;
        cout << "Enter option : ";
        int option;
        cin >> option;
        cout << endl;
        switch (option) {
            case 1:
                system("cls");
                l.create();
                break;
            case 2:
                system("cls");
                l.insert_Data();
                cout << endl;
                break;
            case 3:
                system("cls");
                l.delete_Data();
                cout << endl;
                break;
            case 4:
                system("cls");
                l.update_Data();
                cout << endl;
                break;
            case 5:
                system("cls");
                l.display_Data();
                cout << endl;
                cin.ignore();
                break;
            case 6:
                system("cls");
                l.search();
                cout << endl;
                break;
        }
        if (option == 7) {
            cout << "End of program" << endl;
            break;
        }
    }
}
