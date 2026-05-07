#include<iostream>
using namespace std;

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

        void insertUtil(TrieNode* root,string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index]!=NULL){
                child = root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            insertUtil(child,word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode* root, string word){
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index]!=NULL){
                child = root->children[index];
            }
            else{
                return false;
            }
            return searchUtil(child,word.substr(1));
        }
        
        bool searchWord(string word){
            return searchUtil(root,word);
        }

        void deleteSoft(string word){
            TrieNode* curr = root;
            int n = word.length();

            for(int i=0;i<n;i++){
                int index = word[i] - 'A';

                if(curr->children[index] == NULL){
                    return; // word not present
                }

                curr = curr->children[index];
            }
            curr->isTerminal = false;
        }

        bool deleteUtil(TrieNode* root, string word, int depth){
            int n = word.length();
            if(depth == n){
                if(root->isTerminal == false){
                    return false; // no word present
                }

                root->isTerminal = false;

                for(int i =0;i<26;i++){
                    if(root->children[i]!=NULL){
                        return false;
                    }
                }
                return true;
            }

            int index = word[depth] - 'A';
            TrieNode* child = root->children[index];

            if(child == NULL){
                return false; // word not present
            }

            bool shouldDeleteChild = deleteUtil(child, word, depth + 1);

            if(shouldDeleteChild){
                delete child;
                root->children[index] = NULL;

                // check if current node can be deleted
                if(root->isTerminal == false){
                    for(int i = 0; i < 26; i++){
                        if(root->children[i] != NULL){
                            return false;
                        }
                    }
                    return true;
                }
            }
            return false;
        }

        void deleteWordHard(string word){
            deleteUtil(root,word,0);
        }
};

int main(){

    Trie* t = new Trie();

    t->insertWord("ARM");
    t->insertWord("ARMED");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout << t->searchWord("ARM") << endl; // 1

    t->deleteSoft("ARM");
    cout << t->searchWord("ARM") << endl; // 0 (soft deleted)
    cout << t->searchWord("ARMED") << endl; // 1 (still exists)

    t->deleteWordHard("ARMED");
    cout << t->searchWord("ARMED") << endl; // 0

    return 0;
}