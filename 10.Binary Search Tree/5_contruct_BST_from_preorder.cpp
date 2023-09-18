// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
// check notes, 3 approach are discuss there

// this is O(n) T.C....
TreeNode* solve(vector<int>& preorder, int mini, int maxi, int& i){
    if(i >= preorder.size() ){
        return NULL;
    }

    if(preorder[i]<mini || preorder[i] > maxi){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[i]);
    i = i+1;
    root->left = solve(preorder, mini, root->val, i);

    root->right = solve(preorder, root->val, maxi, i);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;

    int i=0;

    return solve(preorder,mini, maxi, i);
}