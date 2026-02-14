#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}

void alternatereverse(int arr[],int n){
    for(int i=0;i<n-1;i+=2){
        swap(arr[i],arr[i+1]);
    }
}

int main(){

    int n;
    cin>> n;
    
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    alternatereverse(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<< " ";
    }
    
    return 0;
}