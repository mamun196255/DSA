#include <iostream>
using namespace std;

// Merge function
void Merge(int A[], int f, int m, int l) {
    int T[100]; // Temporary array
    int i = f, j = m + 1, k = f;

    // Merge the two subarrays
    while (i <= m && j <= l) {
        if (A[i] <= A[j]) {
            T[k] = A[i];
            i++;
        } else {
            T[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from first subarray
    while (i <= m) {
        T[k] = A[i];
        i++;
        k++;
    }

    // Copy remaining elements from second subarray
    while (j <= l) {
        T[k] = A[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (int i = f; i <= l; i++) {
        A[i] = T[i];
    }
}

// Merge Sort function
void merge_sort(int A[], int f, int l) {
    if (f < l) {
        int m = (f + l) / 2;
        merge_sort(A, f, m);
        merge_sort(A, m + 1, l);
        Merge(A, f, m, l);
    }
}

int main() {
    int A[] = {18, 26, 32, 6, 43, 15, 9, 1};
    int n = 8;

    merge_sort(A, 0, n - 1);

    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
