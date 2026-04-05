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
    unordered_map<int,int> mapping;
    int preIndex = 0;
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int l, int r){
        if(l>r) return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if(l == r) return root;

        int nextVal = preorder[preIndex];
        int pos = mapping[nextVal];

        root->left = solve(preorder,postorder, l,pos);
        root->right = solve(preorder,postorder,pos+1,r-1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();

        for(int i=0;i<n;i++){
            mapping[postorder[i]] = i;
        }

        return solve(preorder,postorder,0,n-1);
    }
};