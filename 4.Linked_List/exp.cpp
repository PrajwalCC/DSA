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

Node* reverseInKgroups(Node* &head, int k){
    
    int count = 0;
    Node* forward;
    Node* prev= NULL;
    Node* curr= head;
    Node* temp= head;
    while(count < k){
        if(temp == NULL){
            return head;
        }
        temp = temp->next;
        count++;
    }
    count = 0;
    while(curr != NULL && count < k){
        forward = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head->next = reverseInKgroups(forward,k);
    }
    return prev;
}

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    print(head);
    cout<<endl;
    int k = 3 ;
    head = reverseInKgroups(head,k);
    print(head);
    cout<<endl;


    return 0;
}