/*
Title: Stack Implementation using Static List

Problem Type: Stack

Description: Implementing a FIFO stack using a static list internally.
*/
#include<iostream>
using namespace std;

struct Stack {
    int capacity;
    int top;
    int *array;
};

struct Stack *createStack(int N) {
    struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
    if(!S) return NULL;

    S->capacity = N;
    S->top = -1;
    S->array = (int *)malloc(S->capacity * sizeof(int));
    if(!S->array) return NULL;

    return S;
}

int isEmptyStack(struct Stack *S) {
    return (S->top == -1);
}

int isFullStack(struct Stack *S) {
    return (S->top == S->capacity-1);
}

void push(struct Stack *S, int data) {
    if(isFullStack(S)) {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    S->array[++S->top] = data;
}

int pop(struct Stack *S) {
    if(isEmptyStack(S)) {
        cout<<"Stack Underflow"<<endl;
        return INT_MIN;
    }
    return (S->array[S->top--]);
}

void DeleteStack(struct Stack *S) {
    if(S) {
        if(S->array){
            free(S->array);
        }
        free(S);
    }
}

int main() {
    struct Stack *S;
    S = createStack(3);
    push(S, 10);
    push(S, 20);
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    push(S, 30);
    push(S, 40);
    push(S, 50);
    push(S, 60);
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    cout<<pop(S)<<endl;
    return 0;
}