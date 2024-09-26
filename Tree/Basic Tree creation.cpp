#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to insert nodes in level order
Node* insertLevelOrder(int arr[], Node* root, int i, int n) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to calculate the height of the tree
int height(Node* node) {
    if (node == NULL)
        return 0;
    else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

// Function to calculate the depth of a node
int depth(Node* root, Node* node, int level) {
    if (root == NULL)
        return -1;
    if (root == node)
        return level;
    int downlevel = depth(root->left, node, level + 1);
    if (downlevel != -1)
        return downlevel;
    return depth(root->right, node, level + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = insertLevelOrder(arr, root, 0, n);

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Depth of node with value 5: " << depth(root, root->left->right, 0) << endl;

    return 0;
}
