#include<bits/stdc++.h>
using namespace std;


class linked_list {
 private:
    vector<pair<int, int>> list[10000];
    int n{0};
 public:
    void create() {
        cout << "How Many Elements ? ";
        cin >> n;
        cout << "Enter " << n << " values\n";
        for (int node{0}; node < n; node++) {
            int value; cin >> value;
            if (node != n-1) list[node].push_back({value, node+1});
            else list[node].push_back({value, -1});
        }
    }
    void show() {
        cout << "Showing linked list\n";
        int h{0};
        for (int i{0}; i < n; i++) {
            cout << list[h][0].first << " ";
            h = list[h][0].second;
        }
        cout << endl;
    }
    void insert(int val, int pos_val) {
        int h{0};
        for (int i{0}; i < n; i++) {
            int tmp_pos{0};
            if (list[h][0].first == pos_val) {
                tmp_pos = list[h][0].second;
                n++;
                list[h][0].second = n;
                list[n].push_back({val, tmp_pos});
                cout << "Added value\n";
                return;
            }
            h = list[h][0].second;
        }
        cout << "Position not found !\n";
    }
    void search(int val) {
        int h{0};
        for (int i{0}; i < n; i++) {
            if (list[h][0].first == val) {
                cout << "Found\nAt pos : " << list[h][0].second << endl;
                return;
            }
            h = list[h][0].second;
        }
        cout << "Value not found !\n";
    }
    void del(int pos_val) {
        int h{0}, lst_pos{0};
        if (list[h][0].first == pos_val) {
            h = 1;
            cout << "Deleted\n";
            n--;
            return;
        }
        for (int i{0}; i < n; i++) {
            if (list[h][0].first == pos_val) {
                cout << "Deleted\n";
                list[lst_pos][0].second = list[h][0].second;
                n--;
                return;
            }
            lst_pos = h;
            h = list[h][0].second;
        }
        cout << "Position not found !\n";
    }
};

int main() {
    linked_list l;
    while(1) {
        system("cls");
        int choose;
        cout << "**Main Menu**\n";
        cout << "1) Create a list\n";
        cout << "2) Insert element\n";
        cout << "3) Search Element\n";
        cout << "4) Delete Element\n";
        cout << "5) Show List\n";
        cout << "6) Exit\n";
        cin >> choose;
        switch(choose) {
            case 1:
                system("cls");
                l.create();
                break;
            case 2:
                system("cls");
                cout << "Enter the value to insert : ";
                int val;
                cin >> val;

                cout << "Enter the pos_val : ";
                int pos;
                cin >> pos;
                l.insert(val, pos);
                break;
            case 3:
                system("cls");
                cout << "Enter value to search : ";
                int s;
                cin >> s;
                l.search(s);
                break;
            case 4:
                system("cls");
                cout << "Enter value to delete : ";
                int d;
                cin >> d;
                l.del(d);
                break;
            case 5:
                system("cls");
                l.show();
                break;
        }
        if (choose == 6) {
            cout << "Exiting Program\n";
            return 0;
        }
    }
}