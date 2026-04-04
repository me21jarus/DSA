/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
    vector<int> ans;
    
    if(root == NULL){
        return ans;
    }
    
    map<int,int> bottomView;
    queue<pair<Node*,int>> q;
    
    q.push({root,0});
    
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        
        Node* bottom = temp.first;
        int hd = temp.second;
        
        bottomView[hd] = bottom->data;
        
        if(bottom->left){
            q.push({bottom->left,hd-1});
        }
        if(bottom->right){
            q.push({bottom->right,hd+1});
        }
    }
    for(auto i:bottomView){
        ans.push_back(i.second);
    }
    
    return ans;
    }
};