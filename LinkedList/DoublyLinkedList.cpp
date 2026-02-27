#include<iostream>
using namespace std;

class DoublyLinkedList{
    public:
        int data;
        DoublyLinkedList* prev;
        DoublyLinkedList* next;
    
    DoublyLinkedList(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(DoublyLinkedList* &head,DoublyLinkedList* &tail,int d){
    DoublyLinkedList* newNode = new DoublyLinkedList(d);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(DoublyLinkedList* &tail, DoublyLinkedList* &head,int d){
    DoublyLinkedList* newNode = new DoublyLinkedList(d);
    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtMiddle(int n,int d,DoublyLinkedList* &head,DoublyLinkedList* &tail){
    if(n == 1){
        insertAtHead(head,tail,d);
        return;
    }
    DoublyLinkedList* temp = head;
    int i=1;
    while(i<n-1){
        temp = temp->next;
        i++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,head,d);
        return;
    }
    DoublyLinkedList* newNode = new DoublyLinkedList(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int pos,DoublyLinkedList* &head,DoublyLinkedList* &tail){
    DoublyLinkedList* temp = head;
    if(head == NULL) return;
    if(pos == 1){
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete temp;
        return;
    }
    DoublyLinkedList* curr = head;
    int i = 1;
    while(i<pos && curr!=NULL){
        curr = curr->next;
        i++;
    }
    if(curr == NULL) return;

    if(curr->next == NULL){
        tail = curr->prev;
        tail->next = NULL;
        delete curr;
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

int len(DoublyLinkedList* &head){
    DoublyLinkedList* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void print(DoublyLinkedList* &head){
    DoublyLinkedList* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    DoublyLinkedList* node = new DoublyLinkedList(11);

    DoublyLinkedList* head = node;
    DoublyLinkedList* tail = node;

    print(head);
    insertAtHead(head,tail,10);
    print(head);
    insertAtTail(tail,head,13);
    print(head);
    insertAtMiddle(3,12,head,tail);
    print(head);
    cout<<len(head)<<endl;
    
    deleteNode(1,head,tail);
    print(head);
    deleteNode(2,head,tail);
    print(head);
    deleteNode(2,head,tail);
    print(head);
    return 0;
}