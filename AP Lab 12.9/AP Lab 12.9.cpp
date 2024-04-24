#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* newNode = new Node();
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else {
        if (key < root->key) {
            root->left = insert(root->left, key);
        }
        else {
            root->right = insert(root->right, key);
        }
        return root;
    }
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int k = 70;
    if (search(root, k) != NULL) {
        cout << "Element " << k << " found in binary tree" << endl;
    }
    else {
        cout << "Element " << k << " didn`t find in binary tree" << endl;
    }

    return 0;
}