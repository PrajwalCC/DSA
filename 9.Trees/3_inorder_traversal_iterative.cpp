// https://www.youtube.com/watch?v=lxTGsVXjwvM
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
void inorderUsingStack(node* root){
    stack<node*> s;
    node* curr = root;
    while(true){
        if(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            if(s.empty()==true){
                break;
            }
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}
int main(){
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root;
    root = buildTree(root);
    inorderUsingStack(root);
    return 0;
}