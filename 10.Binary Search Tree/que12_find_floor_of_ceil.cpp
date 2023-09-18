// https://practice.geeksforgeeks.org/problems/floor-in-bst/1

void solve(Node* root, int k, int& ans){
    if(root == NULL){
        return;
    }
    k
    if(root->data == k){
        ans = k;
        return;
    }
    
    if(root-> data > k){
        solve(root->left, k, ans);
    }
    else{
        ans = max(ans, root->data);
        solve(root->right, k, ans);
    }
}
int floor(Node* root, int k) {
    // Code here
    if (root == NULL) return -1;
    
    int ans = INT_MIN;
    
    solve(root,k, ans);
    
    if(ans == INT_MIN){
        return -1;
    }
    else{
        return ans;
    }
}
