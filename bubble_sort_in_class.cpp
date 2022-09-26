#include <iostream>

using namespace std;

class ajairaArray
{
private:
    int *x;
    int size;

public:
    ajairaArray(int arr[], int n) {
        x = arr;
        size = n;
    }
    void bbSrt() {
        for (int i{0}; i < size; i++) {
            for (int j{0}; j < size-i-1; j++) {
                if (x[j] > x[j+1]) swap(x[j], x[j+1]);
            }
        }
    }
    void print() {
        for (int i{0}; i < size; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n; cin >> n;
    int arr[n];
    for (int i{0}; i < n; i++) {
        cin >> arr[i];
    }
    ajairaArray a(arr, n);
    a.bbSrt();
    a.print();

}
