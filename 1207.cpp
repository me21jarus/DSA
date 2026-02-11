#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        //O(n)
        // unordered_map<int,int> freq;

        // for(int i=0;i<n;i++){
        //     freq[arr[i]]++;
        // }
        // unordered_set<int> ans;
        // for(auto &x : freq){
        //     ans.insert(x.second);
        // }
        // return freq.size()==ans.size();

        //O(logn)
        sort(arr.begin(),arr.end());
        vector<int> v;
        for(int i=0;i<n;i++){
            int count = 0;
            while(i+1<n && arr[i] == arr[i+1]){
                count++;
                i++;
            }
            v.push_back(count);
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(v[i] == v[i-1]){
                return false;
            }
        }
        return true;
    }
};