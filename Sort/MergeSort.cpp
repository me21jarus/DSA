#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr,int s,int mid,int e){
    int n1 = mid - s + 1;
    int n2 = e - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for(int i=0;i<n1;i++)
        leftArr[i] = arr[s+i];

    for(int j=0;j<n2;j++)
        rightArr[j] = arr[mid+1+j];

    int i = 0, j = 0, k = s;

    while(i<n1 && j<n2){
        if(leftArr[i]<=rightArr[j]){
            arr[k++] = leftArr[i++];
        }
        else{
            arr[k++] = rightArr[j++];
        }
    }
    while(i<n1){
        arr[k++] = leftArr[i++];
    }
    while(j<n2){
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(vector<int>& arr,int s,int e){
    if(s>=e) return;

    int mid = s+(e-s)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    mergeSort(arr,0,n-1);

    cout << "Sorted array (Merge Sort): ";
    for (int num : arr)
        cout << num << " ";

    return 0;
}