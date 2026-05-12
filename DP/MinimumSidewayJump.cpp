class Solution {
public:
    int solve(vector<int>& obstacles, int i, int l){
        int n = obstacles.size();
        if(i == n){
            return 0;
        }
        if(obstacles[i+1] != l){
            return solve(obstacles,i+1,l);
        }
        else{
            int ans = INT_MAX;
            for(int lane=1;lane<=3;lane++){
                if(l != lane && obstacles[i] != lane){
                    ans = min(ans, 1 + solve(obstacles,i,lane));
                }
            }
            return ans;
        }
    }
    int solvedp(vector<int>& obstacles, int i, int l,vector<vector<int>>& dp){
        int n = obstacles.size();
        if(i == n-1){
            return 0;
        }

        if(dp[l][i] != -1) return dp[l][i];

        if(obstacles[i+1] != l){
            return solvedp(obstacles,i+1,l,dp);
        }
        else{
            int ans = INT_MAX;
            for(int lane=1;lane<=3;lane++){
                if(l != lane && obstacles[i] != lane){
                    ans = min(ans, 1 + solvedp(obstacles,i,lane,dp));
                }
            }
            dp[l][i] = ans;
            return dp[l][i];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        // int ans = solve(obstacles,0,2);
        // return ans;

        //using dp = recursion + mem
        // vector<vector<int>> dp(4,vector<int>(n+1,-1));
        // int ans = solvedp(obstacles,0,2,dp);
        // return ans;

        //using dp = tab
        // vector<vector<int>> dp(4, vector<int>(n, 1e9));
        // // base case
        // dp[1][n-1] = 0;
        // dp[2][n-1] = 0;
        // dp[3][n-1] = 0;

        // for(int i = n - 2; i >= 0; i--) {
        //     for(int lane = 1; lane <= 3; lane++) {
        //         // move forward
        //         if(obstacles[i + 1] != lane) {
        //             dp[lane][i] = dp[lane][i + 1];
        //         }
        //         else {
        //             int ans = 1e9;
        //             // side jump
        //             for(int l = 1; l <= 3; l++) {
        //                 if(l != lane && obstacles[i] != l) {
        //                     ans = min(ans,1 + dp[l][i+1]);
        //                 }
        //             }
        //             dp[lane][i] = ans;
        //         }
        //     }
        // }
        // return min(dp[2][0], min(1+dp[1][0],1+dp[3][0]));

        //using space optimisation
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);

        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int i = n - 2; i >= 0; i--) {
            for(int lane = 1; lane <= 3; lane++) {
                // move forward
                if(obstacles[i + 1] != lane) {
                    curr[lane] = next[lane];
                }
                else {
                    int ans = 1e9;
                    // side jump
                    for(int l = 1; l <= 3; l++) {
                        if(l != lane && obstacles[i] != l) {
                            ans = min(ans,1 + next[l]);
                        }
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1+next[1],1+next[3]));
    }
};