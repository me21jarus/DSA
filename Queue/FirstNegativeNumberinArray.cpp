class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        // vector<int> ans;
        // int n = arr.size();
        
        // for(int i=0;i<=n-k;i++){
        //     bool found = false;
        //     for(int j=i;j<i+k;j++){
        //         if(arr[j]<0){
        //             ans.push_back(arr[j]);
        //             found =true;
        //             break;
        //         }
        //     }
        //     if(!found) {
        //         ans.push_back(0);
        //     }
        // }
        // return ans;
        
        vector<int> ans;
        int n = arr.size();
        deque<int> dq;
        
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                dq.push_back(i);
            }
        }
        
        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        for(int i=k;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            if(arr[i]<0){
                dq.push_back(i);
            }
            if(dq.size()>0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};