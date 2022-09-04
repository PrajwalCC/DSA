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

void insertion(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    insertion(head,20);
    print(head);
    cout<<endl;
    insertion(head,30);
    print(head);
    
    return 0;
}