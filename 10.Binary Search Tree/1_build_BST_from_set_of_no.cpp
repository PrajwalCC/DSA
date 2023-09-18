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

node* insertNodeInTree(node* root,int k){

    if(root == NULL){
       root = new node(k);
       return root;
    }
    
    if(k > root->data){
        root->right = insertNodeInTree(root->right, k);
    }
    else{
       root->left = insertNodeInTree(root->left, k);
    }

    return root;
}

void buildTree(node*& root, vector<int> v, int n, int i){
     if(i == n){
        return;
     }
    root = insertNodeInTree(root, v[i]);

    buildTree(root,v,n, i+1);

}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        if(curr != NULL){
           cout<<curr->data<<" ";

           if(curr->left){
              q.push(curr->left);
           }
           if(curr->right){
              q.push(curr->right);
           }

        }
        else{
            cout<<endl;
           if(!q.empty()){
             q.push(NULL);
           }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>> a[i];
    }

    node* root = NULL;

    buildTree(root,a,n,0);
    
    cout<<"Printing inorder traversal:";
    inorder(root);//should be sorted
    cout<<endl;

    cout<<"Printing level order traversal:"<<endl;
    levelOrder(root);

    return 0;
}