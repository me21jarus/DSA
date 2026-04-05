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
    map<int,int> mapping;
    int postIndex;
    TreeNode* solve(vector<int>& postorder, int inStart,int inEnd){
        if(inStart > inEnd) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        int pos = mapping[rootVal];

        root->right = solve(postorder, pos+1, inEnd);
        root->left = solve(postorder, inStart, pos-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        postIndex = n-1;

        for(int i=n-1;i>=0;i--){
            mapping[inorder[i]] = i;
        }
        return solve(postorder,0,n-1);
    }
};