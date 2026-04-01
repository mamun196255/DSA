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

// Left-Right (LR) Rotation
Node* LR_Rotation(Node* A) {
    Node* B = A->left;
    Node* C = B->right;

    // Perform rotation
    B->right = C->left;
    C->left  = B;

    A->left  = C->right;
    C->right = A;

    // Reset balance factors
    A->bf = 0;
    B->bf = 0;
    C->bf = 0;

    cout << "LR Rotation performed. New root: " << C->info << endl;
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
    Node* root = createNode(30);
    root->bf = +2;
    root->left = createNode(10);
    root->left->bf = -1;
    root->left->right = createNode(20);

    cout << "Before LR Rotation (Inorder): ";
    inorder(root);
    cout << endl;

    // Apply LR rotation
    root = LR_Rotation(root);

    cout << "After LR Rotation (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
