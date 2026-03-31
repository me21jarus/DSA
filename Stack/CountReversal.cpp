class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        int n=s.length();
        if(n%2 != 0){
            return -1;
        }
        int left =0;
        int rgt =0;
        stack<char> st;
        for(char c:s){
            if(c == '{'){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
            if(st.top() == '{'){
                rgt++;
            }
            else{
                left++;
            }
            st.pop();
        }
        return (((left+1)/2)+((rgt+1)/2));
    }
};