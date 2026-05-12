class Solution {
  public:
    int solve(vector<vector<int>>& mat,int i,int j,int& maxi){
        if(i >= mat.size() || j >= mat[0].size())
            return 0;
            
        int right = solve(mat, i, j+1,maxi);
        int diagnal = solve(mat, i+1, j+1,maxi);
        int bottom = solve(mat, i+1, j,maxi);
        
        if(mat[i][j] == 1){
            int ans = 1+min(right, min(diagnal,bottom));
            maxi = max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    int solvedp(vector<vector<int>>& mat,int i,int j,int& maxi,vector<vector<int>>& dp){
        if(i >= mat.size() || j >= mat[0].size())
            return 0;
            
        if(dp[i][j] != -1) return dp[i][j];    
            
        int right = solvedp(mat, i, j+1,maxi,dp);
        int diagnal = solvedp(mat, i+1, j+1,maxi,dp);
        int bottom = solvedp(mat, i+1, j,maxi,dp);
        
        if(mat[i][j] == 1){
            dp[i][j] = 1+min(right, min(diagnal,bottom));
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;
        }
    }
    int maxSquare(vector<vector<int>>& mat) {
        //using recursion
        // int maxi = 0;
        // solve(mat,0,0,maxi);
        // return maxi;
        
        //using dp = recursion + memoisation
        // int maxi = 0;
        // int n = mat.size();
        // int m = mat[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // solvedp(mat,0,0,maxi,dp);
        // return maxi;
        
        // using dp = tablular
        // int maxi = 0;
        // int n = mat.size();
        // int m = mat[0].size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         int right = dp[i][j+1];
        //         int diagnal = dp[i+1][j+1];
        //         int bottom = dp[i+1][j];
                
        //         if(mat[i][j] == 1){
        //             dp[i][j] = 1+min(right, min(diagnal,bottom));
        //             maxi = max(maxi,dp[i][j]);
        //         }
        //         else{
        //             dp[i][j] = 0;
        //         }
        //     }
        // }
        // return maxi;
        
        // using space optmisiation
        int maxi = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int right = curr[j+1];
                int diagnal = next[j+1];
                int bottom = next[j];
                
                if(mat[i][j] == 1){
                    curr[j] = 1+min(right, min(diagnal,bottom));
                    maxi = max(maxi,curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return maxi;
    }
};