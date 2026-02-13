#include<iostream>
#include<algorithm>
using namespace std;

void Sort01(int arr[], int n){
    int l = 0, r = n-1;
    while(l<r){
        while(arr[l]==0 && l<r){
            l++;
        }
        while(arr[r]==1 && l<r){
            r--;
        }
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){

    int arr[9] = {1,1,1,0,0,0,0,1,0};

    Sort01(arr,9);
    printArray(arr,9);

    return 0;
}