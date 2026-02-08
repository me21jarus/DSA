#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int key){
    int l=0;
    int r=n-1;

    int mid = l +(r-l)/2;
    while(l<=r){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            r= mid-1;
        }
        else{
            l=mid+1;
        }
        mid = l+(r-l)/2;
    }
    return -1;
}

int main(){

    int n;
    cin>> n;
    
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    int ans = BinarySearch(arr,n,key);

    cout<<ans;
    
    return 0;
}