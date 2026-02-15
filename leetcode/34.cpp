#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstOccurence(vector<int>& nums,int n,int key){
        int s = 0,e = n-1;
        int ans=-1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==key){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] < key){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
    int lastOccurence(vector<int>& nums,int n,int key){
        int s = 0,e = n-1;
        int ans=-1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==key){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] < key){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        
        ans.push_back(firstOccurence(nums,n,target));
        ans.push_back(lastOccurence(nums,n,target));

        return ans;
    }
};