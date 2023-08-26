// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

pair<int,int> solve(Node* root){
    if(root == NULL){
        return {0,0};
    }
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
    
    int currInclude = root->data + left.second + right.second;
    int currExclude = max(left.first, left.second) + max(right.first, right.second);
    
    return {currInclude, currExclude};
}
int getMaxSum(Node *root) 
{
    // Add your code here
    pair<int, int> ans = solve(root);
    
    return max(ans.first, ans.second);
}