#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        int x=i;
        while(j<=i){
            cout<<x--;
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
21
321
4321
*/