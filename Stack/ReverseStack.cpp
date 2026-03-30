class Solution {
  public:
    void insertAtBottom(stack<int>& st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int num = st.top();
        st.pop();
        
        insertAtBottom(st,x);
        
        st.push(num);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int num = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtBottom(st,num);
    }
};