/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*> &ans){
        if(root == NULL) return;

        ans.push_back(root);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    void flatten(TreeNode* root) {
        // if(root == NULL) return;

        // vector<TreeNode*> ans;

        // preorder(root, ans);

        // for(int i = 0;i<ans.size()-1;i++){
        //     ans[i]->left = NULL;
        //     ans[i]->right = ans[i+1];
        // }

        // ans.back()->left = NULL; 
        // ans.back()->right = NULL; 

        TreeNode* curr = root;

        while(curr!=NULL){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};