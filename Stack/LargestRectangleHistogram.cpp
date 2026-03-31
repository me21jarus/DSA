class Solution {
private:
    vector<int> nextSmallerEle(vector<int> heights, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerEle(vector<int> heights, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        // int n = heights.size();
        // int maxArea = 0;
        // for(int i=0;i<n;i++){
        //     int height = heights[i];
        //     int left = i;
        //     int rgt = i;
        //     while(left >=0 && heights[left]>=height){
        //         left--;
        //     }
        //     while(rgt < n && heights[rgt]>=height){
        //         rgt++;
        //     }
        //     int width = rgt-left-1;
        //     int area = height*width;

        //     maxArea = max(maxArea,area);
        // }
        // return maxArea;

        int n = heights.size();
        int maxArea = 0;

        vector<int> next = nextSmallerEle(heights, n);
        vector<int> prev = prevSmallerEle(heights, n);

        for(int i=0;i<n;i++){
            if(next[i] == -1){
                next[i] = n;
            }
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            maxArea = max(maxArea,newArea); 
        }
        return maxArea;
    }
};