#include<iostream>
#include <climits>
using namespace std;

void maxiandmini(int arr[],int n){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
        if(arr[i]<mini){
            mini = arr[i];
        }
    }
    cout<<maxi<< " "<<mini<<endl;
}

int main(){
    
    int n;
    cin>> n;
    
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    maxiandmini(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;;
    }
    
    return 0;
}