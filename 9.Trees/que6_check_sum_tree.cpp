// https://practice.geeksforgeeks.org/problems/sum-tree/1
 pair<bool, int> fastCheck(Node* root){
    if(root == NULL){
        return {true, 0};
    }
    if(root->left == NULL && root->right == NULL){
        return {true, root->data};
    }
    
    pair<bool, int> left = fastCheck(root->left);
    pair<bool, int> right = fastCheck(root->right);
    
    int leftSum = left.second;
    int rightSum = right.second;
    
    bool sumCheck = root->data == leftSum + rightSum;
    
    bool leftCheck = left.first;
    bool rightCheck = right.first;
    
    if(sumCheck && leftCheck && rightCheck){
        return {true, root->data + leftSum + rightSum}; //niche ka sara subtree ka value store krte chalna hai
    }
    else{
        return {false,0};
    }
    
}
bool isSumTree(Node* root)
{
        // Your code here
    return fastCheck(root).first;
}