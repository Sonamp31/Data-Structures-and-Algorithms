#include <iostream>
using namespace std;


void printSeq(int n){

    if(n==0){
        return ;
    }
    cout<<n<<" ";
    printSeq(n-1);
}
int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
     
    printSeq(n); 

    return 0;
}