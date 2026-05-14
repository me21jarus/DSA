class Solution {
public:

    // ---------------- RECURSION ----------------

    long long solve(int index,
                    int state,
                    int k,
                    vector<int>& prices) {

        if(index == prices.size() || k == 0)
            return 0;

        long long profit = 0;

        // state = 0 -> free state
        // state = 1 -> holding normal stock
        // state = 2 -> holding short position

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

        if(index == prices.size() || k == 0)
            return 0;

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
        //
        // return solvedp(0, 0, k, prices, dp);

        // ---------------- TABULATION ----------------

        // vector<vector<vector<long long>>> dp(
        //     n + 1,
        //     vector<vector<long long>>(3,
        //     vector<long long>(k + 1, 0))
        // );

        // for(int index = n - 1; index >= 0; index--) {

        //     for(int state = 0; state < 3; state++) {

        //         for(int limit = 1; limit <= k; limit++) {

        //             long long profit = 0;

        //             if(state == 0) {

        //                 long long buy =
        //                     -prices[index] +
        //                     dp[index + 1][1][limit];

        //                 long long shortSell =
        //                     prices[index] +
        //                     dp[index + 1][2][limit];

        //                 long long skip =
        //                     dp[index + 1][0][limit];

        //                 profit = max({buy, shortSell, skip});
        //             }

        //             else if(state == 1) {

        //                 long long sell =
        //                     prices[index] +
        //                     dp[index + 1][0][limit - 1];

        //                 long long hold =
        //                     dp[index + 1][1][limit];

        //                 profit = max(sell, hold);
        //             }

        //             else {

        //                 long long buyBack =
        //                     -prices[index] +
        //                     dp[index + 1][0][limit - 1];

        //                 long long hold =
        //                     dp[index + 1][2][limit];

        //                 profit = max(buyBack, hold);
        //             }

        //             dp[index][state][limit] = profit;
        //         }
        //     }
        // }

        // return dp[0][0][k];



        // ---------------- SPACE OPTIMIZATION ----------------

        vector<vector<long long>> curr(
            3, vector<long long>(k + 1, 0));

        vector<vector<long long>> next(
            3, vector<long long>(k + 1, 0));

        for(int index = n - 1; index >= 0; index--) {

            for(int state = 0; state < 3; state++) {

                for(int limit = 1; limit <= k; limit++) {

                    long long profit = 0;

                    if(state == 0) {

                        long long buy =
                            -prices[index] +
                            next[1][limit];

                        long long shortSell =
                            prices[index] +
                            next[2][limit];

                        long long skip =
                            next[0][limit];

                        profit = max({buy, shortSell, skip});
                    }

                    else if(state == 1) {

                        long long sell =
                            prices[index] +
                            next[0][limit - 1];

                        long long hold =
                            next[1][limit];

                        profit = max(sell, hold);
                    }

                    else {

                        long long buyBack =
                            -prices[index] +
                            next[0][limit - 1];

                        long long hold =
                            next[2][limit];

                        profit = max(buyBack, hold);
                    }

                    curr[state][limit] = profit;
                }
            }

            next = curr;
        }

        return next[0][k];
    }
};