class Solution {
public:
    int solve(vector<int>& arr,int i,int t,int n){
        if(i==n) return 0;

        int incl = arr[i]*(t+1) + solve(arr,i+1,t+1,n);
        int excl = solve(arr,i+1,t,n);

        int ans = max(incl, excl);
        return ans;
    }
    int solvedp(vector<int>& arr,int i,int t,int n,vector<vector<int>>& dp){
        if(i==n) return 0;

        if(dp[i][t]!=-1) return dp[i][t];

        int incl = arr[i]*(t+1) + solvedp(arr,i+1,t+1,n,dp);
        int excl = solvedp(arr,i+1,t,n,dp);

        int ans = max(incl, excl);
        dp[i][t] = ans;
        return dp[i][t];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        // using recursion
        // int ans = solve(satisfaction, 0, 0, n);
        // return ans;

        //using dp = recursion + mem
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return solvedp(satisfaction,0,0,n,dp);

        //using dp = tabluar
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        // for(int index = n-1;index>=0;index--){
        //     for(int time = index;time>=0;time--){
        //         int incl = satisfaction[index]*(time+1) + dp[index+1][time+1];
        //         int excl = dp[index+1][time];

        //         dp[index][time] = max(incl, excl);
        //     }
        // }
        // return dp[0][0];

        //using space optimisation
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int index = n-1;index>=0;index--){
            for(int time = index;time>=0;time--){
                int incl = satisfaction[index]*(time+1) + next[time+1];
                int excl = next[time];

                curr[time] = max(incl, excl);
            }
            next = curr;
        }
        return next[0];
    }
};