class node{
    public:
    int data;
    int i;
    int j;
    
    node(int data,int row,int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
        bool operator()(node* a,node* b){
            return a->data > b->data;
        }
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<node*,vector<node*>,compare> minHeap;
        
        int k = mat.size();
        
        for(int i =0;i<k;i++){
            node* tmp = new node(mat[i][0],i,0);
            minHeap.push(tmp);
        }
        
        vector<int> ans;
        
        while(minHeap.size() > 0){
            node* tmp = minHeap.top();
            ans.push_back(tmp->data);
            minHeap.pop();
            
            int i = tmp->i;
            int j = tmp->j;
            
            if(j+1 < mat[i].size()){
                node* nxt = new node(mat[i][j+1],i,j+1);
                minHeap.push(nxt);
            }
        }
        return ans;
    }
};