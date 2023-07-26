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
int countNumberOfNodes(Node* &head){
        Node* temp=head;
        int cnt=0;
        while(temp!=0){
            temp=temp->next;
            cnt++;
        }
        return cnt;
}
void insertAtHead(Node* &head,int d){
        Node* newnode=new Node(d);
        newnode->next=head;
        head=newnode;
}
void insertAtTail(Node* &head,int d){
        Node* newnode=new Node(d);
       
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=newnode;
        tail=newnode;


}
void insertAtPosition(Node* &head,int d, int position){
               
        if(position == 1){
            insertAtHead(head,d);
            return;
        }
        int total_ele=countNumberOfNodes(head);
        if(position > total_ele+1 ){
            cout<<"\nPosition is out of range of linked list";
            return;
        }
        Node* newnode=new Node(d);
        Node* prev=head;      
        
        int i=1;
        while(i!= position-1){
           i++;
           prev=prev->next;
          
        }
        Node* nextnode=prev->next;
        prev->next=newnode;
        newnode->next=nextnode;
             

}
void deleteFromHead(Node* &head){
   Node* temp=head;
   head=head->next;
   delete temp;
}
void deleteFromTail(Node* &head){
   Node* temp=head;

   while(temp->next->next!=NULL){
       temp=temp->next;
   }
   Node* temp2=temp->next;
   delete temp2;
   temp->next=NULL;
   
  
}
void print(Node* &head){
        cout<<endl;
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
}
void deleteFromPosition(Node* &head,int position){
        cout<<endl;
        if(position==1){
            deleteFromHead(head);
            return;
        }
        int total_ele=countNumberOfNodes(head);
        if(position > total_ele+1 ){
            cout<<"\nPosition is out of range of linked list";
            return;
        }
        Node* temp=head;
        
        int i=1;
        while(i < position-1){
            temp=temp->next;
            i++;
        }
        Node* temp1=temp->next;

        temp->next=temp->next->next;
        delete temp1;
}


int main(){
    
    Node* node1 = new Node(10);
    Node* head = node1;

    insertAtHead(head,43);
    insertAtHead(head,92);
    
    insertAtTail(head,100);
    insertAtTail(head,200);



    print(head);

   

    // deleteFromHead(head);
    // print(head);
    // deleteFromTail(head);
    // deleteFromTail(head);
    // print(head);

    deleteFromPosition(head,3);
    print(head);

    

    return 0;
    
}