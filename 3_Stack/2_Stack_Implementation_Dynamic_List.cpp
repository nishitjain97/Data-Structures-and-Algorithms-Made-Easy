/*
Title: Stack Implementation using Dynamic List

Problem Type: Stack

Description: Implementing a FILO stack using a dynamic list internally.
*/
#include<iostream>
#include<climits>
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

int main() {
    struct DynamicStack *S;
    S = createStack();
    push(S, 10);
    push(S, 20);
    push(S, 30);
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    return 0;
}