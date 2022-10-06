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
    void binary_search(int elm) {
        int l{0}, r{size-1};
        while (l < r) {
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
    void sparse_table(int elm) {
        for (int i{1}; i <= sTable[0][2]; i++) {
            if (sTable[i][2] == elm) {
                cout << "Found: " << elm << " at\nRow: " << sTable[i][0] << "\nColumn: " << sTable[i][1] << endl;
                return;
            }
        }
        cout << "Not found\n";
    }
};


int main() {
    int dimension;
    cout << "Enter Dimension of the matrix: ";
    cin >> dimension;
    int r, c;
    if (dimension == 1) {
        cout << "Enter Size of array : ";
        cin >> c;
        Search oneD(c);
        cout << "Enter number to find: ";
        int f; cin >> f;
        cout << "\nResult using Liner search\n";
        oneD.liner(f);
        cout << "\nResult using Binary search\n";
        oneD.binary_search(f);
    } else if (dimension == 2) {
        cout << "Enter matrix Row x Column : ";
        cin >> r >> c;
        Search twoD(r, c);
        cout << "Enter number to find: ";
        int f; cin >> f;
        twoD.sparse_table(f);
    } else {
        cout << "Invalid selection !" << endl;
    }
    return 0;
}
