// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// Approach -> simply storing elements level by level in each vector...
// 1
// 2 3
// 4 5 
// --> [[1], [2 3], [4 5]]; storing level by level ...

vector <int> zigZagTraversal(Node* root)
{
    // Code here
    vector<vector<int>> l;
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr != NULL){
            v.push_back(curr->data);
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        else{
            l.push_back(v);
            while(!v.empty()){
                v.pop_back();
            }
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
    bool leftToRight = true;
    vector<int> ans;
    for(int i=0; i< l.size(); i++){
        if(leftToRight){
            for(int j=0; j<l[i].size(); j++){
                ans.push_back(l[i][j]);
            }
        }
        else{
            for(int j=l[i].size()-1; j>=0; j--){
                ans.push_back(l[i][j]);
            }
        }
        leftToRight = !leftToRight;
    }
    return ans;
}