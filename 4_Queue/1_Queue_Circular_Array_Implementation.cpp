/*
Title: Queue Implementation using Circular Array

Problem Type: Queue

Description: Implementing a FIFO Queue using fixed-size array
*/
#include<iostream>
using namespace std;

struct ArrayQueue {
    int front, rear;
    int capacity;
    int *array;
};

struct ArrayQueue *Queue(int size) {
    struct ArrayQueue *Q = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
    if(!Q) {
        return NULL;
    }

    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = (int *)malloc(Q->capacity * sizeof(int));

    if(!Q->array) {
        return NULL;
    }
    return Q;
}

int isEmptyQueue(struct ArrayQueue *Q) {
    return Q->front == -1;
}

int isFullQueue(struct ArrayQueue *Q) {
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

int queueSize(struct ArrayQueue *Q) {
    return (Q->capacity - Q->front + Q->rear) % Q->capacity;
}

void enQueue(struct ArrayQueue *Q, int data) {
    if(isFullQueue(Q)) {
        cout<<"Queue full"<<endl;
        return;
    }
    
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front == -1) {
        Q->front = Q->rear;
    }
}

int deQueue(struct ArrayQueue *Q) {
    int data = INT_MIN;

    if(isEmptyQueue(Q)) {
        cout<<"Queue is empty"<<endl;
    } else {
        data = Q->array[Q->front];
        if(Q->front == Q->rear) {
            Q->front = Q->rear = -1;
        } else {
            Q->front = (Q->front + 1) % Q->capacity;
        }
    }
    return data;
}

void deleteQueue(struct ArrayQueue *Q) {
    if(Q) {
        if(Q->array) {
            free(Q->array);
        }
        free(Q);
    }
}

int main() {
    struct ArrayQueue *Q;
    Q = Queue(10);

    cout<<queueSize(Q)<<endl;

    enQueue(Q, 10);
    enQueue(Q, 20);
    cout<<deQueue(Q)<<endl;
    cout<<deQueue(Q)<<endl;
    return 0;
}