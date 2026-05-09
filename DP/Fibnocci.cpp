class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n == 0 || n == 1) return n;

        if(dp[n] != -1) return dp[n];

        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        
        if(n==0 ||n==1) return n;

        //normal approach
        // int a = 0;
        // int b = 1;

        // int res = 0;
        // while(n>1){
        //     res = a+b;
        //     a=b;
        //     b=res;
        //     n--;
        // }
        // return res;


        //using recursion
        // return fib(n-1)+fib(n-2);

        //using dp - recursion + memoisation
        // vector<int> dp(n+1,-1);

        // return solve(n,dp);

        // using dp - tabluar
        // vector<int> dp(n+1);

        // dp[0] = 0;
        // dp[1] = 1;

        // for(int i=2;i<=n;i++){
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp[n];



        //using space optimisation
        int prev1 = 1;
        int prev2 = 0;

        for(int i=2;i<=n;i++){
            int curr = prev1+prev2;

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};