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

void reverse(Node* &head,Node* &curr, Node* &prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr -> next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    reverse(head,curr,prev);
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    print(head);
    cout<<endl;
    Node* curr = head;
    Node* prev= NULL;
    reverse(head,curr,prev);
    print(head);
    cout<<endl;

    return 0;
}