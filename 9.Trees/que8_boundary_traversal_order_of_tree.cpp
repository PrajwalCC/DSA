// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
void leftNode(Node* root, vector<int>& ans){
    if(root == NULL || (root->left == NULL && root->right == NULL) ){
        return ;
    }
    
    ans.push_back(root->data);
    if(root->left){
        leftNode(root->left, ans);
    }
    else{
        leftNode(root->right, ans);
    }
}

void rightNode(Node* root, vector<int>& v){
    if(root == NULL || (root->left == NULL && root->right == NULL) ){
        return ;
    }
    
    if(root->right){
        rightNode(root->right, v);
    }
    else{
        rightNode(root->left, v);
    }
    v.push_back(root->data);
}

void leafNode(Node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    leafNode(root->left, ans);
    leafNode(root->right, ans);
    
}

vector <int> boundary(Node *root)
{
    //Your code here
    vector<int>ans;
    ans.push_back(root->data);
    
    leftNode(root->left, ans);
    
    leafNode(root->left, ans);
    leafNode(root->right, ans);
    
    
    rightNode(root->right, ans);
    
    return ans;
}