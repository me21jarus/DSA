#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& stalls,int n, int k,int mid){
        int cowCnt = 1;
        int lastPos = stalls[0];
        
        for(int i=0;i<n;i++){
            if(stalls[i] - lastPos >= mid){
                cowCnt++;
                if(cowCnt == k){
                    return true;
                }
                lastPos = stalls[i];
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        if(k>n) return -1;
        int s = 0;
        int maxi = -1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,stalls[i]);
        }
        int e = maxi;
        int ans = -1;
        int mid = s+(e-s)/2;
        
        while(s<=e){
            if(isPossible(stalls,n,k,mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};