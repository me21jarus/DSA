#include<iostream>
using namespace std;

int fact(int n){
    int fact = 1;
    
    for(int i=1;i<=n;i++){
        fact = fact*i;
    }
    
    return fact;
}

int nCr(int n,int r){
    return fact(n) / (fact(r) * fact(n-r));
}

int main(){
    
    cout<<nCr(5,0)<<endl;
    cout<<nCr(5,1)<<endl;
    cout<<nCr(5,2)<<endl;
    cout<<nCr(5,3)<<endl;
    cout<<nCr(5,4)<<endl;
    cout<<nCr(5,5)<<endl;
    
    return 0;
}