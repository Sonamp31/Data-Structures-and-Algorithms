#include <iostream>
using namespace std;

int sumOfArray(int arr[],int size){
    if(size==0){
        return 0;
    }

    if(size==1){
        return arr[0];
    }

    int sum=arr[0]+sumOfArray(arr+1,size-1);
    return sum;
}
int main(){
    int arr[5]={2,4,8,1,6};

    int ans=sumOfArray(arr,5);
    cout<<"Sum of all elements = "<<ans;

    return 0;
}