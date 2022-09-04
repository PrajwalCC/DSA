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

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = head->next->next;
    // print(head);
    // cout<<endl;
    Node *slow=head;
    Node *fast=head;
    while(slow!=NULL || fast!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout<<"Yes cycle is present"<<endl;
            cout<<"meeting Node ="<<slow->data;
            break;
        }
    }
    if(slow==NULL || fast==NULL){
        cout<<"No, cycle is not present"<<endl;
    }

    
    return 0;
}