// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

void setValuesToMap(Node *root, map<int,vector<int>>& m, int horiVal){
    if(root == NULL){
        return;
    }
    
    m[horiVal].push_back(root->data);
    
    setValuesToMap(root->left, m, horiVal-1);
    setValuesToMap(root->right, m, horiVal);
    
}
vector<int> diagonal(Node *root)
{
   // your code here
   map<int,vector<int>> m;
   setValuesToMap(root, m, 0);
   
   auto it = m.begin();
   int smallestHoriVal = (*it).first;
   
   int hori = 0;
   vector<int> ans;
   while(smallestHoriVal <= hori){
       
       auto it = m.find(hori);
       if(it != m.end()){
           vector<int> temp = (*it).second;
           
           for(int i=0; i<temp.size(); i++){
               ans.push_back(temp[i]);
           }
       }
       
       hori = hori-1;
   }
   return ans;
}