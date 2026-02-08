#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    int x=0;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            char ch='A'+x++;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}

/*
Output for n=4:
A 
B C 
D E F 
G H I J 
*/