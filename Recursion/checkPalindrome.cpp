#include <iostream>
using namespace std;


bool checkPalindrome(string s,int i,int j){
   
    if(i>j){
        return false;
    }
    if(s[i]!=s[j]){
        return false;
    }
    else{
        i++;
        j--;
    }

    checkPalindrome(s,i,j);
}
int main(){
    string s;
    cout<<"Enter String : "<<endl;
    cin>>s;
   
    bool ans=checkPalindrome(s,0,s.length()-1);
    if(ans){
        cout<<"Given String is Palindrome"<<endl;
    }
    else{
        cout<<"Given String is not a Palindrome"<<endl;
    }
    
    return 0;
}