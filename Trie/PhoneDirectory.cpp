// User function Template for C++
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode('\0');
        }
        
        void insertUtil(TrieNode* root, string words){
            if(words.length() == 0){
                root->isTerminal = true;
                return;
            }
            
            int index = words[0] - 'a';
            TrieNode* child;
            
            if(root->children[index]!=NULL){
                child = root->children[index];
            }
            else{
                child = new TrieNode(words[0]);
                root->children[index] = child;
            }
            insertUtil(child, words.substr(1));
        }
        
        void insert(string words){
            insertUtil(root,words);
        }
        
        void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                TrieNode* next = curr->children[ch-'a'];
                
                if(next!=NULL){
                    prefix+=ch;
                    printSuggestions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }
        
        vector<vector<string>> getSuggestion(string s){
            TrieNode* prev = root;
            
            vector<vector<string>> output;
            string prefix = "";
            
            for(int i = 0;i<s.length();i++){
                char lastch = s[i];
                
                prefix+=lastch;
                
                //check for last ch
                TrieNode* curr = prev->children[lastch - 'a'];
                
                //if not found
                if(curr == NULL){
                    while(i < s.length()){
                        output.push_back({"0"});
                        i++;
                    }
                    break;
                }
                
                //if found
                vector<string> temp;
                printSuggestions(curr,temp, prefix);
                
                output.push_back(temp);
                temp.clear();
                
                prev = curr;
            }
            
            return output;
        }
};

class Solution {
  public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // code here
        
        //step 1 : creation of trie
        Trie* t = new Trie();
        
        //step 2 : insert all contacts in trie
        for(int i=0;i<n;i++){
            string str = contact[i];
            t->insert(str);
        }
        
        //step 3 : return ans
        return t->getSuggestion(s);
    }
};