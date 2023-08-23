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
stack<node*> reverse_levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    stack<node*> s;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        s.push(temp);
        if(temp == NULL){
           if(!q.empty()){
             q.push(NULL);
           }
        }
        else{
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }
    return s;
}
int main(){
    //1 2 3 -1 -1 -1 4 -1 5 -1 -1
    node* root;
    root = buildTree(root);
    stack<node*> s = reverse_levelOrderTraversal(root);
    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        if(temp){
            cout<<temp->data<<" ";
        }
        else{
            cout<<endl;
        }
    }
    return 0;
}