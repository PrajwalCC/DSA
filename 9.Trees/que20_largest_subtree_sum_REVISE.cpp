// https://practice.geeksforgeeks.org/problems/largest-subtree-sum-in-a-tree/1

// this solve is giving sum of tree whose head is current Node,
// but mean while are storing the ans which can be possible..
 
int solve(Node* root, int& ans){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int left = solve(root->left, ans);
    
    int right = solve(root->right, ans);
    
    int curr = left + right + root->data;
    
    int temp = max(curr, max(left, right));
    
    ans = max(temp, ans);
    
    return curr;
}

int findLargestSubtreeSum(Node* root)
{
    //Write your code here
    if(root == NULL){
        return 0;
    }
    
    int ans = INT_MIN;
    int temp = solve(root, ans);
    return max(ans, temp);
}