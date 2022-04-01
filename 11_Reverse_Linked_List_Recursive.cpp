#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *head) {
    while(head->next != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
    return;
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        cout<<"Unable to create node."<<endl;
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if(newNode == NULL) {
        return;
    }

    if((*head) == NULL) {
        (*head) = newNode;
    } else {
        struct Node *iterator = *head;
        while(iterator->next != NULL) {
            iterator = iterator->next;
        }
        iterator->next = newNode;
    }
    return;
}

struct Node* reverseList(struct Node* head) {
    if(head == NULL) {
        return NULL;
    }
    if(head->next == NULL) {
        return head;
    }
    
    struct Node *next_node = head->next;
    head->next = NULL;
    struct Node *reverse_rest = reverseList(next_node);
    next_node->next = head;
    return reverse_rest;
}

int main() {
    struct Node *head = NULL;
    
    for(int i = 0; i < 10; i++) {
        insertNode(&head, i);
    }
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0;
}