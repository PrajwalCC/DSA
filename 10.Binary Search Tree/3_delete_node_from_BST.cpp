//https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

Node* getMin(Node* root){
    if(root -> left == NULL){
        return root;
    }
    
    return getMin(root->left);
}
Node *deleteNode(Node *root, int x) {
    // your code goes here
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == x){
        if(root->left==NULL && root->right==NULL){//leaf node deletion
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
           delete root;
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left!=NULL && root->right!=NULL){// Main case IMPT
            Node* min = getMin(root->right);
            int dataMin = min->data;
            root->data = dataMin;
            
            root->right = deleteNode(root->right, dataMin);
            return root;
            
        }
    }
    else if(x > root->data){
        root->right = deleteNode(root->right, x);
        return root;
    }
    else{
        root->left = deleteNode(root->left, x);
        return root;
    }
    
}