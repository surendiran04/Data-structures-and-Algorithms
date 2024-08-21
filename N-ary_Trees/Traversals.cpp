class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    
    Node(int _val) {
        val = _val;
    }
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void preorder(Node* root) {
    if (root == nullptr) return;

    // Visit the root node
    cout << root->val << " ";

    // Recursively visit all children
    for (Node* child : root->children) {
        preorder(child);
    }
}
void postorder(Node* root) {
    if (root == nullptr) return;

    // Recursively visit all children
    for (Node* child : root->children) {
        postorder(child);
    }

    // Visit the root node
    cout << root->val << " ";
}
void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        // Visit the current node
        cout << node->val << " ";

        // Add all the children to the queue
        for (Node* child : node->children) {
            q.push(child);
        }
    }
}
        1
       /|\
      2 3 4
     /|   |
    5 6   7

Traversals:
Preorder: 1 2 5 6 3 4 7
Postorder: 5 6 2 3 7 4 1
Level Order: 1 2 3 4 5 6 7
