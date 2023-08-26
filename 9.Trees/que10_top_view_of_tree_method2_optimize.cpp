// here we are using Level order traversal ..
// map<int,int> , first int = horizontal distance and second int = node->data ..
// we are mapping each horizontal value with one node ..
// 
// ****###** in level order traversal we are travelling from top to bottom of tree , so if any element is present
// for any horizontal value then we will not take other element ... 

// 
vector<int> topView(Node *root){
    //Your code here
    queue<pair<Node*,int>> q;
    map<int,int> m;
    q.push({root, 0});
    while(!q.empty()){
        
        Node* curr = q.front().first;
        int value = q.front().second;
        q.pop();
        
        auto it = m.find(value);
        if(it == m.end()){
            m[value] = curr->data;
        }
        
        if(curr->left != NULL){
            q.push({curr->left, value-1});
        }
        if(curr->right != NULL){
            q.push({curr->right, value+1});
        }
    }
    vector<int> ans;
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}