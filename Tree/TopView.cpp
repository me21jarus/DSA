/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        map<int,int> topView;
        queue<pair<Node*,int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* front = temp.first;
            int hd = temp.second;
            
            if(topView.find(hd) == topView.end()){
                topView[hd] = front->data;
            }
            
            if(front->left){
                q.push({front->left,hd-1});
            }
            if(front->right){
                q.push({front->right,hd+1});
            }
        }
        for(auto i : topView){
            ans.push_back(i.second);
        }
        return ans;
    }
};