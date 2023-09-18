// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

void preorder(Node* root,  vector<Node*>& preVal){
    if(root == NULL){
        return;
    }
    
    preVal.push_back(root);
    
    preorder(root->left, preVal);
    preorder(root->right, preVal);
}

void flatten(Node *root)
{
    //code here
    vector<Node*> preVal;
    preorder(root, preVal);
    
    int n = preVal.size();
    
    Node* curr = root;
    for(int i=1; i<n; i++){
        
        curr->right = preVal[i];
        curr->left = NULL;
        curr = curr->right;
        
    }
    preVal[n-1]->left = NULL;
    preVal[n-1]->right = NULL;
    
}