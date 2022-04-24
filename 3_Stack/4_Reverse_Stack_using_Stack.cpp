/*
Title: Reverse Stack using Stack

Problem Type: Stack

Description: Reversing the values in the stack using another stack and recursion.
*/
#include<iostream>
using namespace std;

struct DynamicStack {
    int top;
    int capacity;
    int *array;
};

struct DynamicStack *createStack() {
    struct DynamicStack *S = (struct DynamicStack *)malloc(sizeof(struct DynamicStack));
    if(!S) {
        return NULL;
    }
    S->capacity = 1;
    S->top = -1;
    S->array = (int *)malloc(S->capacity * sizeof(int));
    if(!S->array) {
        return NULL;
    }
    return S;
}

int isFullStack(struct DynamicStack *S) {
    return S->top == S->capacity - 1;
}

void extendStack(struct DynamicStack *S) {
    S->capacity *= 2;
    S->array = (int *)realloc(S->array, S->capacity * sizeof(int));
}

void push(struct DynamicStack *S, int data) {
    if(isFullStack(S)) {
        extendStack(S);
    }
    S->array[++S->top] = data;
}

int isEmptyStack(struct DynamicStack *S) {
    return S->top == -1;
}

int top(struct DynamicStack *S) {
    if(isEmptyStack(S)) {
        return INT_MIN;
    }
    return S->array[S->top];
}

int pop(struct DynamicStack *S) {
    if(isEmptyStack(S)) {
        return INT_MIN;
    }
    return S->array[S->top--];
}

void deleteStack(struct DynamicStack *S) {
    if(S) {
        if(S->array) {
            free(S->array);
        }
        free(S);
    }
}

void insertAtBottom(struct DynamicStack *S, int data) {
    int temp;
    if(isEmptyStack(S)) {
        push(S, data);
        return;
    }
    temp = pop(S);
    insertAtBottom(S, data);
    push(S, temp);
}

void reverseStack(struct DynamicStack *S) {
    int data;
    if(isEmptyStack(S)) {
        return;
    }
    data = pop(S);
    reverseStack(S);
    insertAtBottom(S, data);
}

int main() {
    struct DynamicStack *S;
    S = createStack();
    push(S, 10);
    push(S, 20);
    push(S, 30);
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl<<endl;

    push(S, 10);
    push(S, 20);
    push(S, 30);

    reverseStack(S);
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    return 0;
}