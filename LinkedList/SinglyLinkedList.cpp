#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class LinkedListNode{
    public:
        int data;
        LinkedListNode* next;

    LinkedListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(LinkedListNode* &head,int d){
    LinkedListNode* temp = new LinkedListNode(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(LinkedListNode* &tail,int d){
    LinkedListNode* temp = new LinkedListNode(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtMiddle(LinkedListNode* &tail,LinkedListNode* &head,int d,int n){
    if(n==1){
        insertAtHead(head,d);
        return;
    }

    LinkedListNode* temp = head;
    int i=1;
    while(i<n-1){
        temp = temp->next;
        i++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }
    LinkedListNode* newNode = new LinkedListNode(d);
    newNode->data = d;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int n,LinkedListNode* &head,LinkedListNode* &tail){
    if(n == 1){
        LinkedListNode* temp = head;
        head = head->next;

        if(head == NULL)
            tail = NULL;

        delete temp;
        return;
    }
    LinkedListNode* curr = head;
    LinkedListNode* prev = NULL;
    int i = 1;
    while(i<n){
        prev = curr;
        curr = curr->next;
        i++;
    }
    prev->next = curr->next;
    if(curr->next == NULL)
        tail = prev;

    delete curr;
}

void print(LinkedListNode* &head){
    LinkedListNode* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int len(LinkedListNode* &head){
    int cnt = 0;
    LinkedListNode* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}


int main(){

    LinkedListNode* node = new LinkedListNode(10);
    // cout<<node->data<<endl;
    // cout<<node->next<<endl;

    LinkedListNode* head = node;
    LinkedListNode* tail = node;

    // print(head);
    // cout<<"---------------"<<endl;
    // insertAtHead(head,12);
    // insertAtHead(head,15);
    // print(head);
    insertAtTail(tail,20);
    insertAtTail(tail,30);
    // print(head);
    cout<<"---------------"<<endl;
    insertAtMiddle(tail,head,15,2);
    insertAtMiddle(tail,head,25,4);
    insertAtMiddle(tail,head,35,6);
    print(head);
    
    cout<<"---------------"<<endl;
    // cout<<len(head)<<endl;
    deleteNode(1,head,tail);
    print(head);
    cout<<"---------------"<<endl;
    deleteNode(3,head,tail);
    print(head);
    // cout<<head->data<<endl;
    // cout<<tail->data<<endl;
    return 0;
}