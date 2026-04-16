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
        root->right = vectorToBST(mid+1,e,inorder);
        
        return root;
    }
    
    void convertIntoSortedDLL(Node* root, Node* &head){
        if(root==NULL) return;
        
        convertIntoSortedDLL(root->right, head);
        
        root->right = head;
        if(head!=NULL){
            head->left = root;
        }
        head = root;
        
        convertIntoSortedDLL(root->left, head);
    }
    
    Node* merge2SortedLL(Node* head1, Node* head2){
        Node* head = NULL;
        Node* tail = NULL;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data < head2->data){
                if(head == NULL){
                    head = head1;
                    tail = head1;
                    head1 = head1->right;
                    head->left = NULL;
                }
                else{
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right;
                }
            }
            else{
                if(head == NULL){
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                    head->left = NULL;
                }
                else{
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            }
        }
        
        while(head1!=NULL){
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
        while(head2!=NULL){
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
        return head;
    }
    
    int count(Node* root){
        int i = 0;
        Node*temp = root;
        while(temp){
            i++;
            temp = temp->right;
        }
        return i;
    }
    
    Node* sortedLLtoBST(Node* &head,int n){
        if(head==NULL || n<=0){
            return NULL;
        }
        Node* left = sortedLLtoBST(head, n/2);
        Node* root = head;
        root->left = left;
        
        head = head->right;
        
        root->right = sortedLLtoBST(head, n-n/2-1);
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
        
        
        Node* head1 = NULL;
        Node* head2 = NULL;
        convertIntoSortedDLL(root1,head1);
        convertIntoSortedDLL(root2, head2);
        if(head1) head1->left = NULL;
        if(head2) head2->left = NULL;
        
        
        Node* head = merge2SortedLL(head1,head2);
        int n = count(head);
        return merge2Arrays(inorder1,inorder2);
        // return sortedLLtoBST(head, n);
    }
};