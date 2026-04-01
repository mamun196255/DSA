#include <iostream>
using namespace std;

#define MAX 100

int heap[MAX];
int n = 0;

// Insert item into max-heap
void insertHeap(int item) {
    int ptr, par; // Current, Parent position
    
    n = n + 1;
    ptr = n;
    
    while (ptr > 1) { // index 1 (start)
        par = ptr / 2;
        
        if (item <= heap[par]) {
            break;
        } else {
            heap[ptr] = heap[par];
            ptr = par;
        }
    }
    heap[ptr] = item;
}

// Display heap
void display() {
    cout << "Heap: ";
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    insertHeap(50);
    insertHeap(30);
    insertHeap(40);
    insertHeap(10);
    insertHeap(70);
    
    display();
    
    return 0;
}
