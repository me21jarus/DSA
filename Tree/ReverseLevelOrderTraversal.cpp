#include <bits/stdc++.h>
#include <queue>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting in left "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right "<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(Node* root){
    if(root == NULL) return;
    
    queue<Node*> q;
    stack<Node*> st;
    
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        st.push(temp);
        
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    while(!st.empty()){
        cout << st.top()->data << " ";
        st.pop();
    }
}

int main() {
	Node* root = NULL;
	root = buildTree(root);
	
	levelOrderTraversal(root);
	
	reverseLevelOrderTraversal(root);
	
    return 0;
}
