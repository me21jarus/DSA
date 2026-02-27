class Solution {
  public:
    vector<int> rowSum(vector<vector<int>>& mat) {
        // Code here
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        int maxi = -1;
        int index = -1;
        
        for(int i =0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++){
                sum+=mat[i][j];
            }
            ans.push_back(sum);
            //largest row sum
        //     if(maxi < sum){
        //         maxi = sum;
        //         index = i;
        //     }
        // cout<<index<<endl;
        }
        return ans;
    }
};
