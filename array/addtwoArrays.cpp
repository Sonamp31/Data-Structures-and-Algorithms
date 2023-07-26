#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> addTwoArrays(int arr1[],int arr2[],int n,int m){
    int i=n-1;
    int j=m-1;

    vector<int>ans;
    int carry=0;
    int val=0;

    while(i>=0 && j>=0){
        int sum=arr1[i]+arr2[j]+carry;
        carry=sum/10;
        val=sum%10;

        ans.push_back(val);
        i--;
        j--;

    }
    while(i>=0){
        int sum=arr1[i]+carry;
        carry=sum/10;
        val=sum%10;

        ans.push_back(val);
        i--;
    }

    while(j>=0){
        int sum=arr2[j]+carry;
        carry=sum/10;
        val=sum%10;

        ans.push_back(val);
        j--;
    }

    if(carry!=0){
        ans.push_back(carry);
    }

    reverse(ans.begin(),ans.end());

    return ans;
}
int main(){
    int arr1[5]={1,2,3,4,8};
    int arr2[4]={6,8,9,6};

    vector<int>ans=addTwoArrays(arr1,arr2,5,4);
    for(auto i:ans){
        cout<<i;
    }

    return 0;
}