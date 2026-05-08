class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        unordered_map<int, list<pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dist(V, INT_MAX);
        
        set<pair<int,int>> s;
        
        dist[src] = 0;
        s.insert({0,src});
        
        while(!s.empty()){
            auto top = *(s.begin());
            
            int distance = top.first;
            int topNode = top.second;
            
            s.erase(s.begin());
            
            for(auto neighbour:adj[topNode]){
                if(distance + neighbour.second < dist[neighbour.first]){
                    auto record = s.find({dist[neighbour.first],neighbour.first});
                    if(record!=s.end()){
                        s.erase(record);
                    }
                    
                    dist[neighbour.first] = distance + neighbour.second;
                    s.insert({dist[neighbour.first], neighbour.first});
                }
            }
        }
        
        return dist;
    }
};