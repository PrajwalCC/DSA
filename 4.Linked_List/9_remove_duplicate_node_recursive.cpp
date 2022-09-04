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
void remove(Node* &head){
    Node* temp = head;
    if(head == NULL || head->next == NULL){
        return;
    }
    if(temp->data == temp->next->data){
      temp->next = temp->next->next;
      remove(temp->next);
    }else{
        temp = temp->next;
        remove(temp);
    }
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(40);
    head->next->next->next->next->next = new Node(40);
    print(head);
    cout<<endl;

    remove(head);
    print(head);
    
    return 0;
}