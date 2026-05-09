class Solution {
  public:
  
    void dfs(int node, int parent, vector<int> adj[],
             vector<int>& disc, vector<int>& low,
             vector<bool>& visited, vector<bool>& isAP,
             int& timer) {
        
        visited[node] = true;
        disc[node] = low[node] = timer++;
        
        int child = 0;
        
        for(auto nbr : adj[node]) {
            
            if(nbr == parent) continue;
            
            if(!visited[nbr]) {
                child++;
                dfs(nbr, node, adj, disc, low, visited, isAP, timer);
                
                // update low
                low[node] = min(low[node], low[nbr]);
                
                // articulation condition (non-root)
                if(parent != -1 && low[nbr] >= disc[node]) {
                    isAP[node] = true;
                }
            }
            else {
                // back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
        
        // root condition
        if(parent == -1 && child > 1) {
            isAP[node] = true;
        }
    }
  
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false);
        vector<bool> isAP(V, false);
        
        int timer = 0;
        
        // run DFS for all components
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, isAP, timer);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(isAP[i]) ans.push_back(i);
        }
        
        if(ans.empty()) return {-1};
        
        return ans;
    }
};