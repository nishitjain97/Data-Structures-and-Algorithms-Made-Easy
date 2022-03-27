/*
Title: Linked List

Problem Type: Linked List

Description: Implementing a linked list in C++.
*/
#include<iostream>
using namespace std;

struct ListNode {
    // Linked List structure with data and next pointer.
    int data;
    struct ListNode *next;
};

int ListLength(struct ListNode *head) {
    // Function to traverse linked list and find its length
    struct ListNode *current = head;
    int count = 0;

    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

struct ListNode* createNode(int data) {
    struct ListNode *newNode;
    newNode = (ListNode *)malloc(sizeof(struct ListNode));

    if(!newNode) {
        printf("Memory Error!");
        return NULL;
    }

    newNode->data = data;

    return newNode;
}

void InsertInLinkedList(struct ListNode **head, int data, int position) {
    // Traverse list to a position and insert node
    int k = 1;
    struct ListNode *p, *q, *newNode;

    newNode = createNode(data);

    p = *head;

    // Inserting at beginning
    if(position == 1) {
        newNode->next = p;
        *head = newNode;
    } else {
        // Traverse the list
        while((p != NULL) && (k < position)) {
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }
}

void DeleteNodeFromLinkedList(struct ListNode **head, int position) {
    int k = 1;
    struct ListNode *p, *q;
    if(*head == NULL) {
        printf("List Empty");
        return;
    }

    p = *head;

    /* from beginning */
    if(position == 1) {
        *head = (*head)->next;
        free(p);
        return;
    } else {
        // Traverse list until position
        while((p != NULL) && (k < position)) {
            k++;
            q = p;
            p = p->next;
        }
        if(p == NULL) {
            printf("Position does not exist");
        } else {
            q->next = p->next;
            free(p);
        }
    }
}

void DeleteLinkedList(struct ListNode **head) {
    struct ListNode *auxilaryNode, *iterator;
    iterator = *head;
    while(iterator) {
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *head = NULL;
}

void printList(struct ListNode *head) {
    struct ListNode *iterator = head;
    while(iterator->next != NULL) {
        cout<<iterator->data<<"->";
        iterator = iterator->next;
    }
    cout<<iterator->data<<endl;
    return;
}

int main() {
    ListNode *head = NULL;
    
    for(int i = 0; i < 10; i++) {
        InsertInLinkedList(&head, i, i+1);
    }
    
    printList(head);
    return 0;
}