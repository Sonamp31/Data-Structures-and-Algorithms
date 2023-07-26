#include <bits/stdc++.h>
using namespace std;

vector <char> compressString(vector<char> &chars){

    int i=0;
    int n=chars.size();
    int ansIndex=0;

    while(i<n){
        int j=i+1;
        while(j<n && chars[i]==chars[j]){
            j++;
        }

        chars[ansIndex++]=chars[i];

        int count=j-i;

        if(count>1){
            string cnt=to_string(count);
            for(char ch:cnt){
                chars[ansIndex++]=ch;
            }

        }
        i=j;
    }
    return chars;

    
    

}

int main(){
    vector<char> chars(1);
    chars={'a','a','b','b','b','c','c','c'};
   
    vector<char> ans=compressString(chars);
    
    for(auto i:ans){
        cout<<i<<",";
    }
    return 0;
}