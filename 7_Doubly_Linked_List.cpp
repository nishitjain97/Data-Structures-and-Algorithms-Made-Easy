/*
Title: Doubly Linked List

Problem Type: Linked List

Description: C++ implementation of doubly linked list
*/
#include<iostream>
using namespace std;

struct DLLNode {
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};

struct DLLNode *createNode(int data) {
    struct DLLNode *newNode;

    newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    if(!newNode) {
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertNode(struct DLLNode **head, int data, int position) {
    int k = 1;
    struct DLLNode *newNode = createNode(data);

    if(newNode == NULL) {
        return;
    }

    if(*head == NULL) {
        if(position != 1) {
            cout<<"Illegal Position"<<endl;
            return;
        }
        (*head) = newNode;
        return;
    }

    if(position == 1) {
        cout<<"Position Found"<<endl;
        (*head)->prev = newNode;
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }
    
    struct DLLNode *iterator = *head;

    while(iterator->next != NULL) {
        if(k == position-1) {
            break;
        }
        iterator = iterator->next;
        k++;
    }

    if((k == position-1) && (iterator->next == NULL)) {
        iterator->next = newNode;
        newNode->prev = iterator;
        return;
    } else if(k == position-1) {
        iterator->next->prev = newNode;
        newNode->next = iterator->next;
        newNode->prev = iterator;
        iterator->next = newNode;
        return;
    } else {
        cout<<"Illegal position"<<endl;
        return;
    }
}

void deleteNode(struct DLLNode **head, int position) {
    struct DLLNode *temp, *temp2;
    temp = *head;
    int k = 1;

    if((*head) == NULL) {
        cout<<"Illegal Delete"<<endl;
        return;
    }

    if(position == 1) {
        (*head) = (*head)->next;

        if(*head != NULL) 
            (*head)->prev = NULL;
        
        free(temp);
        return;
    }

    while((k < position) && (temp->next != NULL)) {
        temp = temp->next;
        k++;
    }

    if(k != position) {
        cout<<"Illegal Delete"<<endl;
        return;
    }
    
    temp2 = temp->prev;
    temp2->next = temp->next;

    if(temp->next) {
        temp->next->prev = temp2;
    }
    free(temp);
    return;
}

void printNodes(struct DLLNode *head) {
    struct DLLNode *current;
    current = head;

    if(!current) {
        return;
    }

    while(current->next != NULL) {
        cout<<current->data<<"->";
        current = current->next;
    }
    cout<<current->data<<endl;
    current = current->next;
    return;
}

int main() {
    struct DLLNode *head = NULL, *current = NULL, *newNode = NULL;
    
    deleteNode(&head, 1);

    for(int i = 1; i <= 5; i++) {
        insertNode(&head, i * 10, i);
    }
    printNodes(head);

    deleteNode(&head, 1);
    printNodes(head);
    deleteNode(&head, 10);
    printNodes(head);
    deleteNode(&head, 3);
    printNodes(head);

    return 0;
}