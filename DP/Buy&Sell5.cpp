class Solution {
public:

    long long NEG = -1e15;

    // ---------------- RECURSION ----------------

    long long solve(int index,
                    int state,
                    int k,
                    vector<int>& prices) {

        if(index == prices.size()) {

            if(state == 0)
                return 0;

            return NEG;
        }

        if(k == 0) {

            if(state == 0)
                return 0;

            return NEG;
        }

        long long profit = 0;

        // state = 0 -> free state
        // state = 1 -> holding bought stock
        // state = 2 -> holding short sold stock

        if(state == 0) {

            long long buy =
                -prices[index] +
                solve(index + 1, 1, k, prices);

            long long shortSell =
                prices[index] +
                solve(index + 1, 2, k, prices);

            long long skip =
                solve(index + 1, 0, k, prices);

            profit = max({buy, shortSell, skip});
        }

        else if(state == 1) {

            long long sell =
                prices[index] +
                solve(index + 1, 0, k - 1, prices);

            long long hold =
                solve(index + 1, 1, k, prices);

            profit = max(sell, hold);
        }

        else {

            long long buyBack =
                -prices[index] +
                solve(index + 1, 0, k - 1, prices);

            long long hold =
                solve(index + 1, 2, k, prices);

            profit = max(buyBack, hold);
        }

        return profit;
    }

    // ---------------- MEMOIZATION ----------------

    long long solvedp(int index,
                      int state,
                      int k,
                      vector<int>& prices,
                      vector<vector<vector<long long>>>& dp) {

        if(index == prices.size()) {

            if(state == 0)
                return 0;

            return NEG;
        }

        if(k == 0) {

            if(state == 0)
                return 0;

            return NEG;
        }

        if(dp[index][state][k] != -1)
            return dp[index][state][k];

        long long profit = 0;

        if(state == 0) {

            long long buy =
                -prices[index] +
                solvedp(index + 1, 1, k, prices, dp);

            long long shortSell =
                prices[index] +
                solvedp(index + 1, 2, k, prices, dp);

            long long skip =
                solvedp(index + 1, 0, k, prices, dp);

            profit = max({buy, shortSell, skip});
        }

        else if(state == 1) {

            long long sell =
                prices[index] +
                solvedp(index + 1, 0, k - 1, prices, dp);

            long long hold =
                solvedp(index + 1, 1, k, prices, dp);

            profit = max(sell, hold);
        }

        else {

            long long buyBack =
                -prices[index] +
                solvedp(index + 1, 0, k - 1, prices, dp);

            long long hold =
                solvedp(index + 1, 2, k, prices, dp);

            profit = max(buyBack, hold);
        }

        return dp[index][state][k] = profit;
    }

    long long maximumProfit(vector<int>& prices, int k) {

        int n = prices.size();

        // ---------------- RECURSION ----------------
        // return solve(0, 0, k, prices);

        // ---------------- MEMOIZATION ----------------

        // vector<vector<vector<long long>>> dp(
        //     n,
        //     vector<vector<long long>>(3,
        //     vector<long long>(k + 1, -1))
        // );

        // return solvedp(0, 0, k, prices, dp);


        // ---------------- TABULATION ----------------

        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(3,
            vector<long long>(k + 1, NEG))
        );

        for(int limit = 0; limit <= k; limit++) {
            dp[n][0][limit] = 0;
        }

        for(int index = n - 1; index >= 0; index--) {

            for(int limit = 0; limit <= k; limit++) {

                dp[index][0][limit] =
                    dp[index + 1][0][limit];

                if(limit > 0) {

                    dp[index][0][limit] = max(
                        dp[index][0][limit],

                        -prices[index] +
                        dp[index + 1][1][limit]
                    );

                    dp[index][0][limit] = max(
                        dp[index][0][limit],

                        prices[index] +
                        dp[index + 1][2][limit]
                    );

                    dp[index][1][limit] = max(

                        prices[index] +
                        dp[index + 1][0][limit - 1],

                        dp[index + 1][1][limit]
                    );

                    dp[index][2][limit] = max(

                        -prices[index] +
                        dp[index + 1][0][limit - 1],

                        dp[index + 1][2][limit]
                    );
                }
            }
        }

        return dp[0][0][k];
    }
};