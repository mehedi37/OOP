#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot
    int i = (low - 1);   // Index of smaller element and indicates

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(a, n);
    cout << endl << "After insertion sorting : \n";
    for (int i{0}; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}