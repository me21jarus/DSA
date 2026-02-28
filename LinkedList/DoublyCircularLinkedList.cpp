#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }

    ~Node() {
        cout << "Memory free for node with data " << data << endl;
    }
};

// Insert after a given element
void insertNode(Node* &tail, int element, int d) {

    // Empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    Node* curr = tail;

    do {
        if (curr->data == element) {
            Node* temp = new Node(d);

            temp->next = curr->next;
            curr->next->prev = temp;
            curr->next = temp;
            temp->prev = curr;

            // if inserting after tail, move tail
            if (curr == tail) {
                tail = temp;
            }

            return;
        }
        curr = curr->next;
    } while (curr != tail);

    cout << "Element not found!" << endl;
}


// Delete a node by value
void deleteNode(Node* &tail, int value) {

    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = tail;
    Node* prevNode = NULL;

    do {
        if (curr->data == value) {

            // Single node case
            if (curr->next == curr) {
                delete curr;
                tail = NULL;
                return;
            }

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            if (curr == tail) {
                tail = curr->prev;
            }

            curr->next = NULL;
            curr->prev = NULL;

            delete curr;
            return;
        }
        curr = curr->next;
    } while (curr != tail);

    cout << "Value not found!" << endl;
}


// Print list
void print(Node* tail) {

    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = tail;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}


int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 1);
    print(tail);

    insertNode(tail, 1, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 1, 2);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    deleteNode(tail, 2);
    print(tail);

    deleteNode(tail, 1);
    print(tail);

    deleteNode(tail, 4);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    return 0;
}
