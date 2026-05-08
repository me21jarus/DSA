class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool> &visited, vector<int>& res){
        visited[node] = true;
        res.push_back(node);
        
        for(auto& neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,adj,visited,res);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> visited(V,false);
        dfs(0,adj,visited,res);
        return res;
    }
};