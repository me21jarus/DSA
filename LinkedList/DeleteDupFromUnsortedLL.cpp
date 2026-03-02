/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        // Node* curr = head;
        
    //     while(curr != NULL) {
    //         Node* prev = curr;
    //         Node* temp = curr->next;

    //         while(temp != NULL) {
    //             if(curr->data == temp->data) {
    //                 prev->next = temp->next;
    //                 delete temp;
    //                 temp = prev->next;
    //             }
    //             else {
    //                 prev = temp;
    //                 temp = temp->next;
    //             }
    //         }
    //         curr = curr->next;
    //     }
    // return head;
    
        if(head == NULL){
            return head;
        }
        
        unordered_set<int> seen;
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr){
            if(seen.find(curr->data)!=seen.end()){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                seen.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};