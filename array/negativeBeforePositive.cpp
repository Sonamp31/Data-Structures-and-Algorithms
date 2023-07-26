#include <iostream>
#include <vector>
using namespace std;


void integerSequence(int arr[],int n){
    
    int lf=0;
    int curr=0;
    while(curr<n){
        if(arr[curr]<0){
            int temp=arr[lf];
            int pt=curr;
            arr[lf]=arr[curr];
            while(pt>(lf+1)){
                arr[pt]=arr[pt-1];
                pt--;
            }
            arr[pt]=temp;
            lf++;
            curr++;
        }
        else{
            curr++;
        }
    }
   
    
}
int main(){
    int arr[]={3,-2,6,-7,-1,1,5,2}; //-2 -7 -1 3 6 1 5 2
    int size=8;
    integerSequence(arr,size);
    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}