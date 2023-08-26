// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
int height(Node* node){
    // code here
    if(node == NULL){
        return 0;
    }
    
    int heightLeftPart = height(node->left);
    int heightRightPart = height(node->right);
    
    return max(heightLeftPart, heightRightPart)+1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    if(root == NULL){
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if(left&right&diff){
        return true;
    }
    else{
        return false;
    }
}