// User function Template for C++
class Solution {
  public:
    void makeSet(vector<int>& parent, vector<int>& rank, int n){
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(vector<int>& parent, int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent,parent[node]);
    }
    
    void unionSet(int u,int v,vector<int>& parent, vector<int>& rank){
        u = findParent(parent,u);
        v = findParent(parent,v);
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        int n = edges.size();
        
        int miniWeight = 0;
        
        sort(edges.begin(),edges.end(),[](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        
        vector<int> parent(V);
        vector<int> rank(V);
        makeSet(parent, rank, V);
        
        for(int i=0;i<n;i++){
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);
            int w = edges[i][2];
            
            if(u!=v){
                miniWeight+=w;
                unionSet(u,v,parent, rank);;
            }
        }
        return miniWeight;
    }
};