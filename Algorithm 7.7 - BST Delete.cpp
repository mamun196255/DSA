#include <iostream>
using namespace std;

// Node structure
struct Node {
    int info;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        info = value;
        left = nullptr;
        right = nullptr;
    }
};

// Create node (optional since constructor exists)
Node* createNode(int value) {
    return new Node(value);
}

// Insert node in BST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->info)
        root->left = insert(root->left, value);
    else if (value > root->info)
        root->right = insert(root->right, value);

    return root;
}

// Delete node with 0 or 1 child (Case A and Case B)
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        cout << value << " not found in the tree!" << endl;
        return nullptr;
    }

    if (value < root->info)
        root->left = deleteNode(root->left, value);  // Go left
    else if (value > root->info)
        root->right = deleteNode(root->right, value); // Go right
    else {
        // Case A: No children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            cout << "Deleting " << value << " (Case A: leaf node)" << endl;
            delete root;
            return nullptr;
        }
        // Case B: Only right child exists
        else if (root->left == nullptr) {
            cout << "Deleting " << value << " (Case B: has right child only)" << endl;
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case B: Only left child exists
        else if (root->right == nullptr) {
            cout << "Deleting " << value << " (Case B: has left child only)" << endl;
            Node* temp = root->left;
            delete root;
            return temp;
        }
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->info << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    cout << "Before deletion: ";
    inorder(root);
    cout << endl;

    // Case A: Delete leaf node 20
    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;

    // Case B: Delete node 30 (which now has only right child 40)
    root = deleteNode(root, 30);
    cout << "After deleting 30: ";
    inorder(root);
    cout << endl;

    return 0;
}
