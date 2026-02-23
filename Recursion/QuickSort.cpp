#include<iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr,int s,int e){
    int pivot = arr[e];
    int i = s-1;

    for(int j = s ; j<e ; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void quickSort(vector<int>& arr,int s,int e){
    if(s>=e) return;

    int pivot = partition(arr,s,e);
    quickSort(arr,s,pivot-1);
    quickSort(arr,pivot+1,e);
}

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    quickSort(arr,0,n-1);

    cout << "Sorted array (Quick Sort): ";
    for (int num : arr)
        cout << num << " ";

}