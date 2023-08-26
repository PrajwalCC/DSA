// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
vector<int> leftView(Node *root){
    // Your code here
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    queue<pair<int,Node*>> q;
    map<int,int>m;
    q.push({0, root});
    while(!q.empty()){
        Node* curr = q.front().second;
        int level = q.front().first;
        q.pop();
        
        auto it = m.find(level);
        if(it == m.end()){
            m[level] = curr->data;
        }
        
        if(curr->left){
            q.push({level+1, curr->left});
        }
        if(curr->right){
            q.push({level+1, curr->right});
        }
    }


    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}