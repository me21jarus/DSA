/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void insertAtTail(Node* &tail,Node* curr){
        tail->next = curr;
        tail = curr;
    }
    Node* segregate(Node* head) {
        // code here
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* temp = head;
        
        while(temp){
            if(temp->data == 0){
                insertAtTail(zeroTail,temp);
            }
            else if(temp->data == 1){
                insertAtTail(oneTail,temp);
            }
            else{
                insertAtTail(twoTail,temp);
            }
            temp = temp->next;
        }
        if(oneHead->next != NULL){
            zeroTail->next = oneHead->next;
        }
        else{
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        head = zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};