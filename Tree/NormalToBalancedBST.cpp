/*Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
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
    
    Node* inorderToBST(int s, int e,vector<int> &ans){
        if(s>e){
            return NULL;
        }
        int mid = s+(e-s)/2;
        
        Node* root = new Node(ans[mid]);
        root->left = inorderToBST(s,mid-1,ans);
        root->right = inorderToBST(mid+1,e,ans);
        
        return root;
    }
    
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> ans;
        inorder(root,ans);
        
        return inorderToBST(0,ans.size()-1,ans);
    }
};