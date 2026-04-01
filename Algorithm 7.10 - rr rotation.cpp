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

// Right-Right (RR) Rotation
Node* RR_Rotation(Node* A) {
    Node* B = A->right;

    A->right = B->left;
    B->left  = A;

    A->bf = 0;
    B->bf = 0;

    cout << "RR Rotation performed. New root: " << B->info << endl;
    return B;  // B is new root
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
    root->right = createNode(20);
    root->right->bf = -1;
    root->right->right = createNode(30);

    cout << "Before RR Rotation (Inorder): ";
    inorder(root);
    cout << endl;

    // Perform RR rotation
    root = RR_Rotation(root);

    cout << "After RR Rotation (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
