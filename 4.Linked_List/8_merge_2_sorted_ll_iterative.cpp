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
    Node* l1 = new Node(10);
    l1->next = new Node(20);
    l1->next->next = new Node(30);
    l1->next->next->next = new Node(40);
    // print(l1);
    // cout<<endl;

    Node* l2 = new Node(5);
    l2->next = new Node(15);
    l2->next->next = new Node(25);
    // print(l2);
    // cout<<endl;
    
    Node* head;
    if(l1->data < l2->data){
        head = l1;
        l1 = l1->next;
    }else{
        head= l2;
        l2 = l2->next;
    }
    Node* temp = head;

    while(l1 != NULL || l2 != NULL){
        if(l1->data < l2->data){
            temp->next = l1;
            l1 = l1->next;
            temp = temp ->next;
        }else{
            temp-> next = l2;
            l2 = l2->next;
            temp = temp ->next;
        }

        if(l2 == NULL){
            temp->next = l1;
            break;
        }
        if(l1 == NULL){
            temp->next = l2;
            break;
        }

    }
    
    print(head);
    
    return 0;
}