class Solution {
public:
    int solve(int start, int end,vector<int>& slices, int eat){
        if(eat==0 || start > end) return 0;

        int take = slices[start] + solve(start+2,end,slices,eat-1);
        int notTake = solve(start+1,end,slices,eat);

        return max(take,notTake);
    }
    int solvedp(int start, int end,vector<int>& slices, int eat,vector<vector<int>>& dp){
        if(eat==0 || start > end) return 0;

        if(dp[start][eat] != -1) return dp[start][eat];
 
        int take = slices[start] + solvedp(start+2,end,slices,eat-1,dp);
        int notTake = solvedp(start+1,end,slices,eat,dp);

        dp[start][eat] = max(take,notTake);
        return dp[start][eat];
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        //using rec
        // int case1 = solve(0,k-2,slices,k/3);
        // int case2 = solve(1,k-1,slices,k/3);
        // return max(case1,case2);

        //using dp = rec + mem
        // vector<vector<int>> dp1(k,vector<int>(k,-1));
        // vector<vector<int>> dp2(k,vector<int>(k,-1));
        // int case1 = solvedp(0,k-2,slices,k/3,dp1);
        // int case2 = solvedp(1,k-1,slices,k/3,dp2);
        // return max(case1,case2);

        //using dp = tabular
        vector<vector<int>> dp1(k+2, vector<int>(k+1, 0));
        vector<vector<int>> dp2(k+2, vector<int>(k+1, 0));

        for(int index = k-2;index >=0 ;index--){
            for(int eat = 1;eat<=k/3;eat++){
                int take = slices[index] + dp1[index+2][eat-1];
                int notTake = dp1[index+1][eat];

                dp1[index][eat] = max(take,notTake);
            }
        }
        int case1 = dp1[0][k/3];

        for(int index = k-1;index >=1 ;index--){
            for(int eat = 1;eat<=k/3;eat++){
                int take = slices[index] + dp2[index+2][eat-1];
                int notTake = dp2[index+1][eat];

                dp2[index][eat] = max(take,notTake);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1,case2);
    }
};