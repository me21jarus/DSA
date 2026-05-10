class Solution {
  public:
    int solveRec(vector<int>& nums,int n){
        if(n == 0) return 0;
        if(n < 0) return INT_MAX;
        
        int mini = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            int ans = solveRec(nums,n-nums[i]);
            
            if(ans != INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        return mini;
    }
    int solvedp(vector<int>& nums,int n,vector<int>& dp){
        if(n==0) return 0;
        if(n<0) return INT_MAX;
        
        if(dp[n]!=-1) return dp[n];
        
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int ans = solvedp(nums,n-nums[i],dp);
            if(ans != INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        dp[n] = mini;
        
        return mini;
    }
    int findMin(int n) {
        vector<int> nums = {1,2,5,10};
        //using recursion
        // int ans =  solveRec(nums,n);
        
        // using dp = rec+mem
        // vector<int> dp(n+1,-1);
        // int ans = solvedp(nums,n,dp);
        
        // return ans;
        
        
        // using tabluar
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j] >= 0 && dp[i-nums[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-nums[j]]);
                }
            }
        }
        
        if(dp[n] == INT_MAX) return -1;
        
        return dp[n];
    }
};