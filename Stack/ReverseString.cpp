class Solution {
public:
    void reverseString(vector<char>& s) {
    //    int i=0;
    //    int j=s.size()-1;
    //    while(i<j){
    //     swap(s[i++],s[j--]);
    //    }

        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            st.push(s[i]);
        }

        int i=0;
        while(!st.empty()){
            s[i++] = st.top();
            st.pop();
        }
    }
};