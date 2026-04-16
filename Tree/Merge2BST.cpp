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
    void inorder(Node* root,vector<int> &ans){
        if(root == NULL) return ;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    Node* vectorToBST(int s, int e, vector<int> inorder){
        if(s>e) return NULL;
        
        int mid = s+(e-s)/2;
        
        Node* root=new Node(inorder[mid]);
        root->left = vectorToBST(s,mid-1,inorder);
        root->left = vectorToBST(mid+1,e,inorder);
        
        return root;
    }
    
    vector<int> merge2Arrays(vector<int> &inorder1, vector<int> &inorder2){
        vector<int> ans(inorder1.size()+inorder2.size());
        
        int i = 0,j = 0;
        int k=0;
        while(i<inorder1.size() && j<inorder2.size()){
            if(inorder1[i] < inorder2[j]){
                ans[k++] = inorder1[i++];
            }
            else{
                ans[k++] = inorder2[j++];
            }
        }
        while(i<inorder1.size()){
            ans[k++] = inorder1[i++];
        }
        while(j<inorder2.size()){
            ans[k++] = inorder2[j++];
        }
        return ans;
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int> inorder1;
        vector<int> inorder2;
        
        inorder(root1, inorder1);
        inorder(root2, inorder2);
        
        return merge2Arrays(inorder1,inorder2);
    }
};