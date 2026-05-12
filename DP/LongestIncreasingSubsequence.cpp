class Solution {
  public:
    int solve(int n,vector<int>& arr, int curr,int prev){
        if(curr == n) return 0;
        
        int take = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            take = 1+ solve(n,arr,curr+1, curr);
        }
        
        int dontTake = 0 + solve(n,arr,curr+1,prev);
        return max(take,dontTake);
    }
    int solvedp(int n,vector<int>& arr, int curr,int prev,vector<vector<int>>& dp){
        if(curr == n) return 0;
        
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        
        int take = 0;
        if(prev == -1 || arr[curr] > arr[prev]){
            take = 1+ solvedp(n,arr,curr+1, curr,dp);
        }
        
        int dontTake = 0 + solvedp(n,arr,curr+1,prev,dp);
        
        return dp[curr][prev+1] = max(take,dontTake);
    }
    int lis(vector<int>& arr) {
        //using recursion
        // int n = arr.size();
       // return solve(n,arr,0,-1);
    
        //using dp = rec + mem
        int n = arr.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solvedp(n,arr,0,-1,dp);
        
        // using dp = tabular 
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        // for(int curr = n-1;curr>=0;curr--){
        //     for(int prev = curr-1;prev >= -1;prev--){
        //         int take = 0;
        //         if(prev == -1 || arr[curr] > arr[prev]){
        //             take = 1+ dp[curr+1][curr+1];
        //         }
                
        //         int dontTake = 0 + dp[curr+1][prev+1];
                
        //         dp[curr][prev+1] = max(take,dontTake);
        //     }
        // }
        // return dp[0][0];
        
        //using space optimisation
        vector<int> current(n+1,0);
        vector<int> next(n+1,0);
        
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = curr-1;prev >= -1;prev--){
                int take = 0;
                if(prev == -1 || arr[curr] > arr[prev]){
                    take = 1+ next[curr+1];
                }
                
                int dontTake = 0 + current[prev+1];
                
                current[prev+1] = max(take,dontTake);
            }
            next = current;
        }
        return next[0];
    }
};