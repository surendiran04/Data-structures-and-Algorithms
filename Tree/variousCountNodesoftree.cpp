#include <iostream>
#include <queue>
#include <stack>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
    Node() {};
    Node(int data);
};
 
Node::Node(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}
 
class Tree{
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
    int Height(Node* p);
    int Height() { return Height(root); }
    int Count(Node* p);
    int Count(){ Count(root); }
    int Sum(Node* p);
    int Sum(){ Sum(root); }
    int deg2NodeCount(Node* p);
    int deg2NodeCount(){ deg2NodeCount(root); }
    int leafNodeCount(Node* p);
    int deg1ordeg2NodeCount(Node* p);
    int deg1NodeCount(Node* p);
    void DestroyTree(Node* p);
};
 
Tree::Tree() {
    root = nullptr;
}
 
Tree::~Tree() {
    DestroyTree(root);
}
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}
 
Node* Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) {
    static int preIndex = 0;
 
    if (inStart > inEnd){
        return nullptr;
    }
 
    Node* node = new Node(preorder[preIndex++]);
 
    if (inStart == inEnd){
        return node;
    }
 
    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);
 
    return node;
}
 
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
 
    if (p != nullptr){
        l = Height(p->lchild);
        r = Height(p->rchild);
        if (l > r){
            return l + 1;
        } else {
            return r + 1;
        }
    }
    return 0;
}
 
int Tree::Count(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}
 
int Tree::Sum(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}
// int sum(TreeNode* p){ sum of leaf node
//         int l,r;
//         if(p){
//             if(p->left==nullptr && p->right==nullptr){
//                 return p->val;
//             }
//             else{
//                 return sum(p->left)+sum(p->right);
//             } 
//         }
//         return 0;
//   }
 
int Tree::deg2NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        if (p->lchild && p->rchild){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
int Tree::leafNodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = leafNodeCount(p->lchild);
        y = leafNodeCount(p->rchild);
        if (p->lchild == nullptr && p->rchild == nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
int Tree::deg1ordeg2NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg1ordeg2NodeCount(p->lchild);
        y = deg1ordeg2NodeCount(p->rchild);
        if (p->lchild != nullptr || p->rchild != nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
int Tree::deg1NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg1NodeCount(p->lchild);
        y = deg1NodeCount(p->rchild);
        if (p->lchild != nullptr ^ p->rchild != nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
void Tree::DestroyTree(Node *p) {
    if (p != nullptr){
        DestroyTree(p->lchild);
        DestroyTree(p->rchild);
        delete p;
    }
}
 
 
int main() {
 
    Tree bt;
 
    int preorder[] = {8, 3, 12, 4, 9, 7, 5, 10, 6, 2};
    int inorder[] = {12, 9, 4, 7, 3, 8, 10, 5, 2, 6};
 
    int size = sizeof(inorder)/sizeof(inorder[0]);
 
    Node* T = bt.generateFromTraversal(inorder, preorder, 0, size-1);
 
 
    cout << "Inorder: " << flush;
    bt.Inorder(T);
    cout << endl;
 
    cout << "Height: " << bt.Height(T) << endl;
    cout << "Count: " << bt.Count(T) << endl;
    cout << "Sum: " << bt.Sum(T) << endl;
    cout << "# of degree 2 nodes: " << bt.deg2NodeCount(T) << endl;
    cout << "# of leaf nodes: " << bt.leafNodeCount(T) << endl;
    cout << "# of degree 1 or degree 2 nodes: " << bt.deg1ordeg2NodeCount(T) << endl;
    cout << "# of degree 1 nodes: " << bt.deg1NodeCount(T) << endl;
 
    bt.DestroyTree(T);
 
    return 0;
}

// Inorder: 12, 9, 4, 7, 3, 8, 10, 5, 2, 6, 
// Height: 5
// Count: 10
// Sum: 66
// # of degree 2 nodes: 3
// # of leaf nodes: 4
// # of degree 1 or degree 2 nodes: 6
// # of degree 1 nodes: 3
