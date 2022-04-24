/*
Title: Merge Sorted Linked Lists

Problem Type: Linked List

Description: Given two sorted linked lists, merge them into a single list.
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next = NULL;
};

void printList(struct Node *head) {
    if(head == NULL) {
        cout<<"Empty list"<<endl;
        return;
    }

    while(head->next != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
    return;
}

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(!newNode) {
        cout<<"Unable to create node"<<endl;
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

struct Node *mergeSortedListsRecursive(struct Node *list1, struct Node *list2) {
    struct Node *result = NULL;
    if(list1 == NULL) 
        return list2;
    if(list2 == NULL)
        return list1;
    
    if(list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedListsRecursive(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedListsRecursive(list1, list2->next);
    }
    return result;
}

struct Node *mergeSortedLists(struct Node *list1, struct Node *list2) {
    struct Node *result = NULL;
    if(list1 == NULL) 
        return list2;
    if(list2 == NULL)
        return list1;
        
    if(list1->data <= list2->data) {
        result = list1;
        list1 = list1->next;
    } else {
        result = list2;
        list2 = list2->next;
    }

    struct Node *temp = result;
    while((list1 != NULL) && (list2 != NULL)) {
        if(list1->data <= list2->data) {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        } else {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }

    if(list1 == NULL) {
        temp->next = list2;
    } else {
        temp->next = list1;
    }
    return result;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    for(int i = 1; i < 10; i=i+2) {
        insertNode(&list1, i);
    }
    for(int i = 20; i < 30; i=i+2) {
        insertNode(&list2, i);
    }
    printList(list1);
    printList(list2);

    struct Node *result = mergeSortedLists(list1, list2);
    printList(result);
    return 0;
}