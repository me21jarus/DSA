class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        // sort(arr.begin(),arr.end());
        
        // return arr[k-1];
        
        int n = arr.size();
        
        priority_queue<int> ans;
        
        for(int i=0;i<k;i++){
            ans.push(arr[i]);
        }
        for(int i=k;i<n;i++){
            if(arr[i]<ans.top()){
                ans.pop();
                ans.push(arr[i]);
            }
        }
        return ans.top();
    }
};