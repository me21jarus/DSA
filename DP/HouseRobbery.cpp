class Solution {
public:
    int solve(vector<int>& nums,int n){
        if(n<0) return 0;
        if(n==0) return nums[0];

        int incl = solve(nums,n-2) + nums[n];
        int excl = solve(nums,n-1);

        return max(incl,excl);
    }
    int solvedp(vector<int>& nums,int n,vector<int>& dp){
        if(n<0) return 0;
        if(n==0) return nums[0];

        if(dp[n]!=-1) return dp[n];

        int incl = solvedp(nums,n-2,dp) + nums[n];
        int excl = solvedp(nums,n-1,dp);

        dp[n] = max(excl,incl);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        //using recursion
        // int ans = solve(nums,n-1);
        // return ans;

        //using Dp = rec + mem
        // vector<int> dp(n,-1);
        // int ans = solvedp(nums,n-1,dp);
        // return ans;

        //using Dp = tabluar
        // vector<int> dp(n,0);
        // if(n == 0) return 0;
        // if(n == 1) return nums[0];

        // dp[0] = nums[0];
        // dp[1] = max(nums[0],nums[1]);

        // for(int i=2;i<n;i++){
        //     int incl = dp[i-2] + nums[i];
        //     int excl = dp[i-1];

        //     dp[i] = max(incl,excl);
        // }
        // return dp[n-1];


        //using space optmisation
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int incl = prev2 + nums[i];
            int excl = prev1;

            int ans = max(incl,excl);

            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};