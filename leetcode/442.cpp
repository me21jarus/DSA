#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto& it : map){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};