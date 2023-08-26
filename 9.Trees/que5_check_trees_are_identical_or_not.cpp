// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;
    if(left&right&value){
        return true;
    }
    else{
        return false;
    }
}