class Solution {
private:
    vector<int> nextSmallerEle(vector<int>& heights, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i = n-1; i >= 0; i--){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerEle(vector<int>& heights, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < n; i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights, int n) {
        int maxArea = 0;

        vector<int> next = nextSmallerEle(heights, n);
        vector<int> prev = prevSmallerEle(heights, n);

        for(int i = 0; i < n; i++){
            if(next[i] == -1){
                next[i] = n;
            }
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            maxArea = max(maxArea, newArea); 
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;   // ✅ fix

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int area = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            int newArea = largestRectangleArea(heights, m);
            area = max(area, newArea);
        }
        return area;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        int maxArea = 0;

        for(int i=0;i<=n;i++){
            int currHeight = (i == n)? 0: heights[i];

            while(!st.empty() && currHeight < heights[st.top()]){
                int h =heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty()?-1:st.top();

                int width = right -left-1;
                maxArea = max(maxArea, h*width);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        
        vector<int> histogram(matrix[0].size(), 0);

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<histogram.size();j++){
                if(matrix[i][j] == '1'){
                    histogram[j]++;
                }
                else{
                    histogram[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(histogram));
        }
        return maxi;
    }
};