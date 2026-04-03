/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    int solve(Node* root){
        if(root==NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return root->data;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == -1 || right == -1 || root->data != left + right)
            return -1;
        
        return root->data + left + right;
    }
    bool isSumTree(Node* root) {
        // Your code here
        if(root == NULL){
            return 0;
        }

        return solve(root) != -1;
    }
};