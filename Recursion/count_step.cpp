//Count number of distinct ways to climb 'n' given stairs in distinct ways

#include <iostream>
using namespace std;

int countDistinctWays(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;     //for 0th stair ,it will jump on itself
    }
    int ans=countDistinctWays(n-1)+countDistinctWays(n-2);

    return ans;
}

int main(){
    int n;
    cout<<"Enter total number of steps: ";
    cin>>n;

    int ans=countDistinctWays(n);

    cout<<"Answer : "<<ans<<endl;

    return 0;
}