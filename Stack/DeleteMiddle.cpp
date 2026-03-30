class Solution {
  public:
    // Function to delete middle element of a stack.
    
    void solve(stack<int>& s,int count,int n){
        if(count == n/2){
            s.pop();
            return;
        }
        
        int num = s.top();
        s.pop();
        
        solve(s,count+1,n);
        
        s.push(num);
    }
    void deleteMid(stack<int>& s) {
        // code here..
        
        int n = s.size();
        int count = 0;
        solve(s,count,n);
    }
};