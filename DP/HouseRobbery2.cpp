class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();

        int prev1 = nums[0];
        int prev2 = 0;

        for(int i=1;i<n;i++){
            int incl = prev2+nums[i];
            int excl = prev1;

            int ans = max(excl,incl);

            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> eFirst,eLast;

        if(n==1) return nums[0];

        for(int i=0;i<n;i++){
            if(i!=n-1){
                eLast.push_back(nums[i]);
            }
            if(i!=0){
                eFirst.push_back(nums[i]);
            }
        }

        return max(solve(eLast),solve(eFirst));
    }
};