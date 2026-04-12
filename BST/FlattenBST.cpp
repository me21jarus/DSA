/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root,vector<int> &ans){
        if(root==NULL) return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    Node *flattenBST(Node *root) {
        // code here
        vector<int> ans;
        inorder(root,ans);
        
        int n = ans.size();
        
        Node* newRoot = new Node(ans[0]);
        
        Node* curr = newRoot;
        
        for(int i=1;i<n;i++){
            Node* temp = new Node(ans[i]);
            
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }
        
        curr->left = NULL;
        curr->right = NULL;
        
        return newRoot;
    }
};