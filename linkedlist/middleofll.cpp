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

int countNumberOfNodes(Node* &head){
        Node* temp=head;
        int cnt=0;
        while(temp!=0){
            temp=temp->next;
            cnt++;
        }
        return cnt;
}

//iterative approach
Node* middleElement(Node* head){
       int len=countNumberOfNodes(head);
       int mid=(len/2);
    
       Node* ans=head;
       while(mid--){
           ans=ans->next;
       }
       return ans;
}

//two pointer approach
Node *findMiddle(Node *head) {
    
    if(head->next==NULL || head==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }

    Node* pointer1=head;
    Node* pointer2=head->next;

    while(pointer2!=NULL){
        if(pointer2->next==NULL){
            pointer2=pointer2->next;
        }
        else{
            pointer2=pointer2->next->next;
        }
        pointer1=pointer1->next;
    }

    return pointer1;
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
    cout<<endl;

    Node* mid1=findMiddle(head);
    cout<<mid1->data<<endl;

    cout<<endl;

    Node* mid2=middleElement(head);
    cout<<mid2->data<<endl;

    return 0;
}