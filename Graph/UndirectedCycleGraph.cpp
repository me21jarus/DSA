class Solution {
  public:
    //using DFS
    bool isDFSCyclic(int src, int parent, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj){
           visited[src] = true;
           for(auto& neighbour:adj[src]){
               if(!visited[neighbour]){
                   bool cycleDetected = isDFSCyclic(neighbour,src,visited,adj);
                   
                   if(cycleDetected == 1){
                       return true;
                   }
               }
               else if(neighbour != parent){
                       return true;
                  }
           }
           return false;
    }
    
    //using BFS
    bool isBFSCyclic(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj){
        unordered_map<int,int> parent;
        
        parent[src] = -1;
        visited[src] = 1;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto neighbour:adj[node]){
                if(visited[neighbour] == true && neighbour != parent[node]){
                    return true;
                }
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = node;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        //create adjList
        unordered_map<int,list<int>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool> visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // bool ans = isBFSCyclic(i,visited,adj);
                bool ans = isDFSCyclic(i,-1,visited,adj);
                
                if(ans == 1)
                    return true;
            }
        }
        return false;
    }
};