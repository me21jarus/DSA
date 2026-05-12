class Solution {
  public:
    int solve(int dices,int faces,int target){
        if(target < 0)
            return 0;
        if(dices == 0)
            return target == 0;
        
        int ans = 0;
        for(int i=1;i<=faces;i++){
            ans += solve(dices - 1, faces, target - i);
        }
        return ans;
    }
    int solvedp(int dices,int faces,int target,vector<vector<int>>& dp){
        if(target < 0)
            return 0;
        if(dices == 0)
            return target == 0;
            
            if(dp[dices][target] !=-1) return dp[dices][target];
        
        int ans = 0;
        for(int i=1;i<=faces;i++){
            ans += solvedp(dices - 1, faces, target - i,dp);
        }
        dp[dices][target] = ans;
        return dp[dices][target];
    }
    int noOfWays(int m, int n, int x) {
        // return solve(n,m,x);
        
        // vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
        // return solvedp(n,m,x,dp);
        
        
        vector<vector<int>> dp(n+1,vector<int>(x+1,0));
        
        dp[0][0] = 1;
        
        for(int d =1;d<=n;d++){
            for(int t =1;t<=x;t++){
                int ans = 0;
                for(int i=1;i<=m;i++){
                    if(t-i >= 0){
                        ans += dp[d - 1][t - i];
                    }
                }
                dp[d][t] = ans;
            }
        }
        return dp[n][x];
    }
};