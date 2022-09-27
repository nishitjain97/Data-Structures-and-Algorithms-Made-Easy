#include<iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;

    public:
        Stack(int size = 10);
        ~Stack();

        void push(int);
        int pop();
        int peek();

        int size();
        bool isEmpty();
        bool isFull();
};

Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top=-1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int ele) {
    if(isFull()) {
        cout<<"Stack is full!";
        exit(EXIT_FAILURE);
    }
    arr[++top] = ele;
}

int Stack::pop() {
    if(isEmpty()) {
        cout<<"Stack is empty!";
        exit(EXIT_FAILURE);
    }
    return arr[top--];
}

int Stack::peek() {
    if(isEmpty()) {
        cout<<"Stack is empty!";
        exit(EXIT_FAILURE);
    }
    return arr[top];
}

int Stack::size() {
    return top + 1;
}

bool Stack::isEmpty() {
    if(top == -1) {
        return true;
    }
    return false;
}

bool Stack::isFull() {
    if(top == capacity - 1) {
        return true;
    }
    return false;
}

int main() {
    Stack st(3);
    st.push(1);
    cout<<"Top element is "<<st.peek()<<endl;
    cout<<"Stack size is "<<st.size()<<endl;
    st.push(2);
    cout<<"Top element is "<<st.peek()<<endl;
    cout<<"Stack size is "<<st.size()<<endl;
    st.push(3);
    cout<<"Top element is "<<st.peek()<<endl;
    cout<<"Stack size is "<<st.size()<<endl;

    return 0;
}