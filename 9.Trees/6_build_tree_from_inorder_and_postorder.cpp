// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int findPosition(int in[], int inStart, int inEnd, int element){
    for(int i=inStart; i<=inEnd; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[], int post[], int n, int& postIdx, int inStart, int inEnd){
    if(postIdx == -1 || inStart > inEnd){
        return NULL;
    }
    
    Node* root = new Node(post[postIdx]);
    
    int position = findPosition(in, inStart, inEnd, post[postIdx]);
    
    postIdx = postIdx - 1;
    
    root->right = solve(in, post, n, postIdx, position+1, inEnd);
    
    root->left = solve(in, post, n, postIdx, inStart, position-1);
    
    return root;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIdx = n - 1;
    int inStart = 0;
    int inEnd = n - 1;
    
    Node* ans = solve(in, post, n, postIdx, inStart, inEnd);
    return ans;
    
}