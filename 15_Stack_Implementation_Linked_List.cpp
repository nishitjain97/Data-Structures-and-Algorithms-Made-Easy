/*
Title: Stack Implementation using Linked List

Problem Type: Stack

Description: Implementing a FILO stack using a linked list internally.
*/
#include<iostream>
using namespace std;

struct Stack {
    int data;
    struct Stack *next;
};

struct Stack *createStack() {
    return NULL;
}

void push(struct Stack **top, int data) {
    struct Stack *temp;
    temp = (struct Stack *)malloc(sizeof(struct Stack));
    if(!temp) {
        return;
    }

    temp->data = data;
    temp->next = *top;
    *top = temp;
}

int isEmptyStack(struct Stack *top) {
    return top == NULL;
}

int Pop(struct Stack **top) {
    int data;
    struct Stack *temp;
    if(isEmptyStack(*top)) {
        return INT_MIN;
    }

    temp = *top;
    *top = (*top)->next;
    data = temp->data;
    free(temp);
    return data;
}

int top(struct Stack *top) {
    if(isEmptyStack(top)) {
        return INT_MIN;
    }
    return top->data;
}

void deleteStack(struct Stack **top) {
    struct Stack *temp, *p;
    p = *top;

    while(p->next) {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
    free(p);
}

int main() {
    return 0;
}