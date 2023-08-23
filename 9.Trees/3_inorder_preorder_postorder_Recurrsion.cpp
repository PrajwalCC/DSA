#include <bits/stdc++.h>
using namespace std;
class node{
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
node* buildTree(node * root){
    cout<<"Enter data :"<<endl;
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }

    root = new node(d);

    cout<<"add data to left child of "<<d<<endl;
    root->left = buildTree(root->left);

    cout<<"add data to right child of "<<d<<endl;
    root->right = buildTree(root->right);

    return root;
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root == NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    // input 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root;
    root = buildTree(root);
    cout<<"Inorder traversal:";
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal:";
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal:";
    postorder(root);
    return 0;
}