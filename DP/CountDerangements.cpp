class Solution {
  public:
    int derangeCount(int n) {
        if(n==1) return 0;
        if(n==2) return 1;
        
        //using recursion
        // int ans = (n-1)*(derangeCount(n-1)+derangeCount(n-2));
        // return ans;
        
        // using dp = rec + mem
        // vector<int> dp(n+1,-1);
        // if(dp[n] !=-1) return dp[n];
        // dp[n] = (n-1)*(derangeCount(n-1)+derangeCount(n-2));
        // return dp[n];
    
        // using dp = tablular
        // vector<int> dp(n+1);
        
        // dp[1] = 0;
        // dp[2] = 1;
        
        // for(int i=3;i<=n;i++){
        //     dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
        // }
        // return dp[n];
        
        
        // using space optimisation
        int prev2 = 0;
        int prev1 = 1;
        
        for(int i=3;i<=n;i++){
            int ans = (i-1)*(prev2 + prev1);
            
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};