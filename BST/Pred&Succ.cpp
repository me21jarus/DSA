/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* temp = root;
        Node* pred = NULL;
        Node* succ= NULL;
        
        while(temp!=NULL){
            if(temp->data > key){
                succ = temp;
                temp = temp->left;
            }
            else if(temp->data < key){
                pred = temp;
                temp = temp->right;
            }
            else {
                break;
            }
        }
        
        if(temp!=NULL){
            Node* leftTree = temp->left;
            while(leftTree!=NULL){
                pred = leftTree;
                leftTree = leftTree->right;
            }
            Node* rightTree = temp->right;
            while(rightTree!=NULL){
                succ = rightTree;
                rightTree = rightTree->left;
            }
        }
        return {pred, succ};
    }
};