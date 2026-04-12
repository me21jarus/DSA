/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int> &ans){
        if(root == NULL) return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int> ans;
        inorder(root,ans);
        int n = ans.size();
        
        int l = 0;
        int r = n-1;
        
        while(l<r){
            int sum = ans[l] + ans[r];
            if(sum == target){
                return true;
            }
            else if(sum>target){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};