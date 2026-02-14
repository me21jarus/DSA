#include<iostream>
using namespace std;

void fib(int n){
    
    int a = 0;
    int b = 1;
    
    for(int i=0;i<n-2;i++){
        int c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}

int main(){
    
    cout<< 0 <<" " << 1 << " ";
    fib(10);
    
    return 0;
}