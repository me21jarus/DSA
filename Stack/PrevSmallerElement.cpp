class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            ans[i]=(st.empty())?-1:st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};