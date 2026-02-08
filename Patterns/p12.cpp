#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    char ch='A';
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<ch++<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}

/*
OUTPUT for n=4:
A B C D 
E F G H 
I J K L 
M N O P 
*/