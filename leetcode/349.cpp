#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();
        set<int> s;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i] == nums2[j]){
                s.insert(nums1[i]);
                i++;j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }

        for(auto x : s){
            ans.push_back(x);
        }

        return ans;
    }
};