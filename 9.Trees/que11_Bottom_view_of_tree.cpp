// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
vector <int> bottomView(Node *root) {
    // Your Code Here
    map<int,int> m;
    queue<pair<int, Node*>> q;
    q.push({0, root});
    while(!q.empty()){
        Node* curr = q.front().second;
        int value = q.front().first;
        q.pop();
        
        m[value] = curr->data;
        
        if(curr->left){
            q.push({value-1, curr->left});
        }
        if(curr->right){
            q.push({value+1, curr->right});
        }
    }
    
    vector<int> ans;
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}