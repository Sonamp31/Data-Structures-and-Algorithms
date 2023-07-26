#include <iostream>
using namespace std;

class kqueue{   
    private:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int *next;
        int freespot;

    public:
        kqueue(int n,int k){
            this->n = n;
            this->k = k;

            front = new int[k];
            rear = new int[k];
            next = new int[n];
            arr = new int[n];
            for(int i=0;i<n;i++){
                front[i]=-1;
                rear[i]=-1;
            }           
            
            for(int i=0;i<n;i++){
                next[i]=i+1;
            }
            next[n-1]=-1;
          
            freespot = 0;
        }

        void enqueue(int data,int qn){
            if(freespot==-1){
                cout<<"Array is full";
                return;
            }

            //find first free spot
            int index = freespot;

            //update freespot
            freespot = next[index];

            //check whether its first element of queue
            if(front[qn-1]==-1){
                front[qn-1]=index;
            }
            else{
                //link new element to prev element
                next[rear[qn-1]]=index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn-1] = index;

            //push data
            arr[index]=data;

        }

        int dequeue(int qn){
            //underflow condition
            if(front[qn-1]==-1){
                cout<<"Queue is empty";
                return -1;
            }

            //get index to pop
            int index = front[qn-1];

            //update front to next element
            front[qn-1] = next[index];

            //manage freespot
            next[index]=freespot;
            freespot=index;

            return arr[index];
        }
};

int main(){
     
    kqueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;
    

    return 0;

}