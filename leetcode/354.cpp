class Solution {
public:
    int solve(vector<int>& arr){
        int n = arr.size();

        vector<int> ans;
        ans.push_back(arr[0]);

        for(int i=1;i<n;i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a, vector<int>& b){
            if(a[0] != b[0]){
                return a[0]<b[0];
            }
            return a[1] > b[1];
        });

        vector<int> heights;
        for(auto &it : envelopes){
            heights.push_back(it[1]);
        }
        return solve(heights);
    }
};