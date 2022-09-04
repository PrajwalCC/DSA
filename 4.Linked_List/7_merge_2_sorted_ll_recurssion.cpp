#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
}

Node* merge(Node* &l1, Node* &l2){
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }

    if(l1->data < l2->data){
        l1->next = merge(l1->next,l2);
        return l1;
    }else{
        l2->next = merge(l1,l2->next);
        return l2;
    }
}

int main(){
    Node* l1 = new Node(10);
    l1->next = new Node(20);
    l1->next->next = new Node(30);
    print(l1);
    cout<<endl;

    Node* l2 = new Node(5);
    l2->next = new Node(15);
    l2->next->next = new Node(25);
    print(l2);
    cout<<endl;
    
    Node* ans = merge(l1,l2);
    print(ans);
    cout<<endl;

    
    return 0;
}