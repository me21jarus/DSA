#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isValid(char ch){
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch<= '9'){
            return true;
        }
        return false;
    }
    char islower(char ch){
        if(ch >= 'a' && ch <= 'z'){
            return ch;
        }
        else{
            return ch-'A'+'a';
        }
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n-1;
        
        while(l<=r){
            if(!isValid(s[l])) l++;
            else if(!isValid(s[r])) r--;
            else if(islower(s[l]) != islower(s[r])){
                return false;
            }
            else{
                l++;r--;
            }
        }

        return true;
    }
};