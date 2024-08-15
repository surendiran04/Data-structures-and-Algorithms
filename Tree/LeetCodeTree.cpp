#include <iostream>
#include <queue>

using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
};
 
Node* createNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->data << " ";
    }
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
}

int countNode(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = countNode(root->left);
    int right = countNode(root->right);
    return left + right + 1;
}

void Leaf(Node* root) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        std::cout << root->data << " ";
    }
    Leaf(root->left);
    Leaf(root->right);
}

int sum(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = sum(root->left);
    int right = sum(root->right);
    return left + right + root->data;
}

void invert(Node* root) {
    if (root == nullptr) {
        return;
    }
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert(root->left);
    invert(root->right);
}



void leftView(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    leftView(root->left);
}

void rightView(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    rightView(root->right);
}

void topView(Node* root) {
    if (root == nullptr) {
        return;
    }
    leftView(root->left);
    std::cout << root->data << " ";
    rightView(root->right);
}

void bottomView(Node* root) {
    if (root == nullptr) {
        return;
    }
    bottomView(root->left);
    std::cout << root->data << " ";
    bottomView(root->right);
}

void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        std::cout << temp->data << " ";
        q.pop();
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }
}

int main() {
    Node* p = createNode(4);
    Node* p1 = createNode(1);
    Node* p2 = createNode(6);
    Node* p3 = createNode(5);
    Node* p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    std::cout << "Preorder Traversal: ";
    preOrder(p);
    std::cout << "\n";

    std::cout << "Postorder Traversal: ";
    postOrder(p);
    std::cout << "\n";

    std::cout << "Inorder Traversal: ";
    inOrder(p);
    std::cout << "\n";

    std::cout << "Count Nodes: " << countNode(p) << "\n";
    std::cout << "Leaf Nodes: ";
    Leaf(p);
    std::cout << "\n";

    std::cout << "Sum: " << sum(p) << "\n";

    std::cout << "Left View: ";
    leftView(p);
    std::cout << "\n";

    std::cout << "Right View: ";
    rightView(p);
    std::cout << "\n";

    std::cout << "Top View: ";
    topView(p);
    std::cout << "\n";

    std::cout << "Bottom View: ";
    bottomView(p);
    std::cout << "\n";

    std::cout << "Level Order: ";
    levelOrder(p);
    std::cout << "\n";

    return 0;
}
