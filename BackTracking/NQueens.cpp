class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board, int n){
        int x = row;
        int y = col;

        //check for same row
        while(y>=0){
            if(board[x][y] == 'Q')
                return false;
            y--;
        }

        x=row;y=col;
        //diagonal
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q')
                return false;
            y--;
            x--;
        }

        x=row;y=col;
        //diagonal
        while(x<n && y>=0){
            if(board[x][y] == 'Q')
                return false;
            y--;
            x++;
        }
        return true;
    }
    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n){
        //base case
        vector<string> temp;
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,ans,board,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0,ans,board,n);

        return ans;
    }
};