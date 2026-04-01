#include <iostream>
using namespace std;

// Node structure
struct Node {
    int info;
    Node* left;
    Node* right;

    // Constructor for convenience
    Node(int value) {
        info = value;
        left = nullptr;
        right = nullptr;
    }
};

// Preorder traversal
void Preorder(Node* ROOT) {
    if (ROOT == nullptr)
        return;

    cout << ROOT->info << " ";
    Preorder(ROOT->left);
    Preorder(ROOT->right);
}

int main() {
    // Creating the binary tree
    Node* ROOT = new Node(10);
    ROOT->left = new Node(5);
    ROOT->right = new Node(20);
    ROOT->left->left = new Node(3);
    ROOT->left->right = new Node(7);
    ROOT->right->right = new Node(30);

    // Preorder traversal
    cout << "Preorder Traversal: ";
    Preorder(ROOT);
    cout << endl;

    return 0;
}
