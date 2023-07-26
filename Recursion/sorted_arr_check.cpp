//Check whether array is sorted or not

#include <iostream>
using namespace std;


bool isSorted(int *arr,int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        int ans=isSorted(arr+1,size-1);
        return ans;
    }
    
}
int main(){
    int arr[5]={1,2,3,4,5};

    bool ans=isSorted(arr,5);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is unsorted"<<endl;
    }
    return 0;
}