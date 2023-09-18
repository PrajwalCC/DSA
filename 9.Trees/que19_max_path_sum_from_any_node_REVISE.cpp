// https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1
int solve(Node* root, int& ans){
    if(root == NULL){
        return 0;
    }
    
    int left = solve(root->left, ans);
    int right = solve(root->right, ans);
    
    int d = root->data;
    
    int temp = max(d, max(left+d, max(right+d, d+left+right)));
    
    ans = max(ans, temp);
    
    return max( d , d + max(left, right));
}
int findMaxSum(Node* root)
{
    // Your code goes here
    int ans = INT_MIN;
    solve(root, ans);
    
    return ans;
    
}