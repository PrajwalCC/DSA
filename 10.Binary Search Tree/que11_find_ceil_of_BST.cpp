// https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

void solve(Node* root, int k, int& ans){
    if(root == NULL){
        return;
    }
    
    if(root->data == k){
        ans = k;
        return;
    }
    
    if(root-> data > k){
        ans = min(ans, root->data);
        solve(root->left, k, ans);
    }
    else{
        solve(root->right, k, ans);
    }
}

int findCeil(Node* root, int k) {
    if (root == NULL) return -1;
    
    int ans = INT_MAX;
    
    solve(root,k, ans);
    
    if(ans == INT_MAX){
        return -1;
    }
    else{
        return ans;
    }
    
    // Your code here
}