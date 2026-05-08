class Solution {
  public:
    bool checkCycleDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, list<int>>& adj){
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto& neighbour:adj[node]){
            if(!visited[neighbour]){
                bool cycleFound = checkCycleDFS(neighbour, visited,dfsVisited,adj);
                
                if(cycleFound == 1){
                    return true;
                }
            }
            else if(visited[neighbour] && dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        unordered_map<int, list<int>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        //call dfs for all components
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        for(int i=0;i<=V;i++){
            if(!visited[i]){
                bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
                if(cycleFound == 1){
                    return true;
                }
            }
        }
        return false;
    }
};