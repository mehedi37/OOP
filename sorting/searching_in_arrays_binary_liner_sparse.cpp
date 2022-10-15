/*
MD. Mehedi Hasan Maruf
Dept. of CSE , RUET
2003037

07/10/2022 1:53 AM
*/


#include<bits/stdc++.h>
using namespace std;


class Search {
 private:
    vector<pair<int, int>> array;
    vector<int> merged;
    int sparse[100][100];
    int sTable[100][3];
    int size;

 public:
    Search(int column) {
        size = column;
        cout << "Enter the 1D matrix of size: " << size << "\n";
        for (int i{0}; i < size; i++) {
            int tmp; cin >> tmp;
            array.push_back({tmp, i});
        }
        sort(array.begin(), array.end());
    }
    Search(int row, int column) {
        cout << "Enter the 2D matrix of (" << row << "x" << column << ") :\n";
        int counter{0};
        for (int i{0}; i < row; i++) {
            for (int j{0}; j < column; j++) {
                cin >> sparse[i][j];
                if (sparse[i][j] != 0) {
                    counter++;
                    sTable[counter][0] = i;
                    sTable[counter][1] = j;
                    sTable[counter][2] = sparse[i][j];
                }
            }
            sTable[0][0] = row;
            sTable[0][1] = column;
            sTable[0][2] = counter;
        }
    }
    void liner(int elm) {
        for (auto it = array.begin(); it != array.end(); it++) {
            if (it->first == elm) {
                cout << "Found: " << elm << " at pos: " << (it->second)+1 << endl;
                return;
                // comment return..if we need to find all the occurrence
            }
        }
        cout << "Element not found\n";
    }
    void show1DArray(bool one = 1, bool two = 1) {
        for (auto v : array) {
            if (one && two) cout << v.first << " " << v.second << '\n';
            else if (two) cout << v.second << ' ';
            else if (one) cout << v.first << ' ';
        }
        cout << endl;
    }
    void binary_search(int elm) {
        // for (auto v : array) {
        //     cout << v.first << " " << v.second << '\n';
        // }
        cout << endl;
        int l{0}, r{size-1};
        while (l <= r) {
            int mid = l+(r-l)/2;
            if (array[mid].first == elm) {
                cout << "Found: " << elm << " at: " << array[mid].second + 1 << endl;
                return;
            } else if (array[mid].first > elm) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        cout << "Element not found in array !\n";
    }
    void merge(vector<int> &v) {
        merged.clear();
        for (auto val : array) {
            merged.push_back(val.first);
        }
        for (auto val : v) {
            merged.push_back(val);
        }
        sort(merged.begin(), merged.end());
    }
    void mergedShow() {
        for (auto v : merged) {
            cout << v << " ";
        }
        cout << endl;
    }
    void sparse_find(int elm) {
        for (int i{1}; i <= sTable[0][2]; i++) {
            if (sTable[i][2] == elm) {
                cout << "Found: " << elm << " at\nRow: " << sTable[i][0]+1 << "\nColumn: " << sTable[i][1]+1 << endl;
                return;
            }
        }
        cout << "Not found\n";
    }
    void sparseShow() {
        cout << "\n+---+---+---+\n";
        cout << "|ROW|COL|VAL|";
        cout << "\n+---+---+---+\n";
        for (int i{0}; i <= sTable[0][2]; i++) {
            cout << "| ";
            for (int j{0}; j < 3; j++) {
                cout << sTable[i][j] << " | ";
            }
            if (!i) cout << "\n+-----------+";
            if (i != sTable[0][2]) cout << "\n";
        }
        cout << "\n+---+---+---+\n";
    }
};

/*
4 5 6
1 5 6
2 3 8
*/


int main() {
    while (1) {
        system("cls");
        string dimension;
        cout << "\tHome menu\nEnter Dimension of the matrix: ('q' to quite) ";
        cin >> dimension;
        if (dimension[0] == 'q') {
            system("cls");
            cout << "\tQuitting Programme\n\tPress 1 to back\n";
            string tp; cin >> tp;
            if (tp == "1") continue;
            else if (tp == "q") break;
            else cout << "Invalid Choice\n";
        }
        string r, c;
        system("cls");
        if (dimension == "1") {
            while (1) {
                cout << "Enter Size of array for 1D : ";
                cin >> c;
                if (c == "q") break;
                Search oneD(c[0]-'0');
                while (1) {
                    system("cls");
                    oneD.show1DArray(1, 0);
                    cout << "Searching ways available\n";
                    cout << "1) Liner Search\n2) Binary Search\n3) Merge another array\n4) Edit array\n";
                    cout << "Enter number to find: ";
                    string f; cin >> f;
                    if (f == "q" || f == "4") {
                        system("cls");
                        break;
                    }
                    system("cls");
                    if (f == "1") cout << "\nResult using Liner search\n", oneD.liner(stoi(f)), cout << "\n\n(Press Enter)\n";
                    else if (f == "2") cout << "\nResult using Binary search\n", oneD.binary_search(stoi(f)), cout << "\n\n(Press Enter)\n";
                    else if (f == "3") {
                        vector<int> arr;
                        int sz{0};
                        cout << "Enter new array size : ";
                        cin >> sz;
                        cout << "Enter the new array\n";
                        for (int i{0}; i < sz; i++) {
                            int tmp; cin >> tmp;
                            arr.push_back(tmp);
                        }
                        oneD.merge(arr);
                        system("cls");
                        cout << "Merged Array is\n";
                        oneD.mergedShow();
                    }
                    else cout << "Invalid Choice\n";
                    cin.ignore();
                    cin.ignore();
                    system("cls");
                }
            }
        } else if (dimension == "2") {
            cout << "Enter matrix Row x Column : ";
            cin >> r >> c;
            Search twoD(stoi(r), stoi(c));
            while (1) {
                system("cls");
                cout << "1) Find a number\n2) Show the sparse table\n4) Back\n";
                string f; cin >> f;
                if (f == "q") break;
                else if (f == "1") {
                    int tmp;
                    cout << "\nEnter a number to find\n\n";
                    cin >> tmp;
                    twoD.sparse_find(tmp);
                } else if (f == "2") {
                    twoD.sparseShow();
                } else if (f == "3") {
                    break;
                } else {
                    cout << "Invalid Choice\n";
                }
                cin.ignore();
                cout << "(Press Enter)\n";
                cin.ignore();
            }
        } else {
            system("cls");
            cout << "Invalid selection !" << endl;
        }
    }
    return 0;
}
