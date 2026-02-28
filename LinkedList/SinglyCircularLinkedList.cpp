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

    ~LinkedListNode(){
        cout<<"Memory is free with the data "<<data<<endl;
    }
};

void insertNode(LinkedListNode* &tail,int ele,int d){
    if(tail == NULL){
        LinkedListNode* newNode = new LinkedListNode(d);
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    LinkedListNode* curr = tail;
    do{
        if(curr->data == ele){
            LinkedListNode* temp = new LinkedListNode(d);
            temp->next = curr->next;
            curr->next = temp;
            return;
        }
        curr = curr->next;
    } while(curr != tail);    
}

void deleteNode(LinkedListNode* &tail,int ele){
    if(tail == NULL){
        return;
    }
    LinkedListNode* prev = tail;
    LinkedListNode* curr = prev->next;

    if(curr == tail && curr->data == ele){
        delete curr;
        tail = NULL;
        return;
    }
    while(curr->data != ele){
        prev = curr;
        curr = curr->next;

        // safety check (element not found)
        if(curr == tail->next)
            return;
    }
    prev->next = curr->next;
    if(tail == curr){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}

void print(LinkedListNode* tail){
    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }

    LinkedListNode* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

int main(){

    LinkedListNode* tail = NULL;

    insertNode(tail,5,1);
    print(tail);
    insertNode(tail,1,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,1,2);
    print(tail);
    insertNode(tail,3,4);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,2);
    print(tail);
    deleteNode(tail,1);
    print(tail);
    deleteNode(tail,4);
    print(tail);
    deleteNode(tail,5);
    print(tail);


    return 0;
}