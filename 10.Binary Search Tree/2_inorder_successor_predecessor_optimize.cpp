// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

// Directly successor and predecessor can be obtain by forming inorder sequences
// Which will use space ...

// for S.C O(1) ... without using queue,stack, recurrsion ...

Node* succFind(Node* root, int x){
    Node* succ = NULL;
    Node* curr = root;
    while(curr){
        
        if(curr->key == x){
            curr = curr->right;
        }
        else if(x > curr->key){
            curr = curr->right;
        }
        else if(x < curr->key){
            succ = curr;
            curr = curr->left;
        }
        
    }
    
    return succ;
}

Node* preFind(Node* root, int x){
    Node* pre = NULL;
    Node* curr = root;
    
    while(curr){
        
        if(curr->key == x){
            curr = curr->left;
        }
        else if(x > curr->key){
            pre = curr;
            curr = curr->right;
        }
        else if(x < curr->key){
            curr = curr->left;
        }
        
        
    }
    
    return pre;
}
