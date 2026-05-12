class Solution {
public:
    bool solve(int index, vector<int>& nums,int n,int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(index >= n) return 0;

        bool incl = solve(index+1,nums,n,target - nums[index]);
        bool excl = solve(index+1,nums,n,target);

        return incl || excl;
    }
    bool solvedp(int index, vector<int>& nums,int n,int target, vector<vector<int>>& dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(index >= n) return 0;

        if(dp[index][target] != -1) return dp[index][target];

        bool incl = solvedp(index+1,nums,n,target - nums[index],dp);
        bool excl = solvedp(index+1,nums,n,target,dp);

        return dp[index][target] = incl || excl;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto& num:nums){
            sum+=num;
        }
        // vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        vector<vector<int>> dp(n+1,vector<int>(sum/2+1,0));
        if(sum & 1){
            return false;
        }
        else{
            // return solve(0,nums,n,sum/2);
            // return solvedp(0,nums,n,sum/2,dp);

            for(int i=0;i<=n;i++){
                dp[i][0] = 1;
            }

            for(int index = n-1;index >= 0;index--){
                for(int target = 0; target <= sum/2;target++){
                    bool incl = 0;
                    if(target - nums[index] >=0)
                        incl = dp[index+1][target - nums[index]];
                    bool excl = dp[index+1][target];

                    dp[index][target] = incl || excl;
                }
            }
        }
        return dp[0][sum/2];
    }
};