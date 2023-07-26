#include <iostream>
using namespace std;

bool binarySearch(int arr[],int start,int end,int key){

    int mid=start+(end-start)/2;
    if(start>end){
        return false;
    }
    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
        binarySearch(arr,start,mid-1,key);
    }
    else{
        binarySearch(arr,mid+1,end,key);
    }

}
int main(){
    int arr[5]={2,5,8,12,34};

    int key;
    cout<<"Enter key which needs to be searched : ";
    cin>>key;

    int ans=binarySearch(arr,0,5,key);
    if(ans){
        cout<<key<<" is present in the array"<<endl;
    }
    else{
        cout<<key<<" is not present in the array"<<endl;
    }
}