#include <iostream>
using namespace std;


int powerOfTwo(int n){

    if(n==0){
        return 1;
    }

    return 2 * powerOfTwo(n-1);
}
int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;

    int ans=powerOfTwo(n);

    cout<<"Answer : "<<ans<<endl;

    return 0;
}