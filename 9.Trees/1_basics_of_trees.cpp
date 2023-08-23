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
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
           cout<<endl;
           if(!q.empty()){
             q.push(NULL);
           }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
int main(){
    //1 2 3 -1 -1 -1 4 -1 5 -1 -1
    node* root;
    root = buildTree(root);
    levelOrderTraversal(root);
    return 0;
}