#include <iostream>
using namespace std;

bool linearSearch(int arr[],int size,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        return linearSearch(arr+1,size-1,key);
    }
   
}
int main(){
    int arr[5]={38,23,5,2,9};
    int key;
    cin>>key;
    int ans=linearSearch(arr,5,key);
    if(ans){
        cout<<key<<" is Present in the array"<<endl;
    }
    else{
        cout<<key<<" is not present in the array"<<endl;
    }
    return 0;
}