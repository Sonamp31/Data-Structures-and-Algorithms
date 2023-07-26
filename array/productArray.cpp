#include <iostream>
#include <vector>
using namespace std;


vector<int> productArray(int arr[],int n){
    vector<int>ans;
    int prd;
    for(int i=0;i<n;i++){
        prd=1;
        for(int j=0;j<n;j++){
            if(i!=j){
               prd=prd*arr[j]; 
            }         
        }
        ans.push_back(prd);     
    }

    return ans;

    
}
int main(){
    int arr[]={3,2,6,7,1,1,5,2};
    int size=8;
    vector<int>ans=productArray(arr,size);
    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}