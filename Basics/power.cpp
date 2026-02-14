#include<iostream>
using namespace std;

int power(int a,int b){

    int ans = 1;

    for(int i=1;i<=b;i++){
        ans = ans*a;
    }
    return ans;
}

int main(){
    
    cout<<power(5,3)<<endl;
    cout<<power(4,6)<<endl;
    
    return 0;
}