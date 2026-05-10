class Solution {
  public:
    int solve(int n,int k){
        if(n==1) return k;
        
        if(n==2) return k*(k-1) + k;
        
        int ans = solve(n-2,k)*(k-1) + solve(n-1,k)*(k-1);
        
        return ans;
    }
    int solvedp(int n,int k,vector<int>& dp){
        if(n==1) return k;
        
        if(n==2) return k*(k-1) + k;
        
        if(dp[n]!=-1) return dp[n];
        
        dp[n] = solvedp(n-2,k,dp)*(k-1) + solvedp(n-1,k,dp)*(k-1);
        
        return dp[n];
    }
    int countWays(int n, int k) {
        // using recursion
        // int ans = solve(n,k);
        // return ans;
        
        //using dp = rec+mem
        // vector<int> dp(n+1,-1);
        // int ans = solvedp(n,k,dp);
        // return ans;
        
        //using dp = tabluar
        // vector<int> dp(n+1);
        // dp[1] = k;
        // dp[2] = k+k*(k-1);
        
        // for(int i=3;i<=n;i++){
        //     dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-1);
        // }
        // return dp[n];
        
        
        // using space optmisation
        if(n==1) return k;
        
        if(n==2) return k*(k-1) + k;
        
        int prev2 = k;
        int prev1 = k+k*(k-1);
        
        for(int i=3;i<=n;i++){
            int ans = prev2*(k-1) + prev1*(k-1);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};