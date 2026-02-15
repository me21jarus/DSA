#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr,int n, int k,int mid){
        int pCnt = 1;
        int units = 0;
        
        for(int i=0;i<n;i++){
            if(units + arr[i] <= mid){
                units += arr[i];
            }
            else{
                pCnt++;
                if(pCnt > k || arr[i] > mid){
                    return false;
                }
                units = arr[i];
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if(k>n) return -1;
        int s = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int e = sum;
        int ans = -1;
        int mid = s+(e-s)/2;
        
        while(s<=e){
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};