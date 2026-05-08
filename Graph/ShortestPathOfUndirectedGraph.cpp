class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        
        unordered_map<int , list<int>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //bfs
        unordered_map<int,bool> visited;
        vector<int> dist(V, -1);
        
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto& neighbour:adj[node]){
                if(dist[neighbour] == -1){
                    dist[neighbour] = dist[node]+1;
                    q.push(neighbour);
                }
            }
        }
        
        return dist;
    }
};
