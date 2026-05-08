class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {

        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V, false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            ans.push_back(frontNode);
            
            // Traverse neighbors in given order
            for(auto& neighbour:adj[frontNode]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};