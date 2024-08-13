#include <iostream>

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;

    Node(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

class Tree {
public:
    Node* generateFromTraversal(int* inorder, int* postorder, int inStart, int inEnd);
    int searchInorder(int inArray[], int inStart, int inEnd, int data);
};

int Tree::searchInorder(int inArray[], int inStart, int inEnd, int data) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inArray[i] == data) {
            return i;
        }
    }
    return -1;
}

Node* Tree::generateFromTraversal(int* inorder, int* postorder, int inStart, int inEnd) {
    static int postIndex = inEnd;

    if (inStart > inEnd) {
        return nullptr;
    }

    // The last element in postorder is the root node
    Node* node = new Node(postorder[postIndex--]);

    // If the node has no children (leaf node)
    if (inStart == inEnd) {
        return node;
    }

    // Find the index of this node in inorder traversal
    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);

    // Build the right subtree first (since postorder traverses left->right->root)
    node->rchild = generateFromTraversal(inorder, postorder, splitIndex + 1, inEnd);
    node->lchild = generateFromTraversal(inorder, postorder, inStart, splitIndex - 1);

    return node;
}

int main() {
    Tree tree;
    
    // Example inorder and postorder traversals
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    
    Node* root = tree.generateFromTraversal(inorder, postorder, 0, n - 1);
    
    // Additional code to display the tree can be added here
    
    return 0;
}
