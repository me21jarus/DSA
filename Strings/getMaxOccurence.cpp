#include<iostream>
#include<string>
using namespace std;

class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int n = s.length();
        int arr[26] = {0};
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            
            int num = 0;
            if(ch >= 'a' && ch <= 'z'){
                num = ch - 'a';
            }
            else{
                num = ch - 'A';
            }
            arr[num]++;
        }
        int maxi = -1, ans =-1;
        for(int i=0;i<26;i++){
            if(maxi < arr[i]){
                ans = i;
                maxi = arr[i];
            }
        }
        char finalAnswer = 'a' + ans;
        return finalAnswer;
    }
};