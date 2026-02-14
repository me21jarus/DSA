#include<iostream>
using namespace std;

bool isEven(int n){
    if(n%2 == 0) return true;
    return false;
}

int main(){
    
    cout<<isEven(5)<<endl;
    cout<<isEven(4)<<endl;
    
    return 0;
}