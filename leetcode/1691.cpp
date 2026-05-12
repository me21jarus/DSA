class Solution {
public:
    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]){
            return true;
        }
        return false;
    }
    int lis(int n,vector<vector<int>>& cuboids){
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int cur = n-1;cur>=0;cur--){
            for(int prev = cur-1;prev>=-1;prev--){
                int take = 0;
                if(prev == -1 || check(cuboids[cur], cuboids[prev])){
                    take = cuboids[cur][2] + next[cur+1];
                }
                int dontTake = 0 + next[prev+1];
                curr[prev+1] = max(take, dontTake);
            }
            next = curr;
        }
        return next[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& a:cuboids){
            sort(a.begin(),a.end());
        }

        sort(cuboids.begin(),cuboids.end());

        return lis(cuboids.size(),cuboids);
    }
};