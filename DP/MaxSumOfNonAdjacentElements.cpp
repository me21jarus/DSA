// User function template for C++
class Solution {
  public:
    int solve(vector<int>& arr, int n){
        if(n<0) return 0;
        if(n==0) return arr[0];
        int incl = solve(arr,n-2) + arr[n];
        int excl = solve(arr,n-1);
        
        return max(incl,excl);
    }
    // calculate the maximum sum with out adjacent
    int solvedp(vector<int>& arr,int n,vector<int>& dp){
        if(n<0) return 0;
        if(n==0) return arr[0];
        
        if(dp[n]!=-1) return dp[n];
        
        int incl = solvedp(arr,n-2,dp) + arr[n];
        int excl = solvedp(arr,n-1,dp) + 0;
        
        dp[n] = max(excl,incl);
        
        return dp[n];
    }
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        //using recursion
        // int ans = solve(arr,n-1);
        // return ans;
        
        
        //using dp = rec + mem
        // vector<int> dp(n,-1);
        // int ans = solvedp(arr,n-1,dp);
        // return ans;
        
        
        //using dp = tabular
        // vector<int> dp(n,0);
        // dp[0] = arr[0];
        
        // for(int i=1;i<n;i++){
        //     int incl = dp[i-2] + arr[i];
        //     int excl = dp[i-1];
        //     dp[i] = max(excl,incl);
        // }
        // return dp[n-1];
        
        
        //using space optimisation
        int prev2 = 0;
        int prev1 = arr[0];
        
        for(int i=1;i<n;i++){
            int incl = prev2 + arr[i];
            int excl = prev1;
            
            int ans = max(excl,incl);
            
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};