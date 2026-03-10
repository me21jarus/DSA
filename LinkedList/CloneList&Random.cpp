/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    void insertAtTail(Node* &head,Node* &tail,int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* cloneLinkedList(Node* head) {
        // code here
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        unordered_map<Node*,Node*> oldToNew;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode && cloneNode){
            oldToNew[originalNode] = cloneNode;
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode){
            cloneNode->random = oldToNew[originalNode->random];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        return cloneHead;
    }
};