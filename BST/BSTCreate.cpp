#include<iostream>
#include<queue>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<< " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}

vector<vector<int>> LOT(Node* root){
    vector<vector<int>> ans;

    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> temp;

        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();

            temp.push_back(front->data);

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        return new Node(data); 
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>> data;

    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

int main(){

    Node* root = NULL;

    cout<<"Enter data to create BST (-1 to stop):"<<endl;
    takeInput(root);

    cout<<"\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout<<"\nLOT (vector output):\n";
    vector<vector<int>> result = LOT(root);

    for(auto level : result){
        for(auto val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }

}