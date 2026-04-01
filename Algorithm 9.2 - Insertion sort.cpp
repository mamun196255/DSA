#include <iostream>
using namespace std;

int main() {
    int A[] = {17, 12, 18, 5, 7, 10, 8};
    int n = 7;
    int key_value, i;

    // Insertion Sort
    for (int j = 1; j < n; j++) {
        key_value = A[j];
        i = j - 1;

        while (i >= 0 && A[i] > key_value) {
            A[i + 1] = A[i];
            i = i - 1;
        }

        A[i + 1] = key_value;
    }

    // Print sorted array
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
