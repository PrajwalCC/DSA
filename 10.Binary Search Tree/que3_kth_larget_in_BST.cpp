// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//  we know that inorder of BST is in sorted order, find kth element from back in inorder...
void solve(Node* root, vector<int>& inorder){
    if(root == NULL){
        return;
    }
    
    solve(root->left, inorder);
    inorder.push_back(root->data);
    solve(root->right, inorder);
    
}
int kthLargest(Node *root, int k)
{
    //Your code here
    vector<int> inorder;
    solve(root, inorder);
    
    int n = inorder.size();
    return inorder[n-k];
}