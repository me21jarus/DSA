class myQueue {
  public:
    int *arr;
    int front;
    int rear;
    int size;
    int count;
    
    myQueue(int n) {
        // Define Data Structures
        size = n;
        arr = new int[n];
        front = 0;
        rear = 0;
        count=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return count == 0;
    }

    bool isFull() {
        // check if the queue is full
        return count == size;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()){
            return;
        }
        arr[rear] = x;
        rear = (rear+1)%size;
        count++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()){
            return;
        }
        arr[front] = -1;
        front = (front + 1) % size;
        count--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()) return -1;
        return arr[(rear-1+size)%size];
    }
};