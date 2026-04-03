class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int n = s.length();
        vector<int> count(26,0);
        queue<char> q;
        string ans = "";
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            
            count[ch - 'a']++;
            
            q.push(ch);
            
            while(!q.empty()){
                if(count[q.front()-'a']>1){
                    q.pop();
                }
                else{
                    ans.push_back(q.front());
                    break;
                }
            }
            if(q.empty()){
                ans.push_back('#');
            }
        }
        return ans;
    }
};