// https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

void solve(Node* root, int &ans, int k){
    if(root == NULL){
        return;
    }
    ans = min(ans, abs(root->data - k));
    
    if(k > root->data){
        solve(root->right, ans, k);
    }
    else{
        solve(root->left, ans, k);
    }
}
int minDiff(Node *root, int k)
{
    //Your code here
    int ans = INT_MAX;
    solve(root, ans, k);
    return ans;
}