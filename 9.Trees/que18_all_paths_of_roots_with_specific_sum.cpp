// https://practice.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

void solve(Node* root, int sum, vector<vector<int>>& ans, vector<int>& temp){
    
    if(root == NULL){
        return;
    }
    
    
    temp.push_back(root->key);
    if(sum - root->key == 0){
        ans.push_back(temp);
    }
    
    solve(root->left, sum - root->key, ans, temp);
    solve(root->right, sum - root->key, ans, temp);
    
    temp.pop_back();
}
vector<vector<int>> printPaths(Node *root, int sum)
{
    //code here
    vector<vector<int>> ans;
    vector<int> temp;
    
    solve(root,sum, ans, temp);
    
    return ans;
}