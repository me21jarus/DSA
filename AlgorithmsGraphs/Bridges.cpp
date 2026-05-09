class Solution {
public:
    void dfs(int node, int parent, int& timer,
             vector<int>& disc, vector<int>& low,
             unordered_map<int, list<int>>& adj,
             unordered_map<int,bool>& visited,
             bool& isBridgeEdge, int c, int d) {
        
        visited[node] = true;
        disc[node] = low[node] = timer++;
        
        for(auto& ngb : adj[node]) {
            if(ngb == parent) continue;
            
            if(!visited[ngb]) {
                dfs(ngb, node, timer, disc, low, adj, visited, isBridgeEdge, c, d);
                
                // update low
                low[node] = min(low[node], low[ngb]);
                
                // bridge condition
                if(low[ngb] > disc[node]) {
                    if((node == c && ngb == d) || (node == d && ngb == c)) {
                        isBridgeEdge = true;
                    }
                }
            }
            else {
                // back edge
                low[node] = min(low[node], disc[ngb]);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        
        unordered_map<int, list<int>> adj;
        
        // build graph
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> disc(V, -1), low(V, -1);
        unordered_map<int,bool> visited;
        
        int timer = 0;
        bool isBridgeEdge = false;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, -1, timer, disc, low, adj, visited, isBridgeEdge, c, d);
            }
        }
        
        return isBridgeEdge;
    }
};