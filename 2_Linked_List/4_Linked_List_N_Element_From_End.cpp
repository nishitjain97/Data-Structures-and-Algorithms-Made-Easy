#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node *head) {
    if(head == NULL) {
        cout<<"Empty list"<<endl;
        return;
    }

    struct Node *iterator;
    iterator = head;
    while(iterator->next != NULL) {
        cout<<iterator->data<<"->";
        iterator = iterator->next;
    }
    cout<<iterator->data<<endl;
    return;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        cout<<"Unable to create node"<<endl;
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getNthFromStart(struct Node *head, int position) {
    int i = 1;
    while((i < position) && (head != NULL)) {
        head = head->next;
        i++;
    }
    if(head == NULL) {
        cout<<"List too short"<<endl;
        return -1;
    }
    return head->data;
}

int getNthFromLast(struct Node *head, int position) {
    int i = 1;
    struct Node *iterator = head;
    while((i <= position) && (head != NULL)) {
        head = head->next;
        i++;
    }
    if(i != position+1) {
        cout<<"List too short"<<endl;
        return -1;
    }

    while(head != NULL) {
        head = head->next;
        iterator = iterator->next;
    }
    return iterator->data;
}

int main() {
    struct Node *head, *iterator;
    head = createNode(10);
    iterator = head;
    iterator->next = createNode(20);
    iterator = iterator->next;
    iterator->next = createNode(30);
    iterator = iterator->next;
    iterator->next = createNode(40);
    iterator = iterator->next;

    // cout<<getNthFromStart(head, 1)<<' '<<head->data<<endl;
    // cout<<getNthFromStart(head, 2)<<' '<<head->data<<endl;
    // cout<<getNthFromStart(head, 3)<<' '<<head->data<<endl;
    // cout<<getNthFromStart(head, 4)<<' '<<head->data<<endl;
    // cout<<getNthFromStart(head, 5)<<' '<<head->data<<endl;
    // cout<<getNthFromStart(head, 6)<<' '<<head->data<<endl;
    


    cout<<getNthFromLast(head, 1)<<' '<<head->data<<endl;
    cout<<getNthFromLast(head, 2)<<' '<<head->data<<endl;
    cout<<getNthFromLast(head, 3)<<' '<<head->data<<endl;
    cout<<getNthFromLast(head, 4)<<' '<<head->data<<endl;
    cout<<getNthFromLast(head, 5)<<' '<<head->data<<endl;
    cout<<getNthFromLast(head, 6)<<' '<<head->data<<endl;
    return 0;
}