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
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(40);
    print(head);
    cout<<endl;

    Node* temp=head;
    while(temp != NULL){
        if(temp->next != NULL && (temp->next->data == temp->data)){
            temp->next = temp->next->next;
            continue;       
        }
        temp = temp->next;
    }
    print(head);
    
    return 0;
}