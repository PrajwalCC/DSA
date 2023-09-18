// https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1
bool search(Node* root, int x) {
    // Your code here
    if(root == NULL){
        return false;
    }
    
    if(root->data == x){
        return true;
    }
    
    if(x > root->data){
        return search(root->right, x);
    }
    else{
        return search(root->left, x);
    }
}