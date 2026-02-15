#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=0;i<n;i++){
            bool swapped = false;
            for(int j=i+1;j<n;j++){
                if(arr[i] > arr[j]){
                    swap(arr[i],arr[j]);
                    swapped = true;
                }
            }
            if(swapped == false){
                break;
            }
        }
    }
};