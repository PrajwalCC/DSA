// here we will not use 2D vector, 
vector <int> zigZagTraversal(Node* root)
{
    
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
            
            int idx = leftToRight? i : n-1-i;
            
            temp[idx] = curr->data;
            
            q.pop();
        }
        
        for(int j=0; j<n; j++){
            v.push_back(temp[j]);
        }
        leftToRight = !leftToRight;
    }
    
    return v;
}