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

void reverseList(struct Node **head) {
    if((*head) == NULL) {
        cout<<"Empty list. Cannot be reversed"<<endl;
        return;
    }

    if((*head)->next == NULL) {
        return;
    }

    struct Node *prev_node, *cur_node, *next_node;
    prev_node = NULL;
    cur_node = (*head);
    next_node = cur_node->next;
    while(next_node != NULL) {
        cur_node->next = prev_node;
        prev_node = cur_node;
        cur_node = next_node;
        next_node = cur_node->next;
    }
    cur_node->next = prev_node;
    *head = cur_node;
    return;
}

int main() {
    struct Node *head = NULL;
    
    for(int i = 0; i < 2; i++) {
        insertNode(&head, i);
    }
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}