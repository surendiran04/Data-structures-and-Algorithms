vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, in, post;
    if (root == NULL) {
        return {};
    }

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it); 
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second = 3;
            st.push(it); 
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}

//recursive approach
void Inorder(TreeNode* p,vector<int>&v){
    if(p){
        Inorder(p->left,v);
        v.push_back(p->data);
        Inorder(p->right,v);
    }
}
void preorder(TreeNode* p,vector<int>&v){
    if(p){
        v.push_back(p->data);
        preorder(p->left,v);
        preorder(p->right,v);
    }
}
void postorder(TreeNode* p,vector<int>&v){
    if(p){
        postorder(p->left,v);
        postorder(p->right,v);
        v.push_back(p->data);   
    }
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> v;
    vector<int> v1,v2,v3;
    Inorder(root,v1);
    preorder(root,v2);
    postorder(root,v3);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    return v;
}
