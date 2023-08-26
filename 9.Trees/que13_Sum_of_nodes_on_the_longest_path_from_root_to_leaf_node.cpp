// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

void sumOfEveryLeaf(Node* root, map<int,vector<int>> &m, int sum, int length, int& longestLength){
    if(root == NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        m[length+1].push_back(sum + root->data);
        longestLength = max(longestLength, length + 1);
        return;
    }
    sumOfEveryLeaf(root->left, m, sum + root->data, length+1, longestLength);
    sumOfEveryLeaf(root->right, m, sum + root->data, length+1, longestLength);
}
int sumOfLongRootToLeafPath(Node *root)
{
    //code here
    int longestLength = INT_MIN;
    map<int, vector<int>> m;
    sumOfEveryLeaf(root,m, 0,0, longestLength);
    
    vector<int> temp = m[longestLength];
    
    int ans = INT_MIN;
    
    for(int i=0; i<temp.size(); i++){
        ans = max(ans, temp[i]);
    }
    
    return ans;
}