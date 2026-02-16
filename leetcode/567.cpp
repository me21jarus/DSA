#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m) return false;

        int freq[26] = {0};

        for(auto s:s1){
            freq[s-'a']++;
        }

        int left = 0;

        for(int right=0;right<m;right++){
            freq[s2[right] - 'a']--;
            if(right - left + 1 > n) {
                freq[s2[left] - 'a']++;
                left++;
            }

            if(right - left + 1 == n) {
                bool found = true;
                for(int i = 0; i < 26; i++) {
                    if(freq[i] != 0) {
                        found = false;
                        break;
                    }
                }
                if(found) return true;
            }
        }
        return false;
    }
};