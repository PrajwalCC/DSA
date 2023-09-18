// https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1

void countNode(LNode* head, int& count){
    if(head == NULL){
        return;
    }
    count++;
    countNode(head->next, count);
}

TNode* solve(LNode*& head, int n){
    if(head == NULL || n == 0){
        return NULL;
    }
    
    TNode* leftNode = solve(head, n/2);
    
    TNode* root = new TNode(head->data);
    
    root->left = leftNode;
    
    head = head->next;
    
    TNode* rightNode = solve(head, n-(n/2)-1);
    
    root->right = rightNode;
    
    return root;
    
}

TNode* sortedListToBST(LNode *head) {
    //code here
    int count = 0;
    countNode(head, count);
    int n = count;
    
    return solve(head, n);
}