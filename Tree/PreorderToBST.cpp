// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* solve(int pre[], int size, int mini,int maxi,int &i){
        if(i>= size){
            return NULL;
        }
        if(pre[i] < mini || pre[i] > maxi) return NULL;
        
        Node* root = newNode(pre[i]);
        i++;
        root->left = solve(pre, size,mini, root->data, i);
        root->right = solve(pre, size, root->data, maxi ,i);
        
        return root;
    }
    Node* Bst(int pre[], int size) {
        int i = 0;
        
        return solve(pre, size, INT_MIN, INT_MAX, i);
    }
};