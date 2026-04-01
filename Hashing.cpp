#include <iostream>
using namespace std;

// Hash function
int hashAddress(int key, int partSize) {
    int sum = 0;
    int divisor = 1;

    // Compute 10^partSize
    for (int i = 0; i < partSize; i++)
        divisor *= 10;

    // Sum the parts of the key
    while (key > 0) {
        sum += key % divisor;
        key /= divisor;
    }

    return sum;
}

int main() {
    int key = 324112;
    int partSize = 2;

    cout << "Key        : " << key << endl;
    cout << "Part Size  : " << partSize << " digits" << endl;
    cout << "Hash Address: " << hashAddress(key, partSize) << endl;

    return 0;
}
