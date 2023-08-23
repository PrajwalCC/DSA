// input -> 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
// output -> 1
//.          3 5
//.          7 11 17
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
void buildTreeFromLevelOrder(node* &root){
    queue<node*>q;
    cout<<"Enter data to root:"<<endl;
    int d;
    cin>>d;
    root = new node(d);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter data to left child of "<<temp->data<<endl;
        int l;
        cin>>l;
        if(l != -1){
            temp->left = new node(l);
            q.push(temp->left);
        }

        cout<<"Enter data to right child of "<<temp->data<<endl;
        int r;
        cin>>r;
        if(r != -1){
            temp->right = new node(r);
            q.push(temp->right);
        }
    }
}

void printLevelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
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
    node* root;
    buildTreeFromLevelOrder(root);
    printLevelOrderTraversal(root);
    return 0;
}