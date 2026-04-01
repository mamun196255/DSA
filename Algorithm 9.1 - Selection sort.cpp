#include <iostream>
using namespace std;

int main() {
    int A[] = {12, 18, 5, 7, 10, 8, 17};
    int n = 7;
    int small_index, temp;

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        small_index = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[small_index]) {
                small_index = j;
            }
        }

        // Swap
        temp = A[i];
        A[i] = A[small_index];
        A[small_index] = temp;
    }

    // Print sorted array
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
