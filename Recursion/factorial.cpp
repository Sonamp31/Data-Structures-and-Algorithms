#include <iostream>
using namespace std;

int factorial(int n){

    //Base condition
    if(n==0){
        return 1;
    }

    return n*factorial(n-1);   //recursive relation
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int ans=factorial(n);
    cout<<"Factorial of "<<n<<" is "<<ans<<endl;
    return 0;
}