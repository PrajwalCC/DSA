// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
pair<bool,int> fastIsBalance(Node* root){
    if(root == NULL){
        return {true, 0};
    }
    pair<bool, int> left = fastIsBalance(root->left);
    pair<bool, int> right = fastIsBalance(root->right);
    
    int height = max(left.second,right.second) + 1;
    
    bool CheckLeft = left.first;
    bool CheckRight = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    
    bool balanced = false;
    
    if(CheckLeft & CheckRight & diff){
        balanced = true;
    }
    
    return {balanced,height};
    
}
bool isBalanced(Node *root)
{
    //  Your Code here
    
    return fastIsBalance(root).first;
}