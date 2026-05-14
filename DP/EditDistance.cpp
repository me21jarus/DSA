class Solution {
public:
    int solve(string word1, string word2, int i, int j){
        int n1 = word1.length();
        int n2 = word2.length();
        if(i == n1) return n2 - j;
        if(j == n2) return n1 - i;

        int ans = 0;
        if(word1[i] == word2[j]){
            return solve(word1,word2,i+1,j+1);
        }
        else{
            //insert
            int insertAns = 1 + solve(word1,word2,i,j+1);
            //delete
            int deleteAns = 1 + solve(word1,word2,i+1,j);
            //replace
            int replaceAns = 1 + solve(word1,word2,i+1,j+1);

            ans = min(insertAns,min(deleteAns,replaceAns));
        }
        return ans;
    }
    int solvedp(string word1, string word2, int i, int j,vector<vector<int>> dp){
        int n1 = word1.length();
        int n2 = word2.length();
        if(i == n1) return n2 - j;
        if(j == n2) return n1 - i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(word1[i] == word2[j]){
            return solvedp(word1,word2,i+1,j+1,dp);
        }
        else{
            //insert
            int insertAns = 1 + solvedp(word1,word2,i,j+1,dp);
            //delete
            int deleteAns = 1 + solvedp(word1,word2,i+1,j,dp);
            //replace
            int replaceAns = 1 + solvedp(word1,word2,i+1,j+1,dp);

            ans = min(insertAns,min(deleteAns,replaceAns));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        // return solve(word1,word2, 0,0);

        int n1 = word1.length();
        int n2 = word2.length();

        // vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        // return solvedp(word1,word2, 0, 0,dp);

        // vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));

        // for(int j=0;j<n2;j++){
        //     dp[n1][j] = n2-j;
        // }
        // for(int i=0;i<n1;i++){
        //     dp[i][n2] = n1-i;
        // }

        // for(int i=n1-1;i>=0;i--){
        //     for(int j=n2-1;j>=0;j--){
        //         int ans = 0;
        //         if(word1[i] == word2[j]){
        //             ans = dp[i+1][j+1];
        //         }
        //         else{
        //             //insert
        //             int insertAns = 1 + dp[i][j+1];
        //             //delete
        //             int deleteAns = 1 + dp[i+1][j];
        //             //replace
        //             int replaceAns = 1 + dp[i+1][j+1];

        //             ans = min(insertAns,min(deleteAns,replaceAns));
        //         }
        //         dp[i][j] = ans;
        //     }
        // }
        // return dp[0][0];


        // vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        vector<int> curr(n2+1,0);
        vector<int> next(n2+1,0);

        if(n1 == 0) return n2;
        if(n2 == 0) return n1;

        for(int j=0;j<n2;j++){
            next[j] = n2-j;
        }

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){

                curr[n2] = n1-i;

                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = next[j+1];
                }
                else{
                    //insert
                    int insertAns = 1 + curr[j+1];
                    //delete
                    int deleteAns = 1 + next[j];
                    //replace
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns,min(deleteAns,replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
};