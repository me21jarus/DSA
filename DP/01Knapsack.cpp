class Solution {
  public:
    int solve(int W, vector<int> &val,vector<int> &wt,int index){
        if(index == 0){
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        
        int incl = 0;
        if(wt[index] <= W){
            incl = val[index] + solve(W-wt[index], val, wt, index-1);
        }
        
        int excl = solve(W, val,wt,index-1);
        
        int ans = max(incl,excl);
        
        return ans;
    }
    int solvedp(int W, vector<int> &val,vector<int> &wt,int index, vector<vector<int>>& dp){
        if(index == 0){
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        
        if(dp[index][W] !=-1) return dp[index][W];
        
        int incl = 0;
        if(wt[index] <= W){
            incl = val[index] + solvedp(W-wt[index], val, wt, index-1,dp);
        }
        
        int excl = solvedp(W, val,wt,index-1,dp);
        
        dp[index][W] = max(incl,excl);
        
        return dp[index][W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        //using recursion
        // return solve(W,val,wt,n-1);
        
        
        // using dp = rec + mem
        // vector<vector<int>> dp(n,vector<int> (W+1,-1));
        // int ans = solvedp(W, val, wt, n-1, dp);
        // return ans;
        
        //using dp = tabular method
        // vector<vector<int>> dp(n,vector<int> (W+1,0));
        
        // for(int i=wt[0];i<=W;i++){
        //     if(wt[0] <= W) dp[0][i] = val[0];
        //     else dp[0][i] = 0;
        // }
        
        // for(int i=1;i<n;i++){
        //     for(int w=0;w<=W;w++){
        //         int incl = 0;
        //         if(wt[i] <= w){
        //             incl = val[i] + dp[i-1][w-wt[i]];
        //         }
                
        //         int excl = dp[i-1][w];
                
        //         dp[i][w] = max(incl,excl);
        //     }
        // }
        // return dp[n-1][W];
        
        
        // using space optimisation
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        
        for(int i=wt[0];i<=W;i++){
            if(wt[0] <= W) prev[i] = val[0];
            else prev[i] = 0;
        }
        
        for(int i=1;i<n;i++){
            for(int w=0;w<=W;w++){
                int incl = 0;
                if(wt[i] <= w){
                    incl = val[i] + prev[w-wt[i]];
                }
                
                int excl = prev[w];
                
                curr[w] = max(incl,excl);
            }
            prev = curr;
        }
        return prev[W];
    }
};