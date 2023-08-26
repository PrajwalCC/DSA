// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

void setValueTOMap(Node* root, map<int,map<int,vector<int>>>& m, int level, int value){
    if(root == NULL){
        return;
    }
    m[value][level].push_back(root->data);
    setValueTOMap(root->left, m, level+1, value-1);
    setValueTOMap(root->right, m, level+1, value+1);
}

vector<int> verticalOrder(Node *root)
{
    //Your code here

    //*** Priority ***              ,here value means number line presentation and level means level of trees number
    // 1St      2nd                  <-- priority order of value and order for printing answer.
    // value   level       nodes     <-- map elements denotion 
    map<int,map<int,vector<int>>> m;
    setValueTOMap(root,m,0, 0);
    vector<int> ans;
    
    for(auto i:m){
        for(auto j: i.second){
            for(auto k: j.second){ 
                ans.push_back(k);
            }
        }
    }
    return ans;
}