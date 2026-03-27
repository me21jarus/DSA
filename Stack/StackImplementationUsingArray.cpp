class myStack {
  public:
    int *arr;
    int n;
    int top;
    myStack(int n) {
        // Define Data Structures
        this->n = n;
        arr = new int[n];
        top = -1;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == -1;
    }

    bool isFull() {
        // check if the stack is full
        return top == n - 1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if (isFull()) {
            // cout << "Stack is FULL, Can't add new element\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if (isEmpty()) {
            // cout << "Cannot remove element. Stack is empty\n";
            return;
        }
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if (isEmpty()) {
            // cout << "Empty Stack\n";
            return -1;
        }
        return arr[top];
    }
};