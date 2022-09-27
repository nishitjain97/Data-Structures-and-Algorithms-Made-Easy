#include<iostream>
using namespace std;

class Queue {
    int* arr;
    int rear, capacity;

    public:
        Queue(int size=10);
        ~Queue();
        
        void add(int);
        int remove();
        int peek();

        bool isEmpty();
        bool isFull();
        int size();
};

Queue::Queue(int size) {
    arr = new int[size];
    rear = 0;
    capacity = size;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::add(int ele) {
    if(isFull()) {
        cout<<"Queue is full!";
        exit(EXIT_FAILURE);
    }
    arr[rear++] = ele;
}

int Queue::remove() {
    if(isEmpty()) {
        cout<<"Queue is empty!";
        exit(EXIT_FAILURE);
    }

    int ele = arr[0];

    for(int i = 0; i < rear-1; i++) {
        arr[i] = arr[i+1];
    }
    rear--;
    return ele;
}

int Queue::peek() {
    if(isEmpty()) {
        cout<<"Queue is empty!";
        exit(EXIT_FAILURE);
    }
    return arr[0];
}

bool Queue::isEmpty() {
    if(rear == 0) {
        return true;
    }
    return false;
}

bool Queue::isFull() {
    if(rear == capacity) {
        return true;
    }
    return false;
}

int Queue::size() {
    return rear;
}

int main() {
    Queue queue(5);
    queue.add(10);
    cout<<"Top of the queue: "<<queue.peek()<<endl;
    cout<<"Size of the queue: "<<queue.size()<<endl;
    queue.add(20);
    cout<<"Top of the queue: "<<queue.peek()<<endl;
    cout<<"Size of the queue: "<<queue.size()<<endl;
    queue.add(30);
    cout<<"Top of the queue: "<<queue.peek()<<endl;
    cout<<"Size of the queue: "<<queue.size()<<endl;

    int ele = queue.remove();
    cout<<"Element removed: "<<ele<<endl;
    cout<<"Top of the queue: "<<queue.peek()<<endl;
    cout<<"Size of the queue: "<<queue.size()<<endl;

    ele = queue.remove();
    cout<<"Element removed: "<<ele<<endl;
    cout<<"Top of the queue: "<<queue.peek()<<endl;
    cout<<"Size of the queue: "<<queue.size()<<endl;

    ele = queue.remove();
    cout<<"Element removed: "<<ele<<endl;
    cout<<"Top of the queue: "<<queue.peek()<<endl;
    cout<<"Size of the queue: "<<queue.size()<<endl;

    ele = queue.remove();
    cout<<"Element removed: "<<ele<<endl;
    cout<<"Top of the queue: "<<queue.peek()<<endl;
    cout<<"Size of the queue: "<<queue.size()<<endl;

    return 0;
}