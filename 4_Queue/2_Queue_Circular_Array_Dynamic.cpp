/*
Title: Queue Implementation using Circular Array

Problem Type: Queue

Description: Implementing a FIFO Queue using fixed-size array
*/
#include<iostream>
using namespace std;

struct DynArrayQueue {
    int front, rear;
    int capacity;
    int *array;
};

struct DynArrayQueue *createDynQueue(int initial_capacity) {
    struct DynArrayQueue *Q = (struct DynArrayQueue *)malloc(sizeof(struct DynArrayQueue));
    if(!Q) {
        return NULL;
    }

    Q->capacity = initial_capacity;
    Q->front = Q->rear = -1;
    Q->array = (int *)malloc(Q->capacity * sizeof(int));

    if(!Q->array) {
        return NULL;
    }

    return Q;
}

int isEmptyQueue(struct DynArrayQueue *Q) {
    return(Q->front == -1);
}

int isFullQueue(struct DynArrayQueue *Q) {
    return((Q->rear + 1) % Q->capacity == Q->front);
}

int queueSize(struct DynArrayQueue *Q) {
    return(Q->capacity - Q->front + Q->rear) % Q->capacity;
}

void resizeQueue(struct DynArrayQueue *Q) {
    int size = Q->capacity;
    Q->capacity = Q->capacity * 2;
    Q->array = (int *)realloc(Q->array, Q->capacity);

    if(!Q->array) {
        cout<<"Memory error";
        return;
    }
    if(Q->front > Q->rear) {
        for(int i = 0; i < Q->front; i++) {
            Q->array[i+size] = Q->array[i];
        }
        Q->rear = Q->rear + size;
    }
}

void enQueue(struct DynArrayQueue *Q, int data) {
    if(isFullQueue(Q)) {
        resizeQueue(Q);
    }

    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;

    if(Q->front == -1) {
        Q->front = Q->rear;
    }
}

int deQueue(struct DynArrayQueue *Q) {
    int data = INT_MIN;
    if(isEmptyQueue(Q)) {
        cout<<"Queue is empty."<<endl;
        return INT_MIN;
    }
    data = Q->array[Q->front];
    if(Q->front == Q->rear) {
        Q->front = Q->rear = -1;
    } else {
        Q->front = (Q->front + 1) % Q->capacity;
    }
    return data;
}

void deleteQueue(struct DynArrayQueue *Q) {
    if(Q) {
        if(Q->array) {
            free(Q->array);
        }
        free(Q);
    }
}

int main() {
    struct DynArrayQueue *Q = createDynQueue(2);
    enQueue(Q, 10);
    cout<<"Queue size "<<queueSize(Q)<<endl;
    enQueue(Q, 20);
    cout<<"Queue size "<<queueSize(Q)<<endl;
    enQueue(Q, 30);
    cout<<"Queue size "<<queueSize(Q)<<endl;
    cout<<deQueue(Q)<<endl;
    cout<<deQueue(Q)<<endl;
    cout<<deQueue(Q)<<endl;
    cout<<"Queue size "<<queueSize(Q)<<endl;
    cout<<deQueue(Q)<<endl;
    return 0;
}