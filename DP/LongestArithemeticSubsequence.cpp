class Solution {
public:
    int solve(int index, int diff,vector<int>& nums){
        if(index <0) return 0;

        int ans = 0;

        for(int j=index-1;j>=0;j--){
            if(nums[index] - nums[j] == diff){
                ans = max(ans, 1+solve(j, diff, nums));
            }
        }
        return ans;
    }
    int solvedp(int index, int diff,vector<int>& nums,vector<unordered_map<int,int>>& dp){
        if(index <0) return 0;

        int ans = 0;

        if(dp[index].count(diff)) return dp[index][diff];

        for(int j=index-1;j>=0;j--){
            if(nums[index] - nums[j] == diff){
                ans = max(ans, 1+solvedp(j, diff, nums,dp));
            }
        }
        return dp[index][diff] = ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<int,int>> dp(n);
        if(n<=2) return n;
        int ans = 0;
        // using recursion and rec + mem
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         // ans = max(ans, 2+solve(i, nums[j]-nums[i],nums));
        //         ans = max(ans, 2+solvedp(i, nums[j]-nums[i],nums,dp));
        //     }
        // }
        // return ans;


        // using bottom up | dp = tabular
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j];
                int cnt = 1;

                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                dp[i][diff] = 1+cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};