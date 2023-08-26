
void solve(Node *root, int node, vector<int>& traversal){
    if(root == NULL){
        return;
    }

    traversal.push_back(root->data);

    if(root->data == node){
        for(auto i:traversal){
            cout<<i<<" ";
        }
        return;
    }

    solve(root->left, node, traversal);
    solve(root->right, node, traversal);

    traversal.pop_back();
}