#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
       int data;
       Node* left;
       Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){

    int data;
    cout<<"Enter data: ";
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data to insert at left of "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter data to insert at right "<<data<<endl;
    root->right=buildTree(root->right);
    return root;

}

void levelOrderTraversal(Node* root){
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        
        Node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }   
    
}

void depthFirstSearch(Node* root){
    stack<Node* > st;
    st.push(root);

    while(!st.empty()){
        Node* temp=st.top();
        cout<<temp->data<<" ";
        st.pop();
        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }

    }

}

//traversal using recursion
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";   
    inorder(root->right);

}
void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";   
    preorder(root->left);
    preorder(root->right);

}
void postorder(Node* root){
    if(root==NULL){
        return ;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";   

}

//traversal using iterations
void inorderTraverse(Node* root){
    if(root==NULL){
        return;
    }
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
}
int main(){
    Node* root=NULL;
    root = buildTree(root);
    //9 3 6 -1 -1 2 -1 -1 5 4 -1 -1 7 -1 -1
    cout<<"Printing data level wise"<<endl;
    levelOrderTraversal(root);
    cout<<"\nPrinting data depth wise"<<endl;
    depthFirstSearch(root);
    cout<<"\nPrinting inorder"<<endl;
    inorder(root);
    cout<<"\nPrinting preorder"<<endl;
    preorder(root);
    cout<<"\nPrinting postorder"<<endl;
    postorder(root);


    return 0;
}
