#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    string modify(string& s) {
        // code here.
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                ans+=s[i];
            }
            // else{
            //     ans+="@40";
            // }
        }
        return ans;
    }
};