#include <iostream>
using namespace std;

int main() {
    int A[] = {17, 12, 18, 5, 7, 8, 10};
    int n = 7;
    int item = 7;
    int location = -1;

    for (int i = 0; i < n; i++) {
        if (A[i] == item) {
            location = i;
            break;
        }
    }

    if (location != -1) {
        cout << "Item " << item << " found at index " << location << "." << endl;
    } else {
        cout << "Item " << item << " not found." << endl;
    }

    return 0;
}
