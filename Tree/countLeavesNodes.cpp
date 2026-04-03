/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  private:
    void inorderTraversal(Node* &root,int &cnt){
        if(root==NULL){
             return;
        }
        
        inorderTraversal(root->left,cnt);
        
        if(root->left == NULL && root->right == NULL){
            cnt++;
        }
        
        inorderTraversal(root->right,cnt);
    }
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        int cnt=0;
        
        inorderTraversal(root,cnt);
        
        return cnt;
    }
};