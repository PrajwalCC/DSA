#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    // contructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int value = this -> data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }

};

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head -> next;
//   ***Very Impt ... deleting node ka next hamesha null krke hi delete krna..
        temp -> next = NULL;
        delete temp;
    }
    else{
        int c = position - 2;
        Node* temp = head;
        while(c--){
            temp = temp -> next;
        }

        Node* deletingNode = temp->next;
        temp->next = temp->next->next;
        // ***Very Impt ... deleting node ka next hamesha null krke hi delete krna..
        deletingNode -> next = NULL;
        delete deletingNode; 
    }
}

void print(Node* &head){
        Node* temp = head;
        while(temp != NULL){
         cout<<temp->data<<" ";
         temp = temp->next;
        } 
}

int main(){
    Node * head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    print(head);
    cout<<endl;

    deleteNode(2, head);
    
    print(head);
    cout<<endl;
    
    return 0;
}