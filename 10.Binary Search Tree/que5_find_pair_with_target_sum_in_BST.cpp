// https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

//Approach-> find inorder , we know its sorted so apply two pointer approach to find pair sum.

void inorder(Node* root,  vector<int>& inVal){
    if(root == NULL){
        return;
    }
    
    inorder(root->left, inVal);
    
    inVal.push_back(root->data);
    
    inorder(root->right, inVal);
}
int isPairPresent(struct Node *root, int target)
{
//add code here.
    vector<int> inVal;
    inorder(root, inVal);
    
    int n = inVal.size();
    int i=0;
    int j = n - 1;
    
    while(i < j){
        int sum = inVal[i] + inVal[j];
        
        if(sum == target){
            return 1;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    
    return 0;
    
    
    
}