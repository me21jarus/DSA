class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int sum = 0;
        
        int n = arr.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        while(pq.size()  > 1){
            int a = pq.top();
            pq.pop();
            
            int b = pq.top();
            pq.pop();
            
            int ans = a+b;
            sum+=ans;
            pq.push(ans);
            
        }
        
        return sum;
    }
};