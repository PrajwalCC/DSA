// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
int height(struct Node* node){
    // code here
    if(node == NULL){
        return 0;
    }
    
    int heightLeftPart = height(node->left);
    int heightRightPart = height(node->right);
    
    return max(heightLeftPart, heightRightPart)+1;
}