// https://practice.geeksforgeeks.org/problems/check-for-bst/1

// we have to make sure that each and every element in left subTree is smaller than curr root or not
// and make sure that each and every element in right subTree is greater than curr root. 

// Method 2:- can be, find inorder traversal and check whether it is sorted or not if sorted then its BST.
// Method 1:- recurrsive way, check each element.
// here is method 1 
bool check(Node* root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=max || root->data<=min){
        return false;
    }
    bool leftPart = check(root->left, min, root->data);
    bool rightPart = check(root->right, root->data, max);
    
    return leftPart && rightPart;
}

bool isBST(Node* root) 
{
    return check(root, INT_MIN, INT_MAX);
}