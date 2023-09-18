// https://practice.geeksforgeeks.org/problems/largest-bst/1

// Que -> count the nodes of largest possible BST

class info{
    public:
    int mini;
    int maxi;
    bool check;
    int size;
    
};

class Solution{
    public:
    info solve(Node* root, int& ans){
        if(root == NULL){
            return {INT_MAX, INT_MIN, true, 0};
        }
        
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        
        
        int curr = root->data;
        int currSize = 1 + left.size + right.size;
        int currMax = max(root->data, right.maxi);
        int currMin = min(root->data, left.mini);
        bool currCheck;
        
        if(curr>left.maxi && curr<right.mini && left.check && right.check){
            ans = max(ans, currSize);
            currCheck = true;
        }
        else{
            currCheck = false;
        }
        
        return {currMin, currMax, currCheck, currSize};
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans = 0;
    	info j = solve(root, ans);
    	return ans;
    }
};