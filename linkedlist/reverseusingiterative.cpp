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

void reverselinkedlist(Node* head){
    
   
    if(head->next == NULL || head==NULL){
        cout<<head->data;
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* nextnode = NULL;

    while(curr!=NULL){
        nextnode=curr->next;
        curr->next = prev;
        prev=curr;
        curr=nextnode;

    }
    
   print(prev);

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

    reverselinkedlist(head);

    // print(head);
    


    return 0;   

}

