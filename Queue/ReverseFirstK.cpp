class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        int n = q.size();
        
        if(k > n || k <= 0) return q;
        
        stack<int> st;
        
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        int rem = n - k;
        while(rem--){
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        return q;
    }
};