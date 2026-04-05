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
    int preIndex = 0;
    TreeNode* solve(vector<int>& preorder, int inStart,int inEnd){
        if(inStart > inEnd) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        int pos = mapping[rootVal];

        root->left = solve(preorder, inStart, pos-1);
        root->right = solve(preorder, pos+1, inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        for(int i=0;i<n;i++){
            mapping[inorder[i]] = i;
        }

        return solve(preorder,0,n-1);
    }
};