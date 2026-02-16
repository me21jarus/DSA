#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for(auto c : s){
            if(res.size() && c == res.back()){
                res.pop_back();
            }
            else{
                res.push_back(c);
            }
        }
        return res;
    }
};