class node{
    public:
        int data;
        int row;
        int col;
        
        node(int data,int row,int col){
            this->data = data;
            this->row = row;
            this->col = col;
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
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        // Code here
        vector<int> ans;
        
        int row = mat.size();
        int col = mat[0].size();
        
        int mini = INT_MAX,maxi = INT_MIN;
        
        priority_queue<node*,vector<node*>,compare> minHeap;
        
        for(int i=0;i<row;i++){
            int element = mat[i][0];
            mini = min(mini,element);
            maxi = max(maxi,element);
            minHeap.push(new node(element,i,0));
        }
        int start = mini, end = maxi;
        
        while(!minHeap.empty()){
            node* tmp = minHeap.top();
            minHeap.pop();
            
            mini = tmp->data;
            
            if(maxi - mini < end-start){
                start = mini;
                end = maxi;
            }
            
            if(tmp->col+1 < col){
                int nextVal = mat[tmp->row][tmp->col + 1];
                maxi = max(maxi, nextVal);
                minHeap.push(new node(nextVal, tmp->row, tmp->col +1));
            }
            else{
                break;
            }
        }
        
        return {start,end};
    }
};