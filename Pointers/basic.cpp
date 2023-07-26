#include <iostream>
using namespace std;


//pass by value
void update1(int a){
    a=a+5;
}


//pass by reference
void update2(int& a){
    a=a+5;
}

int main(){
    int i = 5;
    cout<<"Before value: "<<i<<endl;
    update1(i);
    cout<<"After value: "<<i<<endl;
    cout<<endl<<endl;
    cout<<"Before value: "<<i<<endl;
    update2(i);
    cout<<"After value: "<<i<<endl;
    return 0;
}