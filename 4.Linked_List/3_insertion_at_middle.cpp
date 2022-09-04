#include <bits/stdc++.h>
using namespace std;
class Node{
        public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this -> next = NULL;
        }

};

void insertionMiddle(Node* &head, int position, int d){
    // we have to handle this case this special...
    if(position == 1){
        Node* temp = head;
        Node* newNode = new Node(d);
        newNode -> next = temp;
        head = newNode;
        return;
    }
    
    Node* temp = head;
    int c = position - 2;
    while(c--){
        temp = temp -> next;
    }
    Node* newNode = new Node(d);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}  

void print(Node* &head){
         Node* temp = head;
        while(temp != NULL){
         cout<<temp->data<<" ";
         temp = temp->next;
        } 
}

int main(){
    
    Node* head = new Node(10);
    head -> next = new Node(20);

    print(head);
    cout<<endl;

    insertionMiddle(head, 3, 30);
    print(head);
    cout<<endl;
    insertionMiddle(head, 3, 250);
    print(head);
    cout<<endl;
    insertionMiddle(head, 2, 50);
    print(head);
    cout<<endl;
    insertionMiddle(head, 1, 100);
    print(head);
    cout<<endl;

    


     
    return 0;
}