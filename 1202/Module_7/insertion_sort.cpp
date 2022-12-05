#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int a[n]{0};
    cout << "Enter elements: ";
    for (int i{0}; i < n; i++) {
        cin >> a[i];
    }
    cout << "Before sorting\n";
    for (int i{0}; i < n; i++) {
        cout << a[i] << " ";
    }
    insertionSort(a, n);
    cout << endl << "After insertion sorting : \n";
    for (int i{0}; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}