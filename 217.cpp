#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto i:map){
            if(i.second > 1){
                return true;
            }
        }
        return false;
    }
};