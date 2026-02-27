#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s1[i] == s2[j]) i++;
            j++;
        }
        return i == n;
    }
};