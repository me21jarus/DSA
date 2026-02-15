#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int arr[6] = {7,9,1,2,3,6};
    
    int s = 0, e = 5;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid] > arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    cout<<e <<endl;

    return 0;
}