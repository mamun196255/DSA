#include <iostream>
using namespace std;

// Node structure
struct Node {
    int info;
    int bf;       // Balance factor
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        info = value;
        bf = 0;
        left = nullptr;
        right = nullptr;
    }
};

// Create node (optional since constructor exists)
Node* createNode(int value) {
    return new Node(value);
}

// Right-Left (RL) Rotation
Node* RL_Rotation(Node* A) {
    Node* B = A->right;   // Right child
    Node* C = B->left;    // Left child of B

    // Perform rotation
    B->left  = C->right;
    C->right = B;

    A->right = C->left;
    C->left  = A;

    // Reset balance factors
    A->bf = 0;
    B->bf = 0;
    C->bf = 0;

    cout << "RL Rotation performed. New root: " << C->info << endl;
    return C;  // C is new root
}

// Inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->info << "(BF=" << root->bf << ") ";
        inorder(root->right);
    }
}

int main() {
    // Creating AVL-like tree
    Node* root = createNode(10);
    root->bf = -2;
    root->right = createNode(30);
    root->right->bf = +1;
    root->right->left = createNode(20);

    cout << "Before RL Rotation (Inorder): ";
    inorder(root);
    cout << endl;

    // Apply RL rotation
    root = RL_Rotation(root);

    cout << "After RL Rotation (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
