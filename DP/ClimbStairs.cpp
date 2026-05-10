class Solution {
public:
    int solve(int n,int i){
        if(i == n) return 1;
        if(i > n) return 0;

        return solve(n,i+1) + solve(n,i+2);
    }
    int solvedp(int n,int i,vector<int>& dp){
        if(n == i) return 1;
        if(i>n) return 0;

        if(dp[n]!=-1) return dp[n];

        dp[i] = solvedp(n,i+1,dp)+solvedp(n,i+2,dp);

        return dp[i];
    }
    int climbStairs(int n) {
        //recursion
        // int ans = solve(n,0);
        
        //dp = rec+mem
        // vector<int> dp(n+1,-1);
        // int ans = solvedp(n,0,dp);
        // return ans;

        //using tabular
        // if(n<=2){
        //     return n;
        // }
        // vector<int> dp(n+1);

        // dp[1] = 1;
        // dp[2] = 2;

        // for(int i=3;i<=n;i++){
        //     dp[i] = dp[i-1]+dp[i-2];
        // }

        // return dp[n];

        // using space optimisation
        if(n<=2) return n;

        int prev1 = 1;
        int prev2 = 2;

        for(int i=3;i<=n;i++){
            int curr = prev1+prev2;

            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};