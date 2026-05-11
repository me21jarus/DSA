class Solution {
public:
    int solve(int n,vector<int>& days, vector<int>& costs,int i){
        if(i>=n) return 0;

        int o1 = costs[0] + solve(n,days,costs,i+1);

        int j;
        for(j=i;j<n && days[j] < days[i]+7;j++);
        int o2 = costs[1] + solve(n,days,costs,j);
        
        for(j=i;j<n && days[j] < days[i]+30;j++);
        int o3 = costs[2] + solve(n,days,costs,j);

        int ans = min(o1,min(o2,o3));
        return ans;
    }
    int solvedp(int n,vector<int>& days, vector<int>& costs,int i,vector<int>& dp){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int o1 = costs[0] + solvedp(n,days,costs,i+1,dp);

        int j;
        for(j=i;j<n && days[j] < days[i]+7;j++);
        int o2 = costs[1] + solvedp(n,days,costs,j,dp);
        
        for(j=i;j<n && days[j] < days[i]+30;j++);
        int o3 = costs[2] + solvedp(n,days,costs,j,dp);

        dp[i] = min(o1, min(o2, o3));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //using recursion
        // int n = days.size();
        // int ans = solve(n,days,costs,0);
        // return ans;

        //using dp = recursion + memoisation
        // int n = days.size();
        // vector<int> dp(n+1,-1);
        // int ans = solvedp(n,days,costs,0,dp);
        // return ans;

        // using dp = tabular
        int n = days.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;

        for(int k = n-1;k>=0;k--){
            int o1 = costs[0] + dp[k+1];

            int j;
            for(j=k;j<n && days[j] < days[k]+7;j++);
            int o2 = costs[1] + dp[j];
            
            for(j=k;j<n && days[j] < days[k]+30;j++);
            int o3 = costs[2] + dp[j];

            dp[k] = min(o1,min(o2,o3));
        }
        return dp[0];
    }
};