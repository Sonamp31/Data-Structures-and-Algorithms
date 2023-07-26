#include <iostream>
using namespace std;

/*
void stringReverse(string& s,int i,int j){

    //base case
    if(i>j){       
        return;
    }
    swap(s[i],s[j]);
    i++;
    j--;
  

    stringReverse(s,i,j);
    
}
*/

//optimised one
void stringReverse(string& s,int i){

    //base case
    if(i>s.length()-i-1){       //j is replaced by s.length()-i-1
        return;
    }
    swap(s[i],s[s.length()-i-1]);
    i++;
  

    stringReverse(s,i);
    
}
int main(){
    string s;
    cout<<"Enter String : "<<endl;
    cin>>s;
    int l=s.length()-1;

    stringReverse(s,0);
    cout<<s<<endl;
    return 0;
}