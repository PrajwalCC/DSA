// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

// preorder : root,left,right
// inorder   : left,root,right
// so the first element in the preorder is the root of the tree
// starts from preorder index =0 , element = pre[index]
// make a node named root with that element 
// (that is root of the tree is the first element of the preorder array)
// find the index of the root element in the inorder array
// using below function
// findposition - function returns the index of the required element from the array with in provided start and end boundaries of the array
// initially inorder start=0,inorderend=n-1
// position= index of the root element in the inorder array
// now the left portion of the root element in the inorder array that is from the indexstart to position-1 => is the root->left part
// now the right portion of the root element in the inorder array that is from the posotion+1 to indexend => is the root->right part
// preorder index increments each time...
// root->left = recursive call to the same function to find the root of the left sub tree from the inorder array
// root->right=recursive call to the same function to find the root of the right sub tree from the inorder array
// return root
// (base case is when inorderstart>inorderend return NULL
// or preorder index > n , completed tree construnction

// ***function for finding index from inOrder array
int findPosition(int in[], int inStart, int inEnd, int element){
    for(int i=inStart; i<=inEnd; i++){
        if(in[i] == element){
            return i;
        }
    }
    return -1;
}
Node* solve(int in[],int pre[], int n, int& preIdx, int inStart, int inEnd){
    
    if(preIdx == n || inStart > inEnd){
        return NULL;
    }
    
    Node* root = new Node(pre[preIdx]);//creating root node for element taken from preorder array
    
    int position = findPosition(in, inStart, inEnd, pre[preIdx]);//finding this element position in inorder array
    
    preIdx = preIdx + 1;//increasing the index of preorder array
    
    //for left child of root, we are taking inorder array in this range of indexs [inStart, position-1]
    root->left = solve(in, pre, n, preIdx, inStart, position-1);

    //for right child of root, we are taking inorder array in this range of indexs[position+1, inEnd]
    root->right = solve(in, pre, n, preIdx, position+1, inEnd);
    
    //finally we are created the left child and right child of root, now return root.
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    // Code here
    int preIdx = 0;
    int inStart = 0;
    int inEnd = n-1;
    Node* ans = solve(in, pre, n, preIdx, inStart, inEnd);
    return ans;
}