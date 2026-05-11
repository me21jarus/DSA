class Solution {
public:
    int solve(vector<int>& nums,int target){
        if(target == 0) return 1;
        if(target< 0) return 0;

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += solve(nums,target-nums[i]);
        }
        return ans;
    }
    int solvedp(vector<int>& nums,int target,vector<int>& dp){
        if(target == 0) return 1;
        if(target< 0) return 0;

        if(dp[target] != -1) return dp[target];

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += solvedp(nums,target-nums[i],dp);
        }
        dp[target] = ans;
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        // USING RECURSON
        // int ans = solve(nums,target);
        // return ans;

        // USING DP = RECURSION + MEM  
        // vector<int> dp(target+1,-1);
        // int ans = solvedp(nums,target,dp);
        // return ans;

        // USING DP = TABULAR
        vector<long long> dp(target+1, 0);
        dp[0] =1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j] >= 0)
                    dp[i] += dp[i-nums[j]];
                
                if(dp[i] > INT_MAX) dp[i] = INT_MAX;
            }
        }
        return (int)dp[target];
    }
};