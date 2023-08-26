// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

void setValueToMap(Node* root, map<int, map<int,int>>& m, int value, int level){
    if(root==NULL){
        return;
    }
    auto it = m.find(value);
    if(it == m.end()){
        m[value][level] = root->data;
    }
    else{
        map<int,int> prevMap = (*it).second;
        auto p = prevMap.begin();
        int prevLevel = (*p).first;
        if(prevLevel > level){
            m.erase(it);
            m[value][level] = root->data;
        }
    }
    setValueToMap(root->left, m, value-1, level+1);
    setValueToMap(root->right, m, value+1, level+1);
    
}
vector<int> topView(Node *root)
{
    //Your code here
    vector<int> ans;
    map<int, map<int,int>> m;
    setValueToMap(root, m, 0, 0);
    for(auto i: m){
        for(auto j : i.second){
            ans.push_back( j.second );
        }
    }
    return ans;
}