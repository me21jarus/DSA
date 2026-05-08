// User function Template for C++
class Solution {
  public:
    void dfs(int node, stack<int>& s, unordered_map<int,bool>& visited, unordered_map<int,list<pair<int,int>>>& adj){
        visited[node] = true;
        
        for(auto& neighbour:adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first,s, visited,adj);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<int> dist(V,INT_MAX);
        
        unordered_map<int,list<pair<int,int>>>adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
        }
        
        unordered_map<int,bool> visited;
        stack<int> s;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, s, visited,adj);
            }
        }
        
        int src = 0;
        dist[src] = 0;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            
            if(dist[top] != INT_MAX){
                for(auto& i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top]+i.second;
                    }
                }
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};