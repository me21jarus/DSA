class Solution {
  public:
    string maximumFrequency(string& s) {
        // Your code foes here.
        unordered_map<string,int> mp;
        
        vector<string> words;
        unordered_map<string, int> freq;

        string temp = "";   // empty string

        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                freq[temp]++;
                temp = "";
            } else {
                temp = temp + c;
            }
        }

        // For last word
        words.push_back(temp);
        freq[temp]++;

        int maxFreq = 0;
        string ans = "";

        for (string w : words) {
            if (freq[w] > maxFreq) {
                maxFreq = freq[w];
                ans = w;
            }
        }

        return ans + " " + to_string(maxFreq);
    }
};