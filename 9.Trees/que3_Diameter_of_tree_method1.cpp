// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
int height(Node* node){
    // code here
    if(node == NULL){
        return 0;
    }
    
    int heightLeftPart = height(node->left);
    int heightRightPart = height(node->right);
    
    return max(heightLeftPart, heightRightPart)+1;
}
int diameter(Node* root) {
    // Your code here
    if(root == NULL){
        return 0;
    }
    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left)+height(root->right)+1;
    return max(opt1, max(opt2, opt3));
}