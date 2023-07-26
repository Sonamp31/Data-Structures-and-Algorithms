#include <iostream>
using namespace std;

//string can consist characters, numbers ,special characters ans whitespaces
//ignore white spaces and other symbols 
//not case sensitive  e.g. $anDdNa   is a palindrome

void lowerCase(string &s){
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch>='A' && ch<='Z'){
            ch=ch-'A'+'a';
            s[i]=ch;
        }
    }
}
bool palindromeCheck(string s){
    lowerCase(s);
    int st=0;
    int end=s.length()-1;
    while(st<end){
        if(isalnum(s[st])==0){
            ++st;
        }
        
        else if(isalnum(s[end])==0){
            --end;
        }
        else if(s[st]==s[end]){
            st++;
            end--;
        }
        else{
            return false;
        }
    }

    return true;

}

int main(){
    string s="N2i&nJA? jnI2n";
    if(!palindromeCheck(s)){
        cout<<"Given string is not a palindrome";
    }
    else{
        cout<<"Given string is a palindrome";
    }
    return 0;
}