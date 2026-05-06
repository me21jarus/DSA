/*
class Node {
   public:
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
    int countNode(Node* tree){
        if(tree == NULL) return 0;
        
        int count = 1+countNode(tree->left)+countNode(tree->right);
        return count;
    }
    bool isCBT(Node* tree, int i,int n){
        if(tree==NULL) return true;
        
        if(i >= n) return false;
        
        bool left = isCBT(tree->left,2*i+1,n);
        bool right = isCBT(tree->right,2*i+2,n);
        
        return left && right;
    }
    
    bool isInHeap(Node* root){
        if(root->left == NULL && root->right == NULL) return true;
        
        if(root->right == NULL){
            return root->data > root->left->data;
        }
        
        bool left = isInHeap(root->left);
        bool right = isInHeap(root->right);
        
        
        return left && right && (root->data > root->left->data) && (root->data > root->right->data);
    }
    bool isHeap(Node* tree) {
        // code here
        int i=0;
        int n = countNode(tree);
        return isCBT(tree,i,n) && isInHeap(tree);
    }
};