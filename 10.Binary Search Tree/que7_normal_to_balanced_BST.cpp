// https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

void inorder(Node* root,  vector<int>& inVal){
    if(root == NULL){
        return;
    }
    
    inorder(root->left, inVal);
    
    inVal.push_back(root->data);
    
    inorder(root->right, inVal);
}

//here balanced tree is getting build...
Node* solve(vector<int> inVal, int i, int j){
    if(i > j){
        return NULL;
    }
    
    int mid = (i+j)/2;
    
    Node* root = new Node(inVal[mid]);
    
    root->left = solve(inVal, i, mid-1);
    root->right = solve(inVal, mid+1, j);
    
    return root;
}

Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> inVal;
    inorder(root, inVal);
    
    int n = inVal.size();
    int j = n-1;
    int i = 0;
    
    return solve(inVal,i,j);
}