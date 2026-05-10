class Solution {
  public:
    int solve(int n,int x,int y,int z){
        if(n==0) return 0;
        
        if(n<0) return INT_MIN;
        
        int a = solve(n-x,x,y,z)+1;
        int b = solve(n-y,x,y,z)+1;
        int c = solve(n-z,x,y,z)+1;
        
        int ans = max(a,max(b,c));
        
        return ans;
    }
    // Function to find the maximum number of cuts.
    int solvedp(int n,int x,int y,int z,vector<int>& dp){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        
        if(dp[n]!=-1) return dp[n];
        
        int a = solvedp(n-x,x,y,z,dp)+1;
        int b = solvedp(n-y,x,y,z,dp)+1;
        int c = solvedp(n-z,x,y,z,dp)+1;
        
        dp[n] = max(a,max(b,c));
        
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z) {
        // using recursion
        // int ans = solve(n,x,y,x);
        // return ans;
        
        //using dp = recurison + mem
        // vector<int> dp(n+1,-1);
        // int ans = solvedp(n,x,y,z,dp);
        // return (ans < 0) ? 0 : ans;
        
        // using dp = tabular
        vector<int> dp(n+1,INT_MIN);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            if(i-x>=0) dp[i] = max(dp[i],dp[i-x] + 1);
            if(i-y>=0) dp[i] = max(dp[i],dp[i-y] + 1);
            if(i-z>=0) dp[i] = max(dp[i],dp[i-z] + 1);
        }
        if(dp[n] < 0) return 0;
        
        return dp[n];
    }
};