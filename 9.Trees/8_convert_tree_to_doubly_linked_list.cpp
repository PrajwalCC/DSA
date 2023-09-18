// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

// approach 1:- form vector of inorder , then convert vector to doubly linked list...

// approach 2:- without using extra space ... using only recurrsion ...
// here is approach 2,
Node* solve(Node* root){
    if(root == NULL){
        return NULL;
    }
        
    Node* rightHead = solve(root->right);
        
    if(rightHead != NULL){
        rightHead->left = root;
    }
        
    root->right = rightHead;
        
    Node* leftHead = solve(root->left);
        
    if(leftHead != NULL){
        Node* temp = leftHead;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = root;
        root->left = temp;
    }
        
    return (leftHead != NULL) ? leftHead : root;
}


//Function to convert binary tree to doubly linked list and return it.
Node * treeToDLL(Node *root)
{
    // your code here
    return solve(root);
}