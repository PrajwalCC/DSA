// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

// we know that inorder of BST is in sorted order, find kth element from front in inorder...
int solve(Node* root, int k, int &count){
    if(root == NULL){
        return -1;
    }
    
    int left = solve(root->left, k, count);
    
    if(left != -1){
        return left;
    }
    
    count++;
    if(count == k){
        return root->data;
    }
    
    return solve(root->right, k, count);
}

int KthSmallestElement(Node *root, int k) {
    // add code here.
    int count = 0;
    return solve(root, k, count);
}