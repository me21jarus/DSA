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