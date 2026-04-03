/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        
        map<int, map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        
        if(root==NULL){
            return ans;
        }
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i:nodes){
            vector<int> column;
                for(auto j:i.second){
                    for(auto k:j.second){
                        column.push_back(k);
                    }
                }
                ans.push_back(column);
            }
        return ans;
    }
};