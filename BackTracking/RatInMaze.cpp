class Solution {
  public:
    bool isSafe(int newx,int newy,vector<vector<bool>>& visited, vector<vector<int>>& maze,int n){
        if(newx >= 0 && newy >= 0 && newx < n && newy < n 
            && !visited[newx][newy] && maze[newx][newy] == 1){            
            return true;
        }
        return false;
    }
    void solve(int x,int y, vector<vector<int>>& maze,int n, vector<string>& ans,vector<vector<bool>>& visited,string path){
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        //D L R U
        visited[x][y] = 1;
        
        //D
        if(isSafe(x+1, y, visited,maze,n)){
            solve(x+1,y,maze,n,ans,visited,path+'D');
        }
        
        
        //L
        if(isSafe(x, y-1, visited,maze,n)){
            solve(x,y-1,maze,n,ans,visited,path+'L');
        }
        
        //R
        if(isSafe(x, y+1, visited,maze,n)){
            solve(x,y+1,maze,n,ans,visited,path+'R');
        }
        
        //U
        if(isSafe(x-1, y, visited,maze,n)){
            solve(x-1,y,maze,n,ans,visited,path+'U');
        }
        
        visited[x][y] = 0;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        
        if(maze[0][0] == 0)
            return ans;
        
        int n = maze.size();
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        string path = "";
        
        solve(0,0,maze,n,ans,visited,path);
        
        return ans;
    }
};