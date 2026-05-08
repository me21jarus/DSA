class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        unordered_map<int, list<pair<int,int>>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> key(V+1,INT_MAX);
        vector<bool> mst(V+1,false);
        vector<int> parent(V+1,-1);
        
        key[1] = 0;
        parent[1] = -1;
        
        int count=0;
        
        for(int i=0;i<V;i++){
            int mini = INT_MAX;
            int u;
            
            for(int i=0;i<V;i++){
                if(mst[i] == false && key[i] < mini){
                    u = i;
                    mini = key[i];
                }
            }
            
            mst[u] = true;
            count+=key[u];
            
            for(auto neighbour:adj[u]){
                int v = neighbour.first;
                int w = neighbour.second;
                
                if(mst[v] == false && w < key[v]){
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
        return count;
    }
};