// Different approach from inorder and preorder iterative 
#include <bits/stdc++.h>
using namespace std;
class node {
    public:
       int data;
       node* left;
       node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    } 
};
node* buildTree(node* root){
    cout<<"Enter the data:"<<endl;
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    root = new node(d);
    
    cout<<"Data of left to "<<d<<endl;
    root->left = buildTree(root->left);

    cout<<"Data of right to "<<d<<endl;
    root->right = buildTree(root->right);

    return root;
}
void postorderUsingStack(node* root){
    stack<node*>s;
    stack<node*>ans;
    s.push(root);
    while(!s.empty()){
        node* curr = s.top();
        s.pop();
        ans.push(curr);

        if(curr->left != NULL){
            s.push(curr->left);
        }
        if(curr->right != NULL){
            s.push(curr->right);
        }
    }

    while(!ans.empty()){
        cout<<ans.top()->data<<" ";
        ans.pop();
    }
}
int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root;
    root = buildTree(root);
    postorderUsingStack(root);
    return 0;
}