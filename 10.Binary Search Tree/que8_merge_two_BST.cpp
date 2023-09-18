// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

// Approach-> find inorder of both BST then merge that both inorder to form one sorted array
//            then form balanced BST from that merged sorted array;

// but here in this gfg que, our task was to just simply return the merged vector ..
void inorderfunc(Node* root, vector<int>& inorder){
    if(root==NULL){
        return ;
    }
    
    inorderfunc(root->left, inorder);
    
    inorder.push_back(root->data);
    
    inorderfunc(root->right, inorder);
}

vector<int> mergefunc(vector<int> inorder1, vector<int> inorder2){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<inorder1.size() && j<inorder2.size()){
        
        if(inorder1[i] < inorder2[j]){
            ans.push_back(inorder1[i]);
            i++;
        }
        else{
            ans.push_back(inorder2[j]);
            j++;
        }
    }
    
    while(i < inorder1.size()){
        ans.push_back(inorder1[i]);
        i++;
    }
    
    while(j < inorder2.size()){
        ans.push_back(inorder2[j]);
        j++;
    }
    
    return ans;
}

vector<int> merge(Node *root1, Node *root2)
{
    //Your code here
    vector<int> inorder1;
    vector<int> inorder2;
    
    inorderfunc(root1, inorder1);
    inorderfunc(root2, inorder2);
    
    vector<int> mergedInorder = mergefunc(inorder1, inorder2);
    
    return mergedInorder;
}