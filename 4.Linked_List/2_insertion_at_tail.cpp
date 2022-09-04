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

void headInsertion(Node* &tail , int d){
      Node* newNode = new Node(d);
      tail->next = newNode;
      tail = newNode;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* tail = new Node(10);
    Node* head = tail;
    headInsertion(tail, 20);
    print(head);
    cout<<endl;
    headInsertion(tail, 30);
    print(head);
    cout<<endl;
    headInsertion(tail, 40);
    print(head);
    cout<<endl;



    

    return 0;
}