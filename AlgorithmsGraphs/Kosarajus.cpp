class Solution {
  public:
    void dfs(int node, unordered_map<int,bool>& visited,stack<int>& s,unordered_map<int,list<int>>& adj){
        visited[node] = true;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,s,adj);
            }
        }
        s.push(node);
    }
    void revDfs(int top,unordered_map<int,bool>& visited, unordered_map<int,list<int>>& adj){
        visited[top] = true;
        for(auto& nbr : adj[top]){
            if(!visited[nbr]){
                revDfs(nbr,visited,adj);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,list<int>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        //topo sort
        stack<int> st;
        unordered_map<int,bool> visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited, st,adj);
            }
        }
        
        //create transpose
        
        unordered_map<int,list<int>> transpose;
        for(int i=0;i<V;i++){
            visited[i] = false;
            for(auto& nbr:adj[i]){
                transpose[nbr].push_back(i);
            }
        }
        
        int count = 0;
        //call dfs untill stack is null
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!visited[top]){
                count++;
                revDfs(top,visited,transpose);
            }
        }
        return count;
    }
};