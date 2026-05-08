class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        vector<vector<int>> ans(V);
        for(auto &edge : edges){
            int u = edge.first;
            int v = edge.second;
            
            ans[u].push_back(v);
            ans[v].push_back(u);
        }

        return ans;
    }
};