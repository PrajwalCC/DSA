// https://practice.geeksforgeeks.org/problems/pth-common-ancestor-in-bst/1

NODE* LCA(NODE *root, int n1, int n2, vector<int> &store)
{
    // code here
    if(root == NULL){
        return NULL;
    }
    
    if(root->data > n1 && root->data > n2){
        store.push_back(root->data);
        return LCA(root->left, n1, n2, store);
    }
    else if(root->data < n1 && root->data < n2){
        store.push_back(root->data);
        return LCA(root->right, n1, n2, store);
    }
    else{
        return root;
    }
}

int pthCommonAncestor(int x,int y,NODE *root,int p,vector<int> &vec){
     /*Your code here */
     if(root == NULL){
         return -1;
     }
     vector<int> store;
    
    NODE* lcaNODE = LCA(root, x, y, store);
    if(lcaNODE == NULL){
        return -1;
    }
    
    store.push_back(lcaNODE->data);
    
    int n = store.size();
    
    int k = n - p ;
    
    if(k >= 0){
        return store[k];
    }
    else{
        return -1;
    }
}