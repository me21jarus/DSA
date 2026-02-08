#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    int x=1;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<x++<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}

/*
Output for n=4
1 
2 3 
4 5 6 
7 8 9 10 
*/