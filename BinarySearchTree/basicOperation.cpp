#include <iostream>
using namespace std;


class Node{
    public:

       int data;
       Node* left;
       Node* right;

       Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
       }
};




Node* InsertIntoBST(Node* &root, int d){
     
    if(root==NULL){
        root=new Node(d);
        return root;
    }

    if(d < root->data){
        root->left=InsertIntoBST(root->left,d);
    }
    else if(d > root->data){
        root->right=InsertIntoBST(root->right,d);
    }

    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        InsertIntoBST(root,data);
        cin>>data;
    }
}

void inOrder(Node* root){

    if(root==NULL){
        return;
    }
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preOrder(root->left);  
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }   
    
    postOrder(root->left);  
    postOrder(root->right);
    cout<<root->data<<" ";
}

bool searchInBST(Node* root, int x) {

    /* Recursive Aproach

    if(root==NULL){
         return false;
    }     
    if(root->data==x){
         return true;
    }
    else if(x < root->data){
         searchInBST(root->left,x);
    }
    else{
         searchInBST(root->right,x);
    }

    */

    //Iterative Approach --> saves space used by recursive stack during recursion
   
    Node* temp=root;

    while(temp!=NULL){
        if(temp->data==x){
            return true;
          
        }
        else if(x < temp->data){
           temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
    

}

int minValue(Node *root){
    Node* temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }

    return temp->data;
}

int maxValue(Node *root){
    Node* temp=root;

    while(temp->right!=NULL){
        temp=temp->right;
    }

    return temp->data;
}

int inOrderPredecessor(Node* root,int target){
     
    int pred=-1;
    Node* temp=root;
    while(temp!=NULL){
        if(temp->data < target){
            pred=temp->data;
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
        
    }
    return pred;
      
}


int inOrderSuccessor(Node* root,int target){
     
    int succ=-1;
    Node* temp=root;
    while(temp!=NULL){
        if(temp->data > target){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
        
    }
    return succ;
      
}

Node* deleteNode(Node* root,int key){
     
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        // 2 cases possible

        if(root->left!=NULL && root->right==NULL){
            Node* temp=root;
            root=temp->left;
            delete temp;
            return root;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* temp=root;
            root=temp->right;
            delete temp;
            return root;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            //2 option possible
            //left se maximum value nikal lo aur right se minimum value nikal lo

            int mini=minValue(root->right);
            root->data=mini;
            root->right=deleteNode(root->right,mini);
            return root;

        }
    }
    else if(root->data > key){
        root->left=deleteNode(root->left,key);
        return root;
    }
    else{
        root->right=deleteNode(root->right,key);
        return root;
    }
}



int main(){
  

    //10 5 21 3 4 7 28 -1
    Node* root=NULL;
    cout<<"Enter the data: ";
    takeInput(root);
    cout<<"InOrder: ";
    inOrder(root);
    cout<<endl;

    cout<<"PreOrder: ";
    preOrder(root);
    cout<<endl;
     
    cout<<"PostOrder: ";
    postOrder(root);
    cout<<endl;
     
    int x;
    cout<<"Enter number need to be searched: ";
    cin>>x;
    bool flag=searchInBST(root, x);
    if(flag==true){
        cout<<x<<" is Present"<<endl;
    }
    else{
        cout<<x<<" is absent"<<endl;
    }

    int minval = minValue(root);
    cout<<"Minimum value: "<< minval <<endl;

    int maxval=maxValue(root);
    cout<<"Minimum value: "<<maxval<<endl;


    int y;
    cout<<"Enter number whose inorder predecessor and successor need to find: ";
    cin>>y;
    cout<<endl;
    int pred=inOrderPredecessor(root,y);
    int succ=inOrderSuccessor(root,y);
    cout<<"\nInorder Predecessor of "<<y<<" = "<<pred;
    cout<<"\nInorder Successor of "<<y<<" = "<<succ;

    Node* n=deleteNode(root,50);
    cout<<"InOrder: ";
    inOrder(n);
    cout<<endl;
    return 0;

}