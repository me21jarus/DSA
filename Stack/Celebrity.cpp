class Solution {
  public:
    bool knows(vector<vector<int>>& mat, int a,int b, int n){
        return mat[a][b];
    }
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        stack<int> st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(knows(mat,a,b,n)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int candidate = st.top();
        
        // row check (celebrity knows nobody)
        for(int i = 0; i < n; i++){
            if(i != candidate && mat[candidate][i] == 1){
                return -1;
            }
        }

        // column check (everyone knows celebrity)
        for(int i = 0; i < n; i++){
            if(i != candidate && mat[i][candidate] == 0){
                return -1;
            }
        }
        
        
        return candidate;
    }
};