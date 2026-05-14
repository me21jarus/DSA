class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        // for(int i=0;i<n;i++){
        //     int buy = prices[i];
        //     for(int j=i;j<n;j++){
        //         int sell = prices[j];
        //         int profit = sell - buy;
        //         ans = max(ans,profit);
        //     }
        // }

        // int l = 0;
        // for(int r=1;r<n;r++){
        //     if(prices[l] < prices[r]){
        //         int profit = prices[r] - prices[l];
        //         ans = max(profit, ans);
        //     }
        //     else{
        //         l=r;
        //     }
        // }

        int minBuy = prices[0];
        for(auto& sell : prices){
            ans = max(ans,sell - minBuy);
            minBuy = min(minBuy,sell);
        }
        return ans;
    }
};