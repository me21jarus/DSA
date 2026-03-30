/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

  public:
    Node* top = NULL;
    int count = 0;
    myStack() {
        // Initialize your data members
        top = NULL;
        count = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == NULL;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        count++;
    }

    void pop() {
        // Removes the top element of the stack
        if(top == NULL)return;
        top = top->next;
        count--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(top == NULL){
            return -1;
        }
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return count;
    }
};