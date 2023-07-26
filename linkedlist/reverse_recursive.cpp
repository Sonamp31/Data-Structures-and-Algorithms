//Reversing a linked list using iterative approach

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int data){
        this -> data = data;
        this -> next = NULL;
    }
    

};
void insertAtTail(Node* &head,int d){
        Node* newnode=new Node(d);
       
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=newnode;
        tail=newnode;


}
void print(Node* &head){
        cout<<endl;
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
}

void reverse(Node* &head,Node* curr,Node* prev){
    
    if(curr==NULL){
        head = prev;
        return;
    }

    reverse(head,curr->next,curr);
    curr->next=prev;
}

void reverselinkedlist(Node* head){
     
    Node* curr=head;
    Node* prev=NULL;
    reverse(head,curr,prev);
    print(head);
}

//Second approach
Node* reverse1(Node* head){
     
     if(head==NULL || head->next==NULL){
        return head;
     }

     Node* chotahead=reverse1(head->next);
     head->next->next=head;
     head->next=NULL;

     return chotahead;
   
}

int main(){
    Node* newnode=new Node(10);
    Node* head=newnode;
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);
    insertAtTail(head,60);

    print(head);

    // reverselinkedlist(head);

    Node* head1=reverse1(head);
    print(head1);
   
   return 0;
}