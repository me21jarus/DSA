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

Node* minVal(Node* root){
    Node* temp = root;

    while(temp && temp->left){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;

    while(temp && temp->right){
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val){
    if(root == NULL) return root;

    if(root->data == val){

        // Case 1: 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // Case 2: 1 child (left)
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: 1 child (right)
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: 2 children
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
    }
    else{
        root->right = deleteFromBST(root->right,val);
    }

    return root;
}

int main(){

    Node* root = NULL;

    cout<<"Enter data to create BST (-1 to stop):"<<endl;
    takeInput(root);

    cout<<"\nLevel Order Traversal:\n";
    levelOrderTraversal(root);


    deleteFromBST(root,10);

    cout<<"Deleting "<<endl;
    cout<<"\nLOT (vector output):\n";
    vector<vector<int>> result = LOT(root);

    for(auto level : result){
        for(auto val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    Node* minNode = minVal(root);
    Node* maxNode = maxVal(root);

    if(minNode)
        cout << "\nMin: " << minNode->data;

    if(maxNode)
        cout << "\nMax: " << maxNode->data;

}