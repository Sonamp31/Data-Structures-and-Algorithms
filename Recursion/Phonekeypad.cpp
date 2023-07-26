/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

// mapping done using exclude and include 


#include <iostream>
#include <vector>
using namespace std;

void solve(string digits,string output,int index, vector<string>& ans,string mapping[]){
            
       //base case
       if(index >= digits.length()){
           ans.push_back(output);
           return ;
       }

       int number = digits[index]-'0';
       string value = mapping[number];

       for(int i = 0 ; i < value.length() ; i++){
           output.push_back(value[i]);
           solve(digits,output,index+1,ans,mapping);
           output.pop_back();
       }
    }
vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
}

int main(){
    string digits;

    cout<<"Enter digits : ";
    cin>>digits;
    vector<string> seq;


    seq=letterCombinations(digits);
    for(int i=0;i<seq.size();i++){
        cout<<seq[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}