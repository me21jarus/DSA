#include<iostream>
using namespace std;

int setBits(int a,int b){
    int count = 0;
    
    while(a){
        if(a&1 == 1){
            count++;
        }
        a=a>>1;
    }
    while(b){
        if(b&1 == 1){
            count++;
        }
        b=b>>1;
    }
    
    return count;
}

int main(){
    
    cout<<setBits(2,3);
    
    return 0;
}