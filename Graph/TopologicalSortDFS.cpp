class Solution {
  public:
    void topoSort(int node, unordered_map<int,bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adj){
        visited[node] = 1;
        
        for(auto& neighbour : adj[node]){
            if(!visited[neighbour]){
                topoSort(neighbour,visited,s,adj);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        
        unordered_map<int, list<int>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        //call dfs ts untill function of all components
        unordered_map<int,bool> visited;
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoSort(i, visited, s, adj);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};